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
	x byte
	n int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	s := io.Text()
	d := make([]pair, 0)
	p := pair{s[0], 1}
	for i := 1; i < len(s); i++ {
		if s[i] == p.x {
			p.n++
		} else {
			d = append(d, p)
			p = pair{s[i], 1}
		}
	}
	d = append(d, p)
	ans := 0
	for i := 0; i < len(d)-1; i++ {
		if d[i].x+1 == d[i+1].x {
			ans += min(d[i].n, d[i+1].n)
		}
	}
	fmt.Println(ans)
}
