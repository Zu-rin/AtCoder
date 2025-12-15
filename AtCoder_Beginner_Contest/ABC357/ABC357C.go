package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
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

func proc(s [][]byte, lv, y, x int) {
	if lv == 0 {
		s[y][x] = '#'
		return
	}
	h := int(math.Pow(3, float64(lv)))
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if i == 1 && j == 1 {
				for yy := y + h/3; yy < y+2*h/3; yy++ {
					for xx := x + h/3; xx < x+2*h/3; xx++ {
						s[yy][xx] = '.'
					}
				}
				continue
			}
			proc(s, lv-1, y+i*h/3, x+j*h/3)
		}
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	h := int(math.Pow(3, float64(n)))
	s := make([][]byte, h)
	for i := range s {
		s[i] = make([]byte, h)
	}
	proc(s, n, 0, 0)
	for i := range s {
		fmt.Println(string(s[i]))
	}
}
