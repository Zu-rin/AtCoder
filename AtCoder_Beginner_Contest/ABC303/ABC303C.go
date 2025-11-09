package main

import (
	"fmt"
)

type pos struct {
	x, y int
}

func main() {
	var n, m, h, k int
	var s string
	d := make(map[pos]bool)
	fmt.Scan(&n, &m, &h, &k, &s)
	for i := 0; i < m; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		d[pos{x, y}] = true
	}
	x, y := 0, 0
	for i := 0; i < n; i++ {
		switch s[i] {
		case 'R':
			x++
		case 'L':
			x--
		case 'U':
			y++
		case 'D':
			y--
		}
		h--
		if h < 0 {
			fmt.Println("No")
			return
		}
		if d[pos{x, y}] && h < k {
			h = k
			d[pos{x, y}] = false
		}
	}
	fmt.Println("Yes")
}
