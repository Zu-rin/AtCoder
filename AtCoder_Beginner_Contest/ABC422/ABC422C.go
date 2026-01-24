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

func check(k, a, b, c int) bool {
	if min(a, c) < k {
		return false
	}
	a -= k
	c -= k
	if a+b+c < k {
		return false
	}
	return true
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	q := io.NextInt()
	for i := 0; i < q; i++ {
		a, b, c := io.NextInt(), io.NextInt(), io.NextInt()
		l, r := 0, min(a, c)+1
		for l+1 < r {
			p := (l + r) >> 1
			if check(p, a, b, c) {
				l = p
			} else {
				r = p
			}
		}
		fmt.Fprintln(io.Out, l)
	}
}
