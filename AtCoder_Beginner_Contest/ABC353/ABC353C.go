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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, k := io.NextInt(), int64(100000000)
	a := make([]int64, n)
	ans := int64(0)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt64()
		ans += a[i] * int64(n-1)
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
	l := n - 1
	for i := 0; i < n; i++ {
		for l > i && a[i]+a[l] < k {
			l--
		}
		if i < l {
			ans -= k * int64(l-i)
		}
	}
	fmt.Println(ans)
}
