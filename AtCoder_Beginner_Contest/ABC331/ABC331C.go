package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

type data struct {
	v, i int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	a, ans := make([]data, n), make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = data{v: io.NextInt(), i: i}
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].v > a[j].v
	})
	sum := a[0].v
	for i := 1; i < n; i++ {
		if a[i].v == a[i-1].v {
			ans[a[i].i] = ans[a[i-1].i]
		} else {
			ans[a[i].i] = sum
		}
		sum += a[i].v
	}
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Println(ans[n-1])
}
