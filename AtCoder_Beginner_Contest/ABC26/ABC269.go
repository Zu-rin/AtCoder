package main

import "fmt"

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

type point struct {
	x, y int
}

func (a *point) isNeighboring(b *point) bool {
	dp := []point{{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}}
	for i := 0; i < len(dp); i++ {
		if a.x+dp[i].x == b.x && a.y+dp[i].y == b.y {
			return true
		}
	}
	return false
}

func main() {
	var (
		num int
	)
	fmt.Scan(&num)
	uf := newUnionFind(num)
	d := make([]point, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&d[i].x, &d[i].y)
	}
	for i := 0; i < num; i++ {
		for j := 0; j < i; j++ {
			if !uf.same(i, j) && d[i].isNeighboring(&d[j]) {
				uf.union(i, j)
			}
		}
	}
	ans := make(map[int]bool, 0)
	for i := 0; i < num; i++ {
		ans[uf.parent(i)] = false
	}
	fmt.Println(len(ans))
}
