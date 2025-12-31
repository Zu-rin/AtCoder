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
	d := make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = io.NextInt()
	}
	ans := 1
	for k := 1; k < n; k++ {
		for s := 0; s < k; s++ {
			x := 1
			for i := s; i < n-k; i += k {
				j := i + k
				if d[i] == d[j] {
					x++
					ans = max(ans, x)
				} else {
					x = 1
				}
			}
		}
	}
	fmt.Println(ans)
}
