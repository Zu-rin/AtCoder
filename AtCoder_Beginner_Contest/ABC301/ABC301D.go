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
	s, n := io.Text(), io.NextInt()
	a := 0
	d := []int{}
	for i, c := range s {
		if c == '1' {
			a |= 1 << (len(s) - 1 - i)
		} else if c == '?' {
			d = append(d, len(s)-1-i)
		}
	}
	if a > n {
		fmt.Println(-1)
		return
	}
	for _, x := range d {
		if a|(1<<x) <= n {
			a |= 1 << x
		}
	}
	fmt.Println(a)
}
