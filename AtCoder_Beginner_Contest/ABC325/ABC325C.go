package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
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
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	h, w := io.NextInt(), io.NextInt()
	s := make([]string, h)
	for i := 0; i < h; i++ {
		s[i] = io.Text()
	}
	uf := newUnionFind(h * w)
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == '#' {
				a := i*w + j
				if i-1 >= 0 && j-1 >= 0 && s[i-1][j-1] == '#' {
					uf.union(a, a-w-1)
				}
				if i-1 >= 0 && s[i-1][j] == '#' {
					uf.union(a, a-w)
				}
				if i-1 >= 0 && j+1 < w && s[i-1][j+1] == '#' {
					uf.union(a, a-w+1)
				}
				if j-1 >= 0 && s[i][j-1] == '#' {
					uf.union(a, a-1)
				}
				if j+1 < w && s[i][j+1] == '#' {
					uf.union(a, a+1)
				}
				if i+1 < h && j-1 >= 0 && s[i+1][j-1] == '#' {
					uf.union(a, a+w-1)
				}
				if i+1 < h && s[i+1][j] == '#' {
					uf.union(a, a+w)
				}
				if i+1 < h && j+1 < w && s[i+1][j+1] == '#' {
					uf.union(a, a+w+1)
				}
			}
		}
	}
	d := map[int]int{}
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == '#' {
				a := i*w + j
				d[uf.parent(a)] = 1
			}
		}
	}
	fmt.Println(len(d))
}
