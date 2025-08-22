using System;

class BirdCount
{
    private int[] birdsPerDay;

    public BirdCount(int[] birdsPerDay)
    {
        this.birdsPerDay = birdsPerDay;
    }

    private static int[] birdsLastWeek = [0, 2, 5, 3, 7, 8, 4];
    public static int[] LastWeek() => birdsLastWeek;
    
    public int Today() => birdsPerDay[birdsPerDay.GetUpperBound(0)];
    
    public void IncrementTodaysCount()
    {
        ++birdsPerDay[birdsPerDay.GetUpperBound(0)];
    }

    public bool HasDayWithoutBirds() => Array.Exists(birdsPerDay, birds => birds == 0);
    
    public int CountForFirstDays(int numberOfDays)
    {
        int count = 0;
        foreach (int birds in birdsPerDay[..numberOfDays])
        {
            count += birds;
        }
        return count;
    }

    public int BusyDays()
    {
        int busyDays = 0;
        foreach (int birds in birdsPerDay)
        {
            if (birds >= 5)
            {
                ++busyDays;
            }
        }
        return busyDays;
    }
}
