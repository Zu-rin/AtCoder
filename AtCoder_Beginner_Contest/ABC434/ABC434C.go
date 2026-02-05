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
	q := io.NextInt()
	for i := 0; i < q; i++ {
		n, h := io.NextInt(), io.NextInt()
		t, l, u := make([]int, n+1), make([]int, n+1), make([]int, n+1)
		t[0], l[0], u[0] = 0, h, h
		for j := 1; j <= n; j++ {
			t[j], l[j], u[j] = io.NextInt(), io.NextInt(), io.NextInt()
		}
		ok := true
		for j := 0; j < n; j++ {
			dif := t[j+1] - t[j]
			if l[j+1] > u[j]+dif || u[j+1] < l[j]-dif {
				ok = false
				break
			}
			u[j+1] = min(u[j+1], u[j]+dif)
			l[j+1] = max(l[j+1], l[j]-dif)
		}
		if ok {
			fmt.Fprintln(io.Out, "Yes")
		} else {
			fmt.Fprintln(io.Out, "No")
		}
	}
}
