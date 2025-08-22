package blackjack

// ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
    // This would probably be better as a map, but the exercise is for switch.
	switch card {
		case "ace":
        	return 11
        case "king", "queen", "jack", "ten":
        	return 10
        case "nine":
        	return 9
        case "eight":
        	return 8
        case "seven":
        	return 7
        case "six":
        	return 6
        case "five":
        	return 5
        case "four":
        	return 4
        case "three":
        	return 3
        case "two":
        	return 2
        case "one":
        	return 1
        default:
        	return 0
    }
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	myTotal := ParseCard(card1) + ParseCard(card2)
    dealerTotal := ParseCard(dealerCard)

    switch {
        case card1 == "ace" && card2 == "ace":
        	return "P"
        case myTotal == 21:
        	if dealerTotal < 10 {
                return "W"
            }
        	return "S"
        case myTotal > 16:
        	return "S"
        case myTotal > 11:
        	if dealerTotal < 7 {
                return "S"
            }
        	return "H"
        default:
        	return "H"
        }
}

