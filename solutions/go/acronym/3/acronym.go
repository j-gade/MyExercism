// Package acronym converts a long name like Portable Network Graphics to its
// acronym (PNG).
// Spaces, dashes, and underscores are considered word separators; all other
// punctuation remains part of the word.
package acronym

import (
	"strings"
	"unicode"
	"unicode/utf8"
)

// Abbreviate returns an uppercase abbreviation (acronym) of the given string.
// Abbreviate is unicode-aware.
func Abbreviate(s string) string {
	// Separate on unicode spaces, dashes, and connectors.
	f := func(r rune) bool {
		return unicode.In(r, unicode.Space, unicode.Pc, unicode.Pd)
	}

	acronym := []rune{}
	for _, w := range strings.FieldsFunc(s, f) {
		r, _ := utf8.DecodeRuneInString(w)
		acronym = append(acronym, unicode.ToUpper(r))
	}

	return string(acronym)
}
