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

type Pair struct {
	i, j int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	d := make([]int, n+1)
	ans := make([]Pair, 0, n)
	for i := 1; i <= n; i++ {
		d[i] = io.NextInt()
	}
	for i := 1; i <= n; i++ {
		if d[i] != i {
			k := i
			for d[k] != k {
				ans = append(ans, Pair{min(k, d[k]), max(k, d[k])})
				d[k], d[d[k]] = d[d[k]], d[k]
				k = d[k]
			}
		}
	}
	fmt.Println(len(ans))
	for _, p := range ans {
		fmt.Fprintf(io.Out, "%d %d\n", p.i, p.j)
	}
}
