package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
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

type Io struct {
	In  *bufio.Scanner
	Out *bufio.Writer
}

func NewIo(r io.Reader, w io.Writer) *Io {
	const buf = 1 << 20
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords)
	s.Buffer(make([]byte, buf), buf)
	return &Io{
		In:  s,
		Out: bufio.NewWriter(w),
	}
}

func (io *Io) Text() string {
	if !io.In.Scan() {
		panic(io.In.Err())
	}
	return io.In.Text()
}

func (io *Io) NextInt() int {
	x, err := strconv.Atoi(io.Text())
	if err != nil {
		panic(err)
	}
	return x
}

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

func next_permutation(arr sort.Interface) bool {
	len := arr.Len() - 1
	i := len
	for i > 0 && !arr.Less(i-1, i) {
		i--
	}
	if i <= 0 {
		return false
	}
	j := len
	for !arr.Less(i-1, j) {
		j--
	}
	arr.Swap(i-1, j)
	j = len
	for i < j {
		arr.Swap(i, j)
		i++
		j--
	}
	return true
}

type rule struct {
	x    int
	prev []int
}

func judge(p []int, rules []rule) bool {
	m := make([]int, 9)
	for i := 0; i < 9; i++ {
		m[p[i]] = i
	}
	for _, r := range rules {
		if m[r.prev[0]] < m[r.x] && m[r.prev[1]] < m[r.x] {
			return false
		}
	}
	return true
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	d := make([][]int, 3)
	p := []int{0, 1, 2, 3, 4, 5, 6, 7, 8}
	rules := make([]rule, 0)
	all := 1
	for i := 1; i <= 9; i++ {
		all *= i
	}
	for i := 0; i < 3; i++ {
		d[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
			d[i][j] = io.NextInt()
		}
	}
	for _, ab := range [][]int{{0, 1}, {1, 2}, {0, 2}} {
		a, b := ab[0], ab[1]
		for i := 0; i < 3; i++ {
			if d[i][a] == d[i][b] {
				rules = append(rules, rule{i*3 + 3 - a - b, []int{i*3 + a, i*3 + b}})
			}
			if d[a][i] == d[b][i] {
				rules = append(rules, rule{(3-a-b)*3 + i, []int{a*3 + i, b*3 + i}})
			}
		}
		if d[a][a] == d[b][b] {
			rules = append(rules, rule{(3-a-b)*3 + (3 - a - b), []int{a*3 + a, b*3 + b}})
		}
		if d[a][2-a] == d[b][2-b] {
			rules = append(rules, rule{(3-a-b)*3 + (a + b - 1), []int{a*3 + (2 - a), b*3 + (2 - b)}})
		}
	}
	cnt := 0
	for {
		if judge(p, rules) {
			cnt++
		}
		if !next_permutation(sort.IntSlice(p)) {
			break
		}
	}
	fmt.Println((float64(cnt) / float64(all)))
}
