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
	n, q := io.NextInt(), io.NextInt()
	a, b, min := make([]int, n+1), make([]int, q+1), 0
	for i := 0; i < q; i++ {
		k, x := io.NextInt(), io.NextInt()
		switch k {
		case 1:
			a[x]++
			b[a[x]]++
			if b[a[x]] == n {
				min = a[x]
			}
		case 2:
			if x+min > q {
				fmt.Fprintln(io.Out, 0)
			} else {
				fmt.Fprintln(io.Out, b[x+min])
			}
		}
	}
}
