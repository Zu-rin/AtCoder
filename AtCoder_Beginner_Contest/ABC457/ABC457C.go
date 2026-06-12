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
	n, k := io.NextInt(), io.NextInt()-1
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		l := io.NextInt()
		a[i] = make([]int, l)
		for j := 0; j < l; j++ {
			a[i][j] = io.NextInt()
		}
	}
	for i := 0; i < n; i++ {
		c := io.NextInt()
		if k >= len(a[i])*c {
			k -= len(a[i]) * c
			continue
		}
		fmt.Println(a[i][k%len(a[i])])
		break
	}
}
