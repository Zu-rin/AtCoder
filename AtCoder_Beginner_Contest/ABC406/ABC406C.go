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
	a := make([]int, n)
	d := make([]int, 0, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	d = append(d, 0)
	for i := 1; i < n-1; i++ {
		if a[i-1] < a[i] && a[i] > a[i+1] {
			d = append(d, i)
		} else if a[i-1] > a[i] && a[i] < a[i+1] {
			d = append(d, i)
		}
	}
	d = append(d, n-1)
	ans := 0
	for i := 1; i < len(d)-2; i++ {
		if a[d[i]] > a[d[i+1]] {
			ans += (d[i] - d[i-1]) * (d[i+2] - d[i+1])
		}
	}
	fmt.Println(ans)
}
