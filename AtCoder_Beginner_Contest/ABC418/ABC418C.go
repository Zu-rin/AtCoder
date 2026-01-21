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
	n, q := io.NextInt(), io.NextInt()
	a := make([]int, n)
	d := make([]int, n+1)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	sort.Ints(a)
	for i := 0; i < n; i++ {
		d[i+1] = d[i] + a[i]
	}
	for i := 0; i < q; i++ {
		b := io.NextInt()
		if a[n-1] < b {
			fmt.Println(-1)
			continue
		}
		c := binarySearch(a, b-1)
		ans := d[c+1] + (b-1)*(n-c-1) + 1
		fmt.Println(ans)
	}
}
