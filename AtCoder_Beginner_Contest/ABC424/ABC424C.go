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

func search(ans []bool, x int, nx []map[int]bool) {
	if ans[x] {
		return
	}
	ans[x] = true
	for k := range nx[x] {
		search(ans, k, nx)
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	nx := make([]map[int]bool, n+1)
	for i := 0; i <= n; i++ {
		nx[i] = make(map[int]bool)
	}
	for i := 1; i <= n; i++ {
		a, b := io.NextInt(), io.NextInt()
		nx[a][i], nx[b][i] = true, true
	}
	get := make([]bool, n+1)
	search(get, 0, nx)
	ans := 0
	for i := 1; i <= n; i++ {
		if get[i] {
			ans++
		}
	}
	fmt.Fprintln(io.Out, ans)
}
