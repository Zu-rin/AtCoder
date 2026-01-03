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

type snake struct {
	h, l int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	q := io.NextInt()
	d := []snake{{h: 0, l: 0}}
	offset := 0
	loss := 0
	for i := 0; i < q; i++ {
		k := io.NextInt()
		switch k {
		case 1:
			x := snake{h: d[len(d)-1].h + d[len(d)-1].l, l: io.NextInt()}
			d = append(d, x)
		case 2:
			offset++
			loss += d[offset].l
		case 3:
			n := io.NextInt()
			fmt.Println(d[n+offset].h - loss)
		}
	}
}
