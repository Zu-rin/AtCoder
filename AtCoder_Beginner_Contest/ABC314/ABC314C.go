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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

type cpos struct {
	pos int
	c   rune
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	s := io.Text()
	d := make([][]cpos, m)
	for i := 0; i < n; i++ {
		x := io.NextInt() - 1
		d[x] = append(d[x], cpos{pos: i, c: rune(s[i])})
	}
	for i := 0; i < m; i++ {
		buf := cpos{pos: d[i][0].pos, c: d[i][len(d[i])-1].c}
		for j := 0; j < len(d[i])-1; j++ {
			d[i][j].pos = d[i][j+1].pos
		}
		d[i][len(d[i])-1] = buf
	}
	ans := make([]rune, n)
	for i := 0; i < m; i++ {
		for j := 0; j < len(d[i]); j++ {
			ans[d[i][j].pos] = d[i][j].c
		}
	}
	fmt.Println(string(ans))
}
