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

type pos struct {
	x, y int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, q := io.NextInt(), io.NextInt()
	d := make([]pos, n)
	for i := 0; i < n; i++ {
		d[i] = pos{n - i, 0}
	}
	a := pos{1, 0}
	for i := 0; i < q; i++ {
		k := io.NextInt()
		if k == 1 {
			c := io.Text()
			switch c {
			case "R":
				a.x++
			case "L":
				a.x--
			case "U":
				a.y++
			case "D":
				a.y--
			}
			d = append(d, a)
		} else {
			c := io.NextInt()
			fmt.Printf("%d %d\n", d[len(d)-c].x, d[len(d)-c].y)
		}
	}
}
