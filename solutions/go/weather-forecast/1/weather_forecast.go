// Package weather provides tools for forecasting weather
// in the cities of Goblinocus.
package weather

// CurrentCondition contains the current weather condition in
// the current location.
var CurrentCondition string

// CurrentLocation contains the current location where we are
// interested in the weather.
var CurrentLocation string

// Forecast updates the CurrentCondition and CurrentLocation
// for the weather, and returns the current location and
// condition as a string.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
