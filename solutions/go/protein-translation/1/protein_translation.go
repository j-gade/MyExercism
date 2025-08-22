package protein

import "errors"

var ErrStop = errors.New("protein: found stop")
var ErrInvalidBase = errors.New("protein: found invalid base")

const codonLength = 3

func FromRNA(rna string) ([]string, error) {
	poly := make([]string, 0)
	for i := 0; i < len(rna); i += codonLength {
		if len(rna[i:]) < 3 {
			panic("FromRNA: unexpected short string")
		}
		protein, err := FromCodon(rna[i : i+codonLength])
		if err == ErrStop {
			break
		}
		if err == ErrInvalidBase {
			return nil, err
		}
		poly = append(poly, protein)
	}
	return poly, nil
}

func FromCodon(codon string) (protein string, err error) {
	switch codon {
	case "AUG":
		protein = "Methionine"
	case "UUU", "UUC":
		protein = "Phenylalanine"
	case "UUA", "UUG":
		protein = "Leucine"
	case "UCU", "UCC", "UCA", "UCG":
		protein = "Serine"
	case "UAU", "UAC":
		protein = "Tyrosine"
	case "UGU", "UGC":
		protein = "Cysteine"
	case "UGG":
		protein = "Tryptophan"
	case "UAA", "UAG", "UGA":
		err = ErrStop
	default:
		err = ErrInvalidBase
	}

	return
}
