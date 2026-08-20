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

type adb struct {
	a, d, b int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	a := make([]adb, n)
	for i := 0; i < n; i++ {
		a[i] = adb{io.NextInt(), io.NextInt(), io.NextInt()}
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].d < a[j].d
	})
	d := make(map[int]int, n)
	for i := 0; i < n; i++ {
		d[a[i].a]++
	}
	for i, k := 1, 0; i <= m; i++ {
		for k < n && a[k].d == i {
			d[a[k].a]--
			d[a[k].b]++
			if d[a[k].a] == 0 {
				delete(d, a[k].a)
			}
			k++
		}
		fmt.Fprintln(io.Out, len(d))
	}
}
