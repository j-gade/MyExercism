package romannumerals

import "fmt"

func ToRomanNumeral(input int) (string, error) {

    if input <= 0 || input > 3999 {
    return "", fmt.Errorf("%d is out of range", input)
    }
    
	ones := []string{
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX",
    }
    
    tens := []string{
        "",
        "X",
        "XX",
        "XXX",
        "XL",
        "L",
        "LX",
        "LXX",
        "LXXX",
        "XC",
    }

    hundreds := []string{
        "",
        "C",
        "CC",
        "CCC",
        "CD",
        "D",
        "DC",
        "DCC",
        "DCCC",
        "CM",
    }

    thousands := []string{
        "",
        "M",
        "MM",
        "MMM",
    }

	roman := thousands[(input / 1000) % 10] + hundreds[(input / 100) % 10] + tens[(input / 10) % 10] + ones[input % 10]
    return roman, nil
}
