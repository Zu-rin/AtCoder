package main

import (
	"fmt"
)

func main() {
	var n, k, a int
	ans := 0
	fmt.Scan(&n, &k)
	d := make(map[int]int)
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		d[a] = 1
	}
	for i := 0; i < k; i++ {
		if d[i] == 0 {
			break
		}
		ans++
	}
	fmt.Println(ans)
}
