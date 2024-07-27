package main

import (
	"fmt"
)

func main() {
	var n, a int
	ans := 0
	fmt.Scan(&n)
	d := make(map[int]int)
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		d[a]++
	}
	for _, v := range d {
		ans += v >> 1
	}
	fmt.Println(ans)
}
