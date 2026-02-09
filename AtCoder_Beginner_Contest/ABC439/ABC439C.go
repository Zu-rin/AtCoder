package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
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
	d := make(map[int]int, n)
	for i := 1; i*i < n; i++ {
		for j := i + 1; i*i+j*j <= n; j++ {
			d[i*i+j*j]++
		}
	}
	a := make([]int, 0, len(d))
	for k, v := range d {
		if v == 1 {
			a = append(a, k)
		}
	}
	sort.Ints(a)
	fmt.Fprintln(io.Out, len(a))
	for i := 0; i < len(a)-1; i++ {
		fmt.Fprint(io.Out, a[i], " ")
	}
	if len(a) > 0 {
		fmt.Fprintln(io.Out, a[len(a)-1])
	} else {
		fmt.Fprintln(io.Out)
	}
}
