package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

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

type pair struct {
	i, j int
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
	for i := range s {
		s[i] = io.Text()
	}
	uf := newUnionFind(h*w + 1)
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == '.' {
				for _, d := range []pair{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} {
					ni, nj := i+d.i, j+d.j
					if ni < 0 || h <= ni || nj < 0 || w <= nj {
						uf.union(i*w+j, h*w)
					} else if s[ni][nj] == '.' {
						uf.union(i*w+j, ni*w+nj)
					}
				}
			}
		}
	}
	d := make(map[int]bool)
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == '.' {
				d[uf.parent(i*w+j)] = true
			}
		}
	}
	if d[uf.parent(h*w)] {
		fmt.Println(len(d) - 1)
	} else {
		fmt.Println(len(d))
	}
}
