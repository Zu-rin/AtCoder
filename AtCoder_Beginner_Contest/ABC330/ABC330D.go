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
	a, b := make([]int, n), make([]int, n)
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = io.Text()
		for j := 0; j < n; j++ {
			if s[i][j] == 'o' {
				a[i]++
				b[j]++
			}
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		if a[i] > 1 {
			for j := 0; j < n; j++ {
				if s[i][j] == 'o' {
					ans += (a[i] - 1) * (b[j] - 1)
				}
			}
		}
	}
	fmt.Println(ans)
}
