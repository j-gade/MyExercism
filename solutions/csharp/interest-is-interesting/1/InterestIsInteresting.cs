using System;

static class SavingsAccount
{
    public static float InterestRate(decimal balance)
    {
        float interest = 2.475f;
        if (balance < 0.0m)
        {
            interest = 3.213f;
        } else if (balance < 1000.0m)
        {
            interest = 0.5f;
        } else if (balance < 5000)
        {
            interest = 1.621f;
        }
        return interest;
    }

    public static decimal Interest(decimal balance) => (balance * (decimal)(InterestRate(balance) / 100));

    public static decimal AnnualBalanceUpdate(decimal balance) => (balance + Interest(balance));

    public static int YearsBeforeDesiredBalance(decimal balance, decimal targetBalance)
    {
        int years = 0;
        if (balance >= targetBalance)
        {
            return years;
        }
        do
        {
            balance = AnnualBalanceUpdate(balance);
            ++years;
        } while (balance < targetBalance);
        return years;
    }
}
