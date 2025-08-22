package cars

// CalculateWorkingCarsPerHour calculates how many working cars are
// produced by the assembly line every hour.
func CalculateWorkingCarsPerHour(productionRate int, successRate float64) float64 {
	return float64(productionRate) * (successRate / 100.0)
}

// CalculateWorkingCarsPerMinute calculates how many working cars are
// produced by the assembly line every minute.
func CalculateWorkingCarsPerMinute(productionRate int, successRate float64) int {
	carsPerHour := CalculateWorkingCarsPerHour(productionRate, successRate)
	const minutesPerHour = 60.0
	return int(carsPerHour / minutesPerHour)
}

// CalculateCost works out the cost of producing the given number of cars.
func CalculateCost(carsCount int) uint {
	const (
		carsPerGroup = 10
		costPerCar   = 10_000
		costPerGroup = 95_000
	)

	carGroups := carsCount / carsPerGroup
	carsRemaining := carsCount % carsPerGroup

	return uint(carGroups*costPerGroup + carsRemaining*costPerCar)
}
