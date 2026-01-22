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
	a, b int
}

func (p *pair) min() int {
	if p.a < p.b {
		return p.a
	}
	return p.b
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, q := io.NextInt(), io.NextInt()
	d := make([]pair, n)
	for i := 0; i < n; i++ {
		d[i].a = io.NextInt()
	}
	for i := 0; i < n; i++ {
		d[i].b = io.NextInt()
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += d[i].min()
	}
	for i := 0; i < q; i++ {
		c, x, v := io.Text(), io.NextInt()-1, io.NextInt()
		ans -= d[x].min()
		if c == "A" {
			d[x].a = v
		} else {
			d[x].b = v
		}
		ans += d[x].min()
		fmt.Fprintln(io.Out, ans)
	}
}
