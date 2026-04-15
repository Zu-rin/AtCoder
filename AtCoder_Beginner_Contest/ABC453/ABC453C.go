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
	d := make([]map[int]int, n+1)
	for i := 0; i <= n; i++ {
		d[i] = make(map[int]int)
	}
	d[0][0] = 0
	for i := 0; i < n; i++ {
		x := io.NextInt()
		for k, v := range d[i] {
			if k >= 0 {
				d[i+1][k+x] = max(d[i+1][k+x], v)
				d[i+1][k-x] = max(d[i+1][k-x], v)
				if k-x < 0 {
					d[i+1][k-x]++
				}
			} else {
				d[i+1][k+x] = max(d[i+1][k+x], v)
				d[i+1][k-x] = max(d[i+1][k-x], v)
				if k+x >= 0 {
					d[i+1][k+x]++
				}
			}
		}
	}
	ans := 0
	for _, v := range d[n] {
		ans = max(ans, v)
	}
	fmt.Fprintln(io.Out, ans)
}
