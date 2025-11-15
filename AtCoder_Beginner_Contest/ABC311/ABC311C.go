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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

type node struct {
	next    int
	visited bool
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()

	n := io.NextInt()
	d := make([]node, n)
	for i := 0; i < n; i++ {
		d[i] = node{next: io.NextInt() - 1, visited: false}
	}
	p := 0
	for {
		if d[p].visited {
			break
		}
		d[p].visited = true
		p = d[p].next
	}
	a := make([]int, 0)
	a = append(a, p)
	for {
		if d[a[len(a)-1]].next == p {
			break
		}
		a = append(a, d[a[len(a)-1]].next)
	}
	fmt.Printf("%v\n", len(a))
	for i := 0; i < len(a)-1; i++ {
		fmt.Printf("%v ", a[i]+1)
	}
	fmt.Printf("%v\n", a[len(a)-1]+1)
}
