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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

type ice struct {
	t, a int
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()

	n := io.NextInt()
	d := make([]ice, n)
	for i := 0; i < n; i++ {
		d[i] = ice{io.NextInt(), io.NextInt()}
	}
	sort.Slice(d, func(i, j int) bool {
		return d[i].a > d[j].a
	})
	ans := 0
	for i := 1; i < n; i++ {
		if d[i].t == d[0].t {
			ans = max(ans, d[i].a>>1)
		} else {
			ans = max(ans, d[i].a)
		}
	}
	fmt.Println(ans + d[0].a)
}
