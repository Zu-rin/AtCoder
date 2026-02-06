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
	i, j int
}

func check(d map[pos]bool, p pos) bool {
	for i := 0; i <= 1; i++ {
		for j := 0; j <= 1; j++ {
			if d[pos{p.i + i, p.j + j}] {
				return false
			}
		}
	}
	return true
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	_, m := io.NextInt(), io.NextInt()
	d := make(map[pos]bool, m<<2)
	ans := 0
	for i := 0; i < m; i++ {
		x, y := io.NextInt(), io.NextInt()
		if check(d, pos{x, y}) {
			for ii := 0; ii <= 1; ii++ {
				for jj := 0; jj <= 1; jj++ {
					d[pos{x + ii, y + jj}] = true
				}
			}
			ans++
		}
	}
	fmt.Println(ans)
}
