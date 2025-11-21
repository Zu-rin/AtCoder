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

func min(a, b int64) int64 {
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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()

	n, t, c := io.NextInt(), io.NextInt64(), io.NextInt64()
	d := make([]int64, n)
	for i := 0; i < n; i++ {
		d[i] = io.NextInt64()
	}
	sort.Slice(d, func(i, j int) bool {
		return d[i] > d[j]
	})
	for i := n - 2; i >= 0; i-- {
		d[i] += d[i+1]
	}
	k := int64(n) / t
	if n%int(t) != 0 {
		k++
	}
	ans := c * k
	for k := int64(0); k*t < int64(n); k++ {
		cost := k * c
		cost += d[k*t]
		ans = min(ans, cost)
	}
	fmt.Println(ans)
}
