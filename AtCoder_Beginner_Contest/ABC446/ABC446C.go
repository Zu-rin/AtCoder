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
	for q := io.NextInt(); q > 0; q-- {
		n, D := io.NextInt(), io.NextInt()
		d := make([]int, 0, n)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = io.NextInt()
		}
		for i := 0; i < n; i++ {
			b := io.NextInt()
			d = append(d, a[i])
			for b > 0 {
				x := min(d[0], b)
				d[0] -= x
				b -= x
				if d[0] == 0 {
					d = d[1:]
				}
			}
			if len(d) > D {
				d = d[1:]
			}
		}
		ans := 0
		for _, v := range d {
			ans += v
		}
		fmt.Fprintln(io.Out, ans)
	}
}
