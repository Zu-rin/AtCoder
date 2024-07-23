package main

import (
	"fmt"
)

func main() {
	var n int
	var s string
	x, y := 0, 0
	plural := false
	d := make(map[int]map[int]int)
	d[0] = make(map[int]int)
	d[0][0] = 1
	fmt.Scan(&n, &s)
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
		if _, ok := d[x]; ok {
			if _, ok := d[x][y]; ok {
				plural = true
				break
			}
		} else {
			d[x] = make(map[int]int)
		}
		d[x][y] = 1
	}
	if plural {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
