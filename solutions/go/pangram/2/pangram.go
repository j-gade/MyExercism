package pangram

import "strings"

type empty struct {}

func IsPangram(input string) bool {
	testString := strings.ToLower(input)
	eachLetter := make(map[rune]empty)
    
    for _, r := range testString {
		eachLetter[r] = empty{}
    }

	for _, r := range "abcdefghijklmnopqrstuvwxyz" {
        if _, ok := eachLetter[r]; !ok {
            return false
        }
    }
    return true
}
