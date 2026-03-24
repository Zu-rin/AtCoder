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

type pos struct {
	k, x, y int
}

func search(ans []pos, d map[int][]pos, ok []bool, x int) {
	if ok[x] {
		return
	}
	ok[x] = true
	for _, v := range d[x] {
		if ans[v.k].k == 0 {
			ans[v.k] = pos{1, ans[x].x + v.x, ans[x].y + v.y}
		}
		search(ans, d, ok, v.k)
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	ans, d, vis := make([]pos, n+1), make(map[int][]pos, m), make([]bool, n+1)
	ans[1] = pos{1, 0, 0}
	for i := 0; i < m; i++ {
		a, b, x, y := io.NextInt(), io.NextInt(), io.NextInt(), io.NextInt()
		d[a] = append(d[a], pos{b, x, y})
		d[b] = append(d[b], pos{a, -x, -y})
	}
	search(ans, d, vis, 1)
	for i := 1; i <= n; i++ {
		if vis[i] {
			fmt.Fprintln(io.Out, ans[i].x, ans[i].y)
		} else {
			fmt.Fprintln(io.Out, "undecidable")
		}
	}
}
