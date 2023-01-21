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

var (
	num  int
	s, t string
)

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

func main() {
	fmt.Scan(&num)
	ok := true
	k := 0
	d := map[string]int{}
	mp := map[string]string{}
	for i := 0; i < num; i++ {
		fmt.Scan(&s, &t)
		mp[s] = t
		if _, exist := d[s]; !exist {
			d[s] = k
			k++
		}
		if _, exist := d[t]; !exist {
			d[t] = k
			k++
		}
	}
	uf := newUnionFind(len(d))
	for s, t = range mp {
		if uf.same(d[s], d[t]) {
			ok = false
			break
		}
		uf.union(d[s], d[t])
	}
	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
