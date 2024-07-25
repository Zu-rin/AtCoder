package main

import (
	"fmt"
)

var h, w int

func dfs(y, x int, d [][]int) []map[int]bool {
	if y == h-1 && x == w-1 {
		return []map[int]bool{{d[y][x]: true}}
	}
	ans := make([]map[int]bool, 0)
	if y < h-1 {
		a := dfs(y+1, x, d)
		for i := 0; i < len(a); i++ {
			if _, ok := a[i][d[y][x]]; !ok {
				a[i][d[y][x]] = true
				ans = append(ans, a[i])
			}
		}
	}
	if x < w-1 {
		b := dfs(y, x+1, d)
		for i := 0; i < len(b); i++ {
			if _, ok := b[i][d[y][x]]; !ok {
				b[i][d[y][x]] = true
				ans = append(ans, b[i])
			}
		}
	}
	return ans
}

func main() {
	fmt.Scan(&h, &w)
	d := make([][]int, h)
	for i := 0; i < h; i++ {
		d[i] = make([]int, w)
		for j := 0; j < w; j++ {
			fmt.Scan(&d[i][j])
		}
	}
	ans := dfs(0, 0, d)
	fmt.Println(len(ans))
}
