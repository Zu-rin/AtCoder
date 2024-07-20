package main

import (
	"fmt"
)

func parent(x int, u []int) int {
	if u[x] == x {
		return x
	}
	u[x] = parent(u[x], u)
	return u[x]
}

func main() {
	var n, m, a, b int
	ok := true
	fmt.Scan(&n, &m)
	d := make([]int, n)
	u := make([]int, n)
	for i := 0; i < n; i++ {
		u[i] = i
	}
	for i := 0; i < m; i++ {
		fmt.Scan(&a, &b)
		a--
		b--
		d[a]++
		d[b]++
		if parent(a, u) != parent(b, u) {
			u[parent(a, u)] = parent(b, u)
		}
	}
	if n != m+1 {
		ok = false
	}
	for i := 0; i < n; i++ {
		if d[i] > 2 {
			ok = false
		}
		if parent(i, u) != parent(0, u) {
			ok = false
		}
	}
	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
