public static class CentralBank
{
    private static string tooBig = "*** Too Big ***";
    private static string muchTooBig = "*** Much Too Big ***";
    
    public static string DisplayDenomination(long @base, long multiplier)
    {
        try
        {
            long denomination = checked(@base * multiplier);
            return denomination.ToString();
        }
        catch (OverflowException)
        {
            return tooBig;
        }
    }

    public static string DisplayGDP(float @base, float multiplier)
    {
        float gdp = @base * multiplier;
        return float.IsInfinity(gdp) ? tooBig : gdp.ToString();
    }

    public static string DisplayChiefEconomistSalary(decimal salaryBase, decimal multiplier)
    {
        try
        {
            decimal salary = salaryBase * multiplier;
            return salary.ToString();
        }
        catch (OverflowException)
        {
            return muchTooBig;
        }
    }
}
