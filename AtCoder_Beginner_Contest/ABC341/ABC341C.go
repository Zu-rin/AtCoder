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
	h, w, n := io.NextInt(), io.NextInt(), io.NextInt()
	s := io.Text()
	d := make([]string, h)
	for i := 0; i < h; i++ {
		d[i] = io.Text()
	}
	ans := 0
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if d[i][j] == '#' {
				continue
			}
			a, b := i, j
			ok := true
			for k := 0; k < n; k++ {
				switch s[k] {
				case 'U':
					a--
				case 'D':
					a++
				case 'L':
					b--
				case 'R':
					b++
				}
				if a < 0 || a >= h || b < 0 || b >= w || d[a][b] == '#' {
					ok = false
					break
				}
			}
			if ok {
				ans++
			}
		}
	}
	fmt.Println(ans)
}
