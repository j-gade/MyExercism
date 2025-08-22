// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

static double const HOURS_PER_DAY = 8.0;
static int const BILLABLE_DAYS_PER_MONTH = 22;

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate * HOURS_PER_DAY;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double const discount_multiplier = (100.0 - discount) / 100.0;
    return before_discount * discount_multiplier;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double monthly_rate_total = daily_rate(hourly_rate) * BILLABLE_DAYS_PER_MONTH;
    double discounted_monthly_rate = apply_discount(monthly_rate_total, discount);
    return static_cast<int>(std::ceil(discounted_monthly_rate));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double daily_rate_total = apply_discount(daily_rate(hourly_rate), discount);
    double days_in_budget_total = budget / daily_rate_total;
    return static_cast<int>(std::floor(days_in_budget_total));
}