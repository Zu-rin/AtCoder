package main

import (
	"fmt"
)

type pos struct {
	x, y int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var h, w int
	a, b := pos{500, 500}, pos{0, 0}
	fmt.Scan(&h, &w)
	s := make([]string, h)
	for i := 0; i < h; i++ {
		fmt.Scan(&s[i])
		for j := 0; j < w; j++ {
			if s[i][j] == '#' {
				a.x = min(a.x, i)
				a.y = min(a.y, j)
				b.x = max(b.x, i)
				b.y = max(b.y, j)
			}
		}
	}
	for i := a.x; i <= b.x; i++ {
		for j := a.y; j <= b.y; j++ {
			if s[i][j] == '.' {
				fmt.Println(i+1, j+1)
				return
			}
		}
	}
}
