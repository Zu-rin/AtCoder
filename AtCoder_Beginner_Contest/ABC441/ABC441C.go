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
	n, k, x := io.NextInt(), io.NextInt(), io.NextInt()
	d := make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = io.NextInt()
	}
	sort.Slice(d, func(i, j int) bool {
		return d[i] > d[j]
	})
	sum := 0
	for i := n - k; i < n; i++ {
		sum += d[i]
		if sum >= x {
			fmt.Println(i + 1)
			return
		}
	}
	fmt.Println(-1)
}
