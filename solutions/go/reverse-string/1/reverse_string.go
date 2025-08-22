package reverse


func Reverse(input string) string {

    if input == "" {
        return ""
    }
    
	reversed := []rune(input)
    i := len(reversed) - 1
    for _, r := range input {
        reversed[i] = r
        i--
    }
    
    return string(reversed)
}
