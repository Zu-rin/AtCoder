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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

type result struct {
	i      int
	a, sum int64
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	res := make([]result, n)
	for i := 0; i < n; i++ {
		a, b := io.NextInt64(), io.NextInt64()
		res[i] = result{i: i + 1, a: a, sum: a + b}
	}
	sort.Slice(res, func(i, j int) bool {
		x, y := res[i].a*res[j].sum, res[j].a*res[i].sum
		if x == y {
			return res[i].i <= res[j].i
		}
		return x >= y
	})
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", res[i].i)
	}
	fmt.Println(res[n-1].i)
}
