package main

import (
	"fmt"
	"reflect"
	"sort"
)

func rotate(s *[]string) *[]string {
	ans := make([]string, len((*s)[0]))
	for i := 0; i < len((*s)[0]); i++ {
		a := make([]byte, 0, len(*s))
		for j := 0; j < len(*s); j++ {
			a = append(a, (*s)[j][i])
		}
		ans[i] = string(a)
	}
	return &ans
}

func main() {
	var (
		h, w int
	)
	fmt.Scan(&h, &w)
	s := make([]string, h)
	t := make([]string, h)
	for i := 0; i < h; i++ {
		fmt.Scan(&s[i])
	}
	for i := 0; i < h; i++ {
		fmt.Scan(&t[i])
	}
	s = *rotate(&s)
	t = *rotate(&t)
	sort.Strings(s)
	sort.Strings(t)
	if reflect.DeepEqual(s, t) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
