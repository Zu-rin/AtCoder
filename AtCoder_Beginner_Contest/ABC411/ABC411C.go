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
	d := make([]bool, n+2)
	ans := 0
	for i := 0; i < q; i++ {
		a := io.NextInt()
		if d[a-1] && d[a+1] {
			if d[a] {
				ans++
			} else {
				ans--
			}
		} else if !d[a-1] && !d[a+1] {
			if d[a] {
				ans--
			} else {
				ans++
			}
		}
		d[a] = !d[a]
		fmt.Println(ans)
	}
}
