package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
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
	n, x, y := io.NextInt(), io.NextInt(), io.NextInt()
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	for i := 0; i < n; i++ {
		b[i] = io.NextInt()
	}
	sort.Ints(a)
	sort.Ints(b)
	for ans := 1; ans <= n; ans++ {
		if a[n-ans] > x || b[n-ans] > y {
			fmt.Println(ans)
			return
		}
		x -= a[n-ans]
		y -= b[n-ans]
	}
	fmt.Println(n)
}
