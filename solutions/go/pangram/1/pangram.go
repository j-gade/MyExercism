package pangram

import "strings"

func IsPangram(input string) bool {
	testString := strings.ToLower(input)
    for _, letter := range "abcdefghijklmnopqrstuvwxyz" {
        if !strings.ContainsRune(testString, letter) {
        	return false
        }
    }
    return true
}
