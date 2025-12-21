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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	ans := n
	l := 0
	for l < n-1 {
		k := a[l+1] - a[l]
		for d := 1; l+d < n; d++ {
			if a[l+d]-a[l+d-1] != k {
				ans += d * (d - 1) / 2
				l += d - 1
				break
			}
			if l+d == n-1 {
				ans += d * (d + 1) / 2
				l = n
				break
			}
		}
	}
	fmt.Println(ans)
}
