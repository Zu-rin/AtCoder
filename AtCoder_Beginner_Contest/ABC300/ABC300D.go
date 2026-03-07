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
	n := io.NextInt()
	a := make([]bool, 300001)
	p := make([]int, 0)
	for i, _ := range a {
		a[i] = true
	}
	for i := 2; i <= 300000; i++ {
		if a[i] {
			p = append(p, i)
			for j := i << 1; j <= 300000; j += i {
				a[j] = false
			}
		}
	}
	ans := 0
	for b, _ := range p {
		c := len(p) - 1
		for a := 0; a < b; a++ {
			for ; b < c; c-- {
				if p[a]*p[a]*p[b]*p[c]*p[c] <= n {
					ans += c - b
					break
				}
			}
		}
	}
	fmt.Println(ans)
}
