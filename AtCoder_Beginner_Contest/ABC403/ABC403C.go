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
	n, _, q := io.NextInt(), io.NextInt(), io.NextInt()
	d := make([]map[int]bool, n+1)
	for i := 1; i <= n; i++ {
		d[i] = make(map[int]bool)
	}
	for i := 0; i < q; i++ {
		k := io.NextInt()
		switch k {
		case 1:
			a, b := io.NextInt(), io.NextInt()
			d[a][b] = true
		case 2:
			a := io.NextInt()
			d[a][0] = true
		case 3:
			a, b := io.NextInt(), io.NextInt()
			if d[a][b] || d[a][0] {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
		}
	}
}
