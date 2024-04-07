package main

func CountOccurrences(word string, text *string) int {
	// count number of occurrences of word in text.
	texx := text
	words := splitInWords(texx)
	count := 0
	for _, w := range words {
		if w == word {
			count++
		}
	}
	return count
}

func Keys[T comparable, U any](m map[T]U) (keys []T) {
    for k := range m {
        keys = append(keys, k)
    }
    return keys
}

func BoolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func Compare(word string, a, b ResultFromDto) int {
	text1 := a.Text()
	text2 := b.Text()
	count1 := CountOccurrences(word, text1)
	count2 := CountOccurrences(word, text2)
	if count1 < count2 {
		return -1
	} else if count1 > count2 {
		return 1
	} else {
		return BoolToInt(a.Name() < b.Name())
	}
}

func splitInWords(text *string) []string {
	// provide better implementation.
	isletter := func(c uint8) bool {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
	}
	words := make([]string, 0)
	i := 0
	for i < len(*text) {
		start := i
		end := i
		if isletter( (*text)[i]) {
			for end+1 < len(*text) && isletter( (*text)[end+1]) {
				end++
			}
			words = append(words, (*text)[start:end+1])
		}
		i = end + 1
	}
	return words
}

func Map[T any, U any](vs []T, f func(T) U) []U {
	vsm := make([]U, len(vs))
	for i, v := range vs {
		vsm[i] = f(v)
	}
	return vsm
}