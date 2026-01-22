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
	x, y int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	ma, mi := pos{0, 0}, pos{1 << 60, 1 << 60}
	for i := 0; i < n; i++ {
		x, y := io.NextInt(), io.NextInt()
		ma.x = max(ma.x, x)
		ma.y = max(ma.y, y)
		mi.x = min(mi.x, x)
		mi.y = min(mi.y, y)
	}
	ans := (max(ma.x-mi.x, ma.y-mi.y) + 1) >> 1
	fmt.Println(ans)
}
