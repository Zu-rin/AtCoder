package main

import (
	"fmt"
)

func main() {
	var n, m, c, x int
	fmt.Scan(&m, &n)
	d := make([][10]bool, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c)
		for j := 0; j < c; j++ {
			fmt.Scan(&x)
			d[i][x-1] = true
		}
	}
	ans := 0
	for b := 0; b < (1 << uint(n)); b++ {
		p := 0
		for i := 0; i < n; i++ {
			if b&(1<<uint(i)) != 0 {
				for j := 0; j < len(d[i]); j++ {
					if d[i][j] {
						p |= (1 << uint(j))
					}
				}
			}
		}
		if p == (1<<uint(m))-1 {
			ans++
		}
	}
	fmt.Println(ans)
}
