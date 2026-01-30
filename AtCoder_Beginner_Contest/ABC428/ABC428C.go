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
	a, b := make([]int, 0, q), make([]int, 0, q)
	a, b = append(a, 0), append(b, 0)
	for i := 0; i < q; i++ {
		k := io.NextInt()
		switch k {
		case 1:
			c := io.Text()
			switch c[0] {
			case '(':
				a = append(a, a[len(a)-1]+1)
			case ')':
				a = append(a, a[len(a)-1]-1)
			}
			b = append(b, min(b[len(b)-1], a[len(a)-1]))
		case 2:
			a = a[:len(a)-1]
			b = b[:len(b)-1]
		}
		if a[len(a)-1] == 0 && b[len(b)-1] == 0 {
			fmt.Fprintln(io.Out, "Yes")
		} else {
			fmt.Fprintln(io.Out, "No")
		}
	}
}
