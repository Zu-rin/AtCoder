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
	n, l := io.NextInt(), io.NextInt()
	d := make(map[int]int, n)
	d[0] = 1
	for i, p := 0, 0; i < n-1; i++ {
		p += io.NextInt()
		d[p%l]++
	}
	if l%3 != 0 {
		fmt.Println(0)
		return
	}
	ans := 0
	l /= 3
	for i := 0; i < l; i++ {
		ans += d[i] * d[i+l] * d[i+2*l]
	}
	fmt.Println(ans)
}
