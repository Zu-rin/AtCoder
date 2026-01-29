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

func check(x, n int, nx []map[int]bool) int {
	cnt := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if (x>>i)&1 == (x>>j)&1 && nx[i+1][j+1] {
				cnt++
			}
		}
	}
	return cnt
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	nx := make([]map[int]bool, n+1)
	for i := 0; i <= n; i++ {
		nx[i] = make(map[int]bool)
	}
	for i := 0; i < m; i++ {
		a, b := io.NextInt(), io.NextInt()
		nx[min(a, b)][max(a, b)] = true
	}
	ans := m
	for i := 0; i < (1 << n); i++ {
		ans = min(ans, check(i, n, nx))
	}
	fmt.Println(ans)
}
