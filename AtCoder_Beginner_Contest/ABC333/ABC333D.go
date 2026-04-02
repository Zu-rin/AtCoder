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
	n := io.NextInt()
	uf := newUnionFind(n)
	for i := 0; i < n-1; i++ {
		a, b := io.NextInt(), io.NextInt()
		if a != 1 && b != 1 {
			uf.union(a, b)
		}
	}
	d := make(map[int]int)
	for i := 2; i <= n; i++ {
		d[uf.parent(i)]++
	}
	ma := 0
	for _, v := range d {
		ma = max(ma, v)
	}
	fmt.Println(n - ma)
}
