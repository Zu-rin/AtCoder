package main

import (
	"fmt"
)

type pos struct {
	x, y int
}

func parent(p []int, x int) int {
	if p[x] != x {
		p[x] = parent(p, p[x])
	}
	return p[x]
}

func union(p []int, x, y int) {
	p[parent(p, x)] = parent(p, y)
}

func main() {
	var n, D, x, y int
	fmt.Scan(&n, &D)
	D = D * D
	d := make([]pos, n)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x, &y)
		d[i] = pos{x, y}
		p[i] = i
	}
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			dx, dy := d[i].x-d[j].x, d[i].y-d[j].y
			if dx*dx+dy*dy <= D {
				union(p, i, j)
			}
		}
	}
	for i := 0; i < n; i++ {
		if parent(p, 0) == parent(p, i) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
