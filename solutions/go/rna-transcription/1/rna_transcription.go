package strand

var transcription = map[rune]rune{
	'G': 'C',
	'C': 'G',
	'T': 'A',
	'A': 'U',
}

func ToRNA(dna string) string {
	var rna string
	for _, n := range dna {
		if t, ok := transcription[n]; ok {
			rna += string(t)
		} else {
			break
		} // Stop processing on invalid nucleotide
	}
	return rna
}
