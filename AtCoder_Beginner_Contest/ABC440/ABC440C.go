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
	q := io.NextInt()
	for ; q > 0; q-- {
		n, w := io.NextInt(), io.NextInt()
		d := make([]int, n+1)
		ans := 1 << 60
		for i := 0; i < n; i++ {
			d[i+1] = io.NextInt() + d[i]
		}
		for i := 0; i < w*2; i++ {
			x := 0
			for j := i; j <= n+w; j += w << 1 {
				x += d[min(j, n)] - d[max(0, j-w)]
			}
			ans = min(ans, x)
		}
		fmt.Fprintln(io.Out, ans)
	}
}
