package main

import "fmt"

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type unionFind struct {
	n int
	d []int
}

func newUnionFind(n int) *unionFind {
	d := make([]int, n+1)
	for i := 0; i <= n; i++ {
		d[i] = i
	}
	return &unionFind{
		n: n,
		d: d,
	}
}

func (uf *unionFind) parent(a int) int {
	if uf.d[a] == a {
		return a
	} else {
		uf.d[a] = uf.parent(uf.d[a])
		return uf.d[a]
	}
}

func (uf *unionFind) union(a int, b int) {
	uf.d[uf.parent(b)] = uf.parent(a)
}

func (uf *unionFind) same(a int, b int) bool {
	return uf.parent(a) == uf.parent(b)
}

var (
	num, m int
)

func main() {
	var a, b int
	ans := 0
	fmt.Scan(&num, &m)
	uf := newUnionFind(num)
	for i := 0; i < m; i++ {
		fmt.Scan(&a, &b)
		uf.union(a, b)
	}
	for i := 1; i <= num; i++ {
		if uf.parent(i) == i {
			ans++
		}
	}
	fmt.Println(ans)
}
