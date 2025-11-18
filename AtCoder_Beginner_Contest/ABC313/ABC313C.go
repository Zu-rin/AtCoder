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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	a := make([]int64, n)
	ave, ans := int64(0), int64(0)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt64()
		ave += a[i]
	}
	ave /= int64(n)
	x, y := int64(0), int64(0)
	for i := 0; i < n; i++ {
		if a[i] < ave {
			x += ave - a[i]
		} else if a[i] > ave+1 {
			y += a[i] - (ave + 1)
		}
	}
	ans = max(x, y)
	fmt.Println(ans)
}
