package main

import (
	"fmt"
)

func main() {
	var n, x int
	var s string
	fmt.Scan(&n, &s)
	ans := 0
	for i := 0; i < n; i++ {
		if s[i] == 'o' {
			x++
		} else {
			x = 0
		}
		if ans < x {
			ans = x
		}
	}
	if ans == 0 || ans == n {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}
