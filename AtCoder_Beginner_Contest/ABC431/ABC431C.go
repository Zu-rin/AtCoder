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
	n, m, k := io.NextInt(), io.NextInt(), io.NextInt()
	a, b := make([]int, n), make([]int, m)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	for i := 0; i < m; i++ {
		b[i] = io.NextInt()
	}
	sort.Ints(a)
	sort.Ints(b)
	a, b = a[:k], b[m-k:]
	for i := 0; i < k; i++ {
		if a[i] > b[i] {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}
