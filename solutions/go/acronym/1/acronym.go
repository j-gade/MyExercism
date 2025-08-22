// Package acronym converts a long name like Portable Network Graphics to its
// acronym (PNG).
//
// Punctuation is handled as follows: hyphens or dashes are word separators
// (like whitespace); all other punctuation can be removed from the input.
package acronym

import "unicode"

// Abbreviate returns an uppercase abbreviation (acronym) of the given string.
// Abbreviate is unicode-aware.
func Abbreviate(s string) string {
	acronym := []rune{}
	for wordStart := 0; wordStart < len(s); {
		for _, r := range s[wordStart:] {
			wordStart += len(string(r))
			if unicode.IsLetter(r) {
				acronym = append(acronym, unicode.ToUpper(r))
				break
			}
		}

		for _, r := range s[wordStart:] {
			wordStart += len(string(r))
			if unicode.IsSpace(r) || unicode.Is(unicode.Pd, r) {
				break
			}
		}

	}

	return string(acronym)
}
