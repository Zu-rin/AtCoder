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
	n, t := io.NextInt(), io.NextInt()
	ans := 1
	d := make([]int, n)
	x := make(map[int]int)
	x[0] = n
	for i := 0; i < t; i++ {
		a, b := io.NextInt()-1, io.NextInt()
		x[d[a]]--
		if x[d[a]] == 0 {
			ans--
		}
		d[a] += b
		x[d[a]]++
		if x[d[a]] == 1 {
			ans++
		}
		fmt.Fprintln(io.Out, ans)
	}
}
