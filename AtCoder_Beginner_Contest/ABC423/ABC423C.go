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
	n, r := io.NextInt(), io.NextInt()
	l := make([]int, n)
	o := 0
	for i := 0; i < n; i++ {
		l[i] = io.NextInt()
		if l[i] == 0 {
			o++
		}
	}
	a, b := n, 0
	for i := 0; i < n; i++ {
		if l[i] == 0 {
			a = i
			break
		}
	}
	for i := n - 1; i >= 0; i-- {
		if l[i] == 0 {
			b = i
			break
		}
	}
	k := 0
	if a <= r-1 {
		for i := a + 1; i < r; i++ {
			if l[i] == 1 {
				k++
			}
		}
	}
	if b >= r {
		for i := r; i < b; i++ {
			if l[i] == 1 {
				k++
			}
		}
	}
	fmt.Println(2*k + o)
}
