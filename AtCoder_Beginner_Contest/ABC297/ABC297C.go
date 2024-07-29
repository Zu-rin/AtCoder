package main

import (
	"fmt"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)
	for i := 0; i < h; i++ {
		var s string
		fmt.Scan(&s)
		for j := 0; j < w-1; j++ {
			if s[j] == 'T' && s[j+1] == 'T' {
				s = s[:j] + "PC" + s[j+2:]
				j++
			}
		}
		fmt.Println(s)
	}
}
