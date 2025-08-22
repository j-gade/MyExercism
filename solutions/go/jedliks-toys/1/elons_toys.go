package elon

import "fmt"

func (c *Car) Drive() {
    if newBattery := c.battery - c.batteryDrain; newBattery >= 0 {
        c.battery = newBattery
        c.distance += c.speed
    }
}

func (c Car) DisplayDistance() string {
    return fmt.Sprintf("Driven %d meters", c.distance)
}

func (c Car) DisplayBattery() string {
    return fmt.Sprintf("Battery at %d%%", c.battery)
}

func (c Car) CanFinish(trackDistance int) bool {
    if trackDistance == 0 {
        return true
    }
    return (((trackDistance - 1) / c.speed) + 1) * c.batteryDrain <= c.battery
}
