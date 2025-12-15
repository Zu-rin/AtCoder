package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	d := make([]int, n)
	for i := 0; i < n; i++ {
		s := io.Text()
		for j := 0; j < m; j++ {
			if s[j] == 'o' {
				d[i] |= 1 << j
			}
		}
	}
	ans := n
	for i := 1; i < 1<<n; i++ {
		a, cnt := 0, 0
		for j := 0; j < n; j++ {
			if i&(1<<j) > 0 {
				cnt++
				a |= d[j]
			}
		}
		if a == (1<<m)-1 {
			ans = min(ans, cnt)
		}
	}
	fmt.Println(ans)
}
