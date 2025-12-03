package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
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
	n := io.NextInt()
	d, a, b := make([]int, n), make([]int, n), make([]int, n)
	x := 1 << 30
	for i := 0; i < n; i++ {
		d[i] = io.NextInt()
	}
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
		if a[i] > 0 {
			x = min(x, d[i]/a[i])
		}
	}
	for i := 0; i < n; i++ {
		b[i] = io.NextInt()
	}
	ans := 0
	for x >= 0 {
		y := 1 << 30
		for i := 0; i < n; i++ {
			if b[i] > 0 {
				y = min(y, (d[i]-a[i]*x)/b[i])
			}
		}
		ans = max(ans, x+y)
		x--
	}
	fmt.Println(ans)
}
