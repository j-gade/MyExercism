using System;

class RemoteControlCar
{
    private int _speed;
    private int _batteryDrain;
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
        if (_batteryCharge >= _batteryDrain)
        {
            _batteryCharge -= _batteryDrain;
            _distanceDriven += _speed;
        }
    }

    public static RemoteControlCar Nitro()
    {
        const int nitroSpeed = 50;
        const int nitroBattery = 4;
        return new RemoteControlCar(nitroSpeed, nitroBattery);
    }
}

class RaceTrack
{
    private int _distance;

    public RaceTrack(int distance)
    {
        _distance = distance;
    }
    
    public bool TryFinishTrack(RemoteControlCar car)
    {
        while (car.DistanceDriven() < _distance && !car.BatteryDrained())
        {
            car.Drive();
        }
        return car.DistanceDriven() >= _distance;
    }
}
