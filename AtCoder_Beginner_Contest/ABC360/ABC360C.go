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

type box struct {
	sum, ma int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	d := make(map[int]box, n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	for i := 0; i < n; i++ {
		w := io.NextInt()
		if b, ok := d[a[i]]; ok {
			b.sum += w
			b.ma = max(b.ma, w)
			d[a[i]] = b
		} else {
			d[a[i]] = box{w, w}
		}
	}
	ans := 0
	for _, v := range d {
		ans += v.sum - v.ma
	}
	fmt.Println(ans)
}
