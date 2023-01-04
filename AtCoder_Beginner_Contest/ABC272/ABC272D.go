package main

import "fmt"

var (
	n, m int
	k    []point
	ans  [][]int
)

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

type point struct {
	i, j int
}

type Queue struct {
	data []point
}

func (que *Queue) push(p *point) {
	que.data = append(que.data, *p)
}

func (que *Queue) pop() *point {
	ans := que.data[0]
	que.data = que.data[1:]
	return &ans
}

func (que *Queue) empty() bool {
	return len(que.data) == 0
}

func search() {
	que := Queue{}
	que.push(&point{0, 0})
	ans[0][0] = 0
	for !que.empty() {
		x := que.pop()
		for i := 0; i < len(k); i++ {
			nx := point{x.i + k[i].i, x.j + k[i].j}
			if min(nx.i, nx.j) < 0 || n <= max(nx.i, nx.j) {
				continue
			}
			if ans[nx.i][nx.j] < 0 {
				ans[nx.i][nx.j] = ans[x.i][x.j] + 1
				que.push(&nx)
			}
		}
	}
}

func main() {
	fmt.Scan(&n, &m)
	d := []int{0}
	k = []point{}
	ans = make([][]int, n)
	for i := 1; i*i <= m; i++ {
		d = append(d, i*i)
	}
	for i := 0; i < len(d); i++ {
		for j := 0; j < len(d); j++ {
			if d[i]+d[j] == m {
				k = append(k, point{i, j}, point{-i, j}, point{i, -j}, point{-i, -j})
			}
		}
	}
	for i := 0; i < n; i++ {
		ans[i] = make([]int, n)
		for j := 0; j < n; j++ {
			ans[i][j] = -1
		}
	}
	search()
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			fmt.Printf("%v ", ans[i][j])
		}
		fmt.Println(ans[i][n-1])
	}
}
