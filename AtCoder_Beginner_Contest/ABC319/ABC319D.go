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

func judge(a []int, m, w int) bool {
	x := w
	for _, v := range a {
		if w < v {
			return false
		}
		if x < v {
			m--
			if m <= 0 {
				return false
			}
			x = w - v - 1
		} else {
			x -= v + 1
		}
	}
	return true
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	a := make([]int, n)
	for i := range a {
		a[i] = io.NextInt()
	}
	l, r := 0, 1<<60
	for l+1 < r {
		p := (l + r) >> 1
		if judge(a, m, p) {
			r = p
		} else {
			l = p
		}
	}
	fmt.Println(r)
}
