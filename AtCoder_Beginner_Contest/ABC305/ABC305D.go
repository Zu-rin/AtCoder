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

func binarySearch(d []int, tag int) int {
	if tag < d[0] {
		return -1
	}
	l, r := 0, len(d)
	for l+1 < r {
		p := (l + r) >> 1
		if d[p] <= tag {
			l = p
		} else {
			r = p
		}
	}
	return l
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	a, d := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	for i := 1; i < n; i += 2 {
		d[i+1] = a[i+1] - a[i]
	}
	for i := 0; i < n-1; i++ {
		d[i+1] += d[i]
	}
	for q := io.NextInt(); q > 0; q-- {
		l, r := io.NextInt(), io.NextInt()
		x, y := binarySearch(a, l), binarySearch(a, r)
		ans := d[y] - d[x]
		if x&1 == 1 {
			ans -= l - a[x]
		}
		if y&1 == 1 {
			ans += r - a[y]
		}
		fmt.Println(ans)
	}
}
