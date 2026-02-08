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

type pair struct {
	x, n int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	d := make([]pair, 1, n)
	d[0] = pair{0, 0}
	ans := n
	for i := 0; i < n; i++ {
		x := io.NextInt()
		if d[len(d)-1].x == x {
			d[len(d)-1].n++
			if d[len(d)-1].n == 4 {
				d = d[:len(d)-1]
				ans -= 4
			}
		} else {
			d = append(d, pair{x, 1})
		}
	}
	fmt.Println(ans)
}
