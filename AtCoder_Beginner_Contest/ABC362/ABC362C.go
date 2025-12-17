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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

type pair struct {
	l, r int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	d := make([]pair, n)
	sum := 0
	for i := 0; i < n; i++ {
		d[i].l, d[i].r = io.NextInt(), io.NextInt()
		sum += d[i].l
	}
	for i := 0; i < n && sum < 0; i++ {
		x := min(d[i].r-d[i].l, -sum)
		d[i].l += x
		sum += x
	}
	if sum == 0 {
		fmt.Println("Yes")
		for i := 0; i < n-1; i++ {
			fmt.Printf("%d ", d[i].l)
		}
		fmt.Println(d[n-1].l)
	} else {
		fmt.Println("No")
	}
}
