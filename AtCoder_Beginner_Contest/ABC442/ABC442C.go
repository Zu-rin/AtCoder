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

func comb3(n int) int {
	if n < 3 {
		return 0
	}
	v := n * (n - 1) * (n - 2) / 6
	return v
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	d := make([]int, n+1)
	for i := 0; i < m; i++ {
		a, b := io.NextInt(), io.NextInt()
		d[a]++
		d[b]++
	}
	for i := 1; i < n; i++ {
		ans := comb3(n - d[i] - 1)
		fmt.Fprint(io.Out, ans, " ")
	}
	ans := comb3(n - d[n] - 1)
	fmt.Fprintln(io.Out, ans)
}
