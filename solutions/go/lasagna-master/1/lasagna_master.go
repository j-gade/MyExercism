package lasagna

func PreparationTime(layers []string, timePerLayer int) int {
    if timePerLayer == 0 {
        timePerLayer = 2
    }
    return len(layers) * timePerLayer
}

func Quantities(layers []string) (noodles int, sauce float64) {
    const gramsOfNoodles = 50
    const litersOfSauce = 0.2

    for _, layer := range layers {
        if layer == "noodles" {
            noodles += gramsOfNoodles
        } else if layer == "sauce" {
            sauce += litersOfSauce
        }
    }
    return
}

func AddSecretIngredient(friendsList []string, myList []string) {
    friendsLast := len(friendsList) - 1
    myLast := len(myList) - 1

    myList[myLast] = friendsList[friendsLast]
}

func ScaleRecipe(amountsForTwo []float64, portions int) (scaledAmounts []float64) {
    scaledAmounts = make([]float64, len(amountsForTwo))
    for i, amount := range amountsForTwo {
        scaledAmounts[i] = amount * float64(portions) / 2
    }
    return scaledAmounts
}
