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

func search(s []string, d *[]string, a string, n, k int) {
	if n == k {
		*d = append(*d, a)
		return
	}
	for i := 0; i < len(s); i++ {
		search(s, d, a+s[i], n+1, k)
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, k, x := io.NextInt(), io.NextInt(), io.NextInt()
	s := make([]string, n)
	d := make([]string, 0, 100000)
	for i := 0; i < n; i++ {
		s[i] = io.Text()
	}
	search(s, &d, "", 0, k)
	sort.Slice(d, func(i, j int) bool {
		return d[i] < d[j]
	})
	fmt.Println(d[x-1])
}
