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
	n, l, r := io.NextInt(), io.NextInt(), io.NextInt()
	d, a, b := make([]int, n), make([]int, n+1), make([]int, n+1)
	ans := 0
	for i := 0; i < n; i++ {
		d[i] = io.NextInt()
		ans += d[i]
		a[i+1] = a[i] + l - d[i]
	}
	for i := n - 1; i >= 0; i-- {
		b[i] = b[i+1] + r - d[i]
	}
	mia, mib := 1<<60, 1<<60
	for i := 0; i <= n; i++ {
		mia = min(mia, a[i])
		a[i] = mia
	}
	for i := n; i >= 0; i-- {
		mib = min(mib, b[i])
		b[i] = mib
	}
	mi := 1 << 60
	for i := 0; i <= n; i++ {
		mi = min(mi, a[i]+b[i])
	}
	fmt.Println(ans + mi)
}
