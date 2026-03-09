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
	n, m, D := io.NextInt(), io.NextInt(), io.NextInt()
	a, b := make([]int, n), make([]int, m)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	for i := 0; i < m; i++ {
		b[i] = io.NextInt()
	}
	sort.Ints(a)
	sort.Ints(b)
	ans := -1
	for i := 0; i < n; i++ {
		j := binarySearch(b, a[i]+D)
		if j >= 0 && max(a[i], b[j])-min(a[i], b[j]) <= D {
			ans = max(ans, a[i]+b[j])
		}
		j = binarySearch(b, a[i]-D-1) + 1
		if j < m && max(a[i], b[j])-min(a[i], b[j]) <= D {
			ans = max(ans, a[i]+b[j])
		}
	}
	fmt.Println(ans)
}
