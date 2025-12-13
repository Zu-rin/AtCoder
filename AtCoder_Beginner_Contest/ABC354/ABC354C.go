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

type card struct {
	a, c, i int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	d := make([]card, n)
	for i := 0; i < n; i++ {
		d[i] = card{io.NextInt(), io.NextInt(), i + 1}
	}
	sort.Slice(d, func(i, j int) bool {
		return d[i].a > d[j].a
	})
	ans := []card{d[0]}
	maxC := d[0].c
	for i := 1; i < n; i++ {
		if d[i].c < maxC {
			ans = append(ans, d[i])
			maxC = d[i].c
		}
	}
	sort.Slice(ans, func(i, j int) bool {
		return ans[i].i < ans[j].i
	})
	fmt.Println(len(ans))
	for i := 0; i < len(ans)-1; i++ {
		fmt.Printf("%d ", ans[i].i)
	}
	fmt.Println(ans[len(ans)-1].i)
}
