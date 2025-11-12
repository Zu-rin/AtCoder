package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	c := 0
	d := make([]int, n+1)
	for i := 0; i < 3*n; i++ {
		var a int
		fmt.Scan(&a)
		d[a]++
		if d[a] == 2 {
			if c < n-1 {
				fmt.Printf("%v ", a)
			} else {
				fmt.Printf("%v\n", a)
			}
			c++
		}
	}
}
