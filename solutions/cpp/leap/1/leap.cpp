#include "leap.h"

namespace leap {
bool is_leap_year(int year)
{
	bool divisible_by_400 = !(year % 400);
	bool divisible_by_100 = !(year % 100);
	bool divisible_by_4 = !(year % 4);

	return divisible_by_400 || (divisible_by_4 && !divisible_by_100);
}
}  // namespace leap
