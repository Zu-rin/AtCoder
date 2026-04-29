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
	n, s := io.NextInt(), io.Text()
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i] = io.NextInt()
	}
	a, b := make([]int, n+1), make([]int, n+1)
	for i := 0; i < n; i++ {
		if i&1 == int(s[i]-'0') {
			a[i+1] = a[i]
			b[i+1] = b[i] + c[i]
		} else {
			a[i+1] = a[i] + c[i]
			b[i+1] = b[i]
		}
	}
	ans := 1 << 60
	for i := 0; i < n-1; i++ {
		x, y := 0, 0
		if s[i] != '0' {
			x += c[i]
		} else {
			y += c[i]
		}
		if s[i+1] != '0' {
			x += c[i+1]
		} else {
			y += c[i+1]
		}
		if i == 0 {
			x += b[n] - b[i+1]
			y += a[n] - a[i+1]
		} else if i == n-2 {
			if i&1 == 0 {
				x += a[i]
				y += b[i]
			} else {
				x += b[i]
				y += a[i]
			}
		} else {
			if i&1 == 0 {
				x += a[i] + b[n] - b[i+2]
				y += b[i] + a[n] - a[i+2]
			} else {
				x += b[i] + a[n] - a[i+2]
				y += a[i] + b[n] - b[i+2]
			}
		}
		ans = min(ans, x, y)
	}
	fmt.Println(ans)
}
