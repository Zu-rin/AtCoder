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
	a := make([]int, n+1)
	b := make([]map[int]int, n+1)
	ans := 0
	for i := 1; i <= n; i++ {
		a[i] = i
		b[i] = map[int]int{i: 0}
	}
	for i := 0; i < q; i++ {
		k := io.NextInt()
		switch k {
		case 1:
			x, y := io.NextInt(), io.NextInt()
			delete(b[a[x]], x)
			if len(b[a[x]]) == 1 {
				ans--
			}
			a[x] = y
			b[y][x] = 0
			if len(b[y]) == 2 {
				ans++
			}
		case 2:
			fmt.Println(ans)
		}
	}
}
