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
	n, m := io.NextInt(), io.NextInt()
	a := make([]int, n)
	b := make([]int, m)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	for i := 0; i < m; i++ {
		b[i] = io.NextInt()
	}
	sort.Ints(a)
	sort.Ints(b)
	ans, sum := 0, 0
	for i := 0; i < n; i++ {
		if a[i] > 0 {
			sum += a[i]
			ans = sum
		}
	}
	if sum > 0 {
		a[n-1] = sum
	}
	for i := n - 2; i >= 0; i-- {
		a[i] = min(0, a[i])
	}
	sum = 0
	for i := 1; i <= min(n, m); i++ {
		sum += a[n-i] + b[m-i]
		ans = max(ans, sum)
	}
	fmt.Println(ans)
}
