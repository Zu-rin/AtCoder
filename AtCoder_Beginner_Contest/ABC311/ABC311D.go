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

type pair struct {
	i, j int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = io.Text()
	}
	a, ans := make(map[pair]bool, n*m), make(map[pair]bool, n*m)
	x := pair{1, 1}
	q := []pair{x}
	for len(q) > 0 {
		x, q = q[0], q[1:]
		if a[x] {
			continue
		}
		a[x], ans[x] = true, true
		for _, d := range []pair{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} {
			for i := 1; i < max(n, m); i++ {
				y := pair{x.i + d.i*i, x.j + d.j*i}
				if s[y.i][y.j] == '#' {
					q = append(q, pair{y.i - d.i, y.j - d.j})
					break
				}
				ans[y] = true
			}
		}
	}
	fmt.Println(len(ans))
}
