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
	c, x int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	q := io.NextInt()
	d := []pair{}
	for i := 0; i < q; i++ {
		k, c := io.NextInt(), io.NextInt()
		switch k {
		case 1:
			x := io.NextInt()
			d = append(d, pair{c, x})
		case 2:
			ans := 0
			for c > 0 {
				ans += min(c, d[0].c) * d[0].x
				if c < d[0].c {
					d[0].c -= c
					c = 0
				} else {
					c -= d[0].c
					d = d[1:]
				}
			}
			fmt.Println(ans)
		}
	}
}
