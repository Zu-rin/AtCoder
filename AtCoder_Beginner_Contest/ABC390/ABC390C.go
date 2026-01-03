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

type pos struct {
	i, j int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	h, w := io.NextInt(), io.NextInt()
	s := make([]string, h)
	l, r, u, d := w, -1, h, -1
	e := false
	for i := 0; i < h; i++ {
		s[i] = io.Text()
		for j := 0; j < w; j++ {
			switch s[i][j] {
			case '#':
				l = min(l, j)
				r = max(r, j)
				u = min(u, i)
				d = max(d, i)
			case '?':
				e = true
			}
		}
	}
	if l > r {
		if e {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
		return
	}
	for i := u; i <= d; i++ {
		for j := l; j <= r; j++ {
			if s[i][j] == '.' {
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}
