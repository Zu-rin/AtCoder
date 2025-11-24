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
	a, d := make([]int, m), make([]int, n)
	s := make([]string, n)
	for i := 0; i < m; i++ {
		a[i] = io.NextInt()
	}
	top := 0
	for i := 0; i < n; i++ {
		s[i] = io.Text()
		d[i] = i + 1
		for j := 0; j < m; j++ {
			if s[i][j] == 'o' {
				d[i] += a[j]
			}
		}
		top = max(top, d[i])
	}
	for i := 0; i < n; i++ {
		if d[i] == top {
			fmt.Println(0)
			continue
		}
		q := make([]int, 0, m)
		for j := 0; j < m; j++ {
			if s[i][j] == 'x' {
				q = append(q, a[j])
			}
		}
		sort.Sort(sort.Reverse(sort.IntSlice(q)))
		ans := 0
		for d[i] < top {
			d[i] += q[ans]
			ans++
		}
		fmt.Println(ans)
	}
}
