using System;

public static class PhoneNumber
{
    public static (bool IsNewYork, bool IsFake, string LocalNumber) Analyze(string phoneNumber)
    {
        string[] split = phoneNumber.Split('-');
        (string area, string prefix, string line) = (split[0], split[1], split[2]);
        return (area == "212", prefix == "555", line);
    }

    public static bool IsFake((bool IsNewYork, bool IsFake, string LocalNumber) phoneNumberInfo) => phoneNumberInfo.IsFake;
}
