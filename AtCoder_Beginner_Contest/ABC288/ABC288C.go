package main

import "fmt"

func parent(x int, u []int) int {
	if u[x] == x {
		return x
	}
	u[x] = parent(u[x], u)
	return u[x]
}

func main() {
	var n, m, a, b int
	fmt.Scan(&n, &m)
	u := make([]int, n)
	for i := 0; i < n; i++ {
		u[i] = i
	}
	for i := 0; i < m; i++ {
		fmt.Scan(&a, &b)
		u[parent(a-1, u)] = parent(b-1, u)
	}
	d := make(map[int]int)
	for i := 0; i < n; i++ {
		d[parent(i, u)]++
	}
	need := 0
	for _, v := range d {
		need += v - 1
	}
	fmt.Println(m - need)
}
