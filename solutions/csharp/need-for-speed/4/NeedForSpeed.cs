using System;

class RemoteControlCar
{
    private readonly int _speed;
    private readonly int _batteryDrain;
    private int _distanceDriven;
    private int _batteryCharge = 100;

    public RemoteControlCar(int speed, int batteryDrain)
    {
        _speed = speed;
        _batteryDrain = batteryDrain;
    }
    
    public bool BatteryDrained() => _batteryCharge < _batteryDrain;

    public int DistanceDriven() => _distanceDriven;

    public void Drive()
    {
        if (_batteryCharge >= _batteryDrain) {
            _batteryCharge -= _batteryDrain;
            _distanceDriven += _speed;
        }
    }

    private const int nitroSpeed = 50;
    private const int nitroBattery = 4;
    public static RemoteControlCar Nitro() => new RemoteControlCar(nitroSpeed, nitroBattery);
}

class RaceTrack
{
    private readonly int _distance;

    public RaceTrack(int distance)
    {
        _distance = distance;
    }
    
    public bool TryFinishTrack(RemoteControlCar car)
    {
        while (!car.BatteryDrained())
        {
            car.Drive();
        }
        return car.DistanceDriven() >= _distance;
    }
}
