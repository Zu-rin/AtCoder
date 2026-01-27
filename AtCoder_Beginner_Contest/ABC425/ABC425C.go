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
	n, q := io.NextInt(), io.NextInt()
	d := make([]int, n+1)
	for i := 1; i <= n; i++ {
		d[i] = io.NextInt() + d[i-1]
	}
	x := 0
	for i := 0; i < q; i++ {
		k, l := io.NextInt(), io.NextInt()
		switch k {
		case 1:
			x += l
		case 2:
			l--
			r := io.NextInt() - 1
			l, r = (l+x)%n, (r+x)%n
			ans := 0
			if l > r {
				l, r = r, l
				ans = d[n] - (d[r] - d[l+1])
			} else {
				ans = d[r+1] - d[l]
			}
			fmt.Fprintln(io.Out, ans)
		}
	}
}
