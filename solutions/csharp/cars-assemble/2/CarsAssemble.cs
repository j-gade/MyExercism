using System;

static class AssemblyLine
{
    public static double SuccessRate(int speed)
    {
        double rate = 0.0;
        if (speed >= 10)
        {
            rate = 0.77;
        } else if (speed == 9)
        {
            rate = 0.80;
        } else if (speed > 4)
        {
            rate = 0.90;
        } else if (speed > 0)
        {
            rate = 1.0;
        }
        
        return rate;
    }

    const int CarsPerHour = 221;
    public static double ProductionRatePerHour(int speed) => speed * CarsPerHour * SuccessRate(speed);

    public static int WorkingItemsPerMinute(int speed) => (int)(ProductionRatePerHour(speed) / 60.0);
}
