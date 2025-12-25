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
	a := make([][]byte, n)
	b := make([][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = []byte(io.Text())
		b[i] = make([]byte, n)
	}
	for i := 0; i < n>>1; i++ {
		l, r := i, n-1-i
		for j := l; j <= r; j++ {
			switch i % 4 {
			case 0:
				b[l][j] = a[n-1-j][l]
				b[r][j] = a[n-1-j][r]
				b[j][l] = a[r][j]
				b[j][r] = a[l][j]
			case 1:
				b[l][j] = a[r][n-1-j]
				b[r][j] = a[l][n-1-j]
				b[j][l] = a[n-1-j][r]
				b[j][r] = a[n-1-j][l]
			case 2:
				b[l][j] = a[j][r]
				b[r][j] = a[j][l]
				b[j][l] = a[l][n-1-j]
				b[j][r] = a[r][n-1-j]
			case 3:
				b[l][j] = a[l][j]
				b[r][j] = a[r][j]
				b[j][l] = a[j][l]
				b[j][r] = a[j][r]
			}
		}
	}
	for _, ans := range b {
		fmt.Println(string(ans))
	}
}
