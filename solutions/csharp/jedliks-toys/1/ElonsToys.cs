using System;

class RemoteControlCar
{
    private int _metersDriven = 0;
    private int _batteryCharge = 100;
    
    public static RemoteControlCar Buy() => new RemoteControlCar();

    public string DistanceDisplay() => $"Driven {_metersDriven} meters";

    public string BatteryDisplay() => _batteryCharge > 0 ? $"Battery at {_batteryCharge}%" : "Battery empty";

    public void Drive()
    {
        if (_batteryCharge > 0)
        {
            --_batteryCharge;
            _metersDriven += 20;
        }
    }
}
