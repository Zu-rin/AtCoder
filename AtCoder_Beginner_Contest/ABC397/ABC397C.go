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
	d := make([]int, n)
	a, b := make(map[int]int), make(map[int]int)
	for i := 0; i < n; i++ {
		d[i] = io.NextInt()
		a[d[i]]++
	}
	ans := len(a)
	for i := 0; i < n; i++ {
		b[d[i]]++
		if a[d[i]] > 1 {
			a[d[i]]--
		} else {
			delete(a, d[i])
		}
		ans = max(ans, len(a)+len(b))
	}
	fmt.Println(ans)
}
