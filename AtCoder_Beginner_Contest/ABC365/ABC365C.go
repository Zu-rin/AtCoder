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

func check(a []int, n, m, k int) bool {
	sum := 0
	for i := 0; i < n; i++ {
		sum += min(a[i], k)
	}
	return sum <= m
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	a := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
		sum += a[i]
	}
	if sum <= m {
		fmt.Println("infinite")
		return
	}
	l, r := 0, sum
	for l+1 < r {
		p := (l + r) / 2
		if check(a, n, m, p) {
			l = p
		} else {
			r = p
		}
	}
	fmt.Println(l)
}
