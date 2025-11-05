using System.Runtime.InteropServices;
using System.Globalization;

public enum Location
{
    NewYork,
    London,
    Paris
}

public enum AlertLevel
{
    Early,
    Standard,
    Late
}

public static class Appointment
{
    public static DateTime ShowLocalTime(DateTime dtUtc) => dtUtc.ToLocalTime();

    public static TimeZoneInfo AppointmentTimeZoneInfo(Location location) {
                string tzId;
        if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows)) {
        switch(location) {
            case Location.NewYork: tzId = "Eastern Standard Time";
                break;
            case Location.London: tzId = "GMT Standard Time";
                break;
            case Location.Paris: tzId = "W. Europe Standard Time";
                break;
            default: tzId = string.Empty; 
                break;
        }
        } else {
            switch(location) {
                case Location.NewYork: tzId = "America/New_York";
                    break;
                case Location.London: tzId = "Europe/London";
                    break;
                case Location.Paris: tzId = "Europe/Paris";
                    break;
                default: tzId = string.Empty;
                    break;
            }
        }

        return TimeZoneInfo.FindSystemTimeZoneById(tzId);
        
    }
    public static DateTime Schedule(string appointmentDateDescription, Location location)
    {
        DateTime dtAppointmentLocal = DateTime.Parse(appointmentDateDescription);
        return TimeZoneInfo.ConvertTimeToUtc(dtAppointmentLocal, AppointmentTimeZoneInfo(location));
    }

    public static DateTime GetAlertTime(DateTime appointment, AlertLevel alertLevel)
    {
        TimeSpan alertTimeSpan;

        switch (alertLevel) {
            case AlertLevel.Early:
                alertTimeSpan = new(1, 0, 0, 0);
                break;
            case AlertLevel.Standard:
                alertTimeSpan = new(1, 45, 0);
                break;
            case AlertLevel.Late:
                alertTimeSpan = new(0, 30, 0);
                break;
            default: alertTimeSpan = new(0, 0, 0);
                break;
        }
        return appointment - alertTimeSpan;
    }

    public static bool HasDaylightSavingChanged(DateTime dt, Location location)
    {
        var appointmentTzInfo = AppointmentTimeZoneInfo(location);
        return appointmentTzInfo.IsDaylightSavingTime(dt + TimeSpan.FromDays(7))
            || appointmentTzInfo.IsDaylightSavingTime(dt - TimeSpan.FromDays(7));
    }

    public static DateTime NormalizeDateTime(string dtStr, Location location)
    {
        CultureInfo culture;
        switch (location) {
            case Location.NewYork: culture = CultureInfo.CreateSpecificCulture("en-US");
                break;
            case Location.London: culture = CultureInfo.CreateSpecificCulture("en-GB");
                break;
            case Location.Paris: culture = CultureInfo.CreateSpecificCulture("fr-FR");
                break; 
            default: culture = CultureInfo.InvariantCulture;
                break;
        }
        
        DateTime dt;
        return DateTime.TryParse(dtStr, culture, out dt) ? dt : new DateTime(1, 1, 1);
    }
}
