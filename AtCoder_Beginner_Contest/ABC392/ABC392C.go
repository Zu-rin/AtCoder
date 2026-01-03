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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	p, q := make([]int, n+1), make([]int, n+1)
	ans := make([]int, n+1)
	for i := 1; i <= n; i++ {
		p[i] = io.NextInt()
	}
	for i := 1; i <= n; i++ {
		q[i] = io.NextInt()
	}
	for i := 1; i <= n; i++ {
		ans[q[i]] = q[p[i]]
	}
	for i := 1; i < n; i++ {
		fmt.Fprintf(io.Out, "%d ", ans[i])
	}
	fmt.Fprintln(io.Out, ans[n])
}
