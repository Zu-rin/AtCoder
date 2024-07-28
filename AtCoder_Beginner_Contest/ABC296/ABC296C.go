package main

import (
	"fmt"
)

func main() {
	var n, x, a int
	fmt.Scan(&n, &x)
	d := make(map[int]int)
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		d[a] = 1
	}
	ans := false
	for v := range d {
		if _, ok := d[v+x]; ok {
			ans = true
			break
		}
	}
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
