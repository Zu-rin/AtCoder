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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	l, r := 0, int(1e9)
	for l+1 < r {
		p := (l + r) >> 1
		if (p*p)<<1 <= n {
			l = p
		} else {
			r = p
		}
	}
	ans := l
	l, r = 0, int(1e9)
	for l+1 < r {
		p := (l + r) >> 1
		if (p*p)<<2 <= n {
			l = p
		} else {
			r = p
		}
	}
	ans += l
	fmt.Println(ans)
}
