package listops

// IntList is an abstraction of a list of integers which we can define methods on
type IntList []int

func (s IntList) Foldl(fn func(int, int) int, initial int) int {
	acc := initial
	for _, v := range s {
		acc = fn(acc, v)
	}
	return acc
}

func (s IntList) Foldr(fn func(int, int) int, initial int) int {
	acc := initial
	for i := len(s) - 1; i >= 0; i-- {
		acc = fn(s[i], acc)
	}
	return acc
}

func (s IntList) Filter(fn func(int) bool) IntList {
	newList := make(IntList, 0, cap(s))
	for _, v := range s {
		if fn(v) {
			newList = append(newList, v)
		}
	}
	return newList
}

func (s IntList) Length() int {
	return len(s)
}

func (s IntList) Map(fn func(int) int) IntList {
	newList := make(IntList, len(s))
	for i, v := range s {
		newList[i] = fn(v)
	}
	return newList
}

func (s IntList) Reverse() IntList {
	newList := make(IntList, len(s))
	for i, v := range s {
		newList[len(s)-i-1] = v
	}
	return newList
}

func (s IntList) Append(lst IntList) IntList {
	return append(s, lst...)
}

func (s IntList) Concat(lists []IntList) IntList {
	newList := s
	for _, list := range lists {
		newList = append(newList, list...)
	}
	return newList
}
