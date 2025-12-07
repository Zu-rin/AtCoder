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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	m := io.NextInt()
	b := make([]int, m)
	for i := 0; i < m; i++ {
		b[i] = io.NextInt()
	}
	l := io.NextInt()
	c := make([]int, l)
	for i := 0; i < l; i++ {
		c[i] = io.NextInt()
	}
	d := make(map[int]bool)
	for _, aa := range a {
		for _, bb := range b {
			for _, cc := range c {
				d[aa+bb+cc] = true
			}
		}
	}
	n = io.NextInt()
	for i := 0; i < n; i++ {
		x := io.NextInt()
		if d[x] {
			fmt.Fprintln(io.Out, "Yes")
		} else {
			fmt.Fprintln(io.Out, "No")
		}
	}
}
