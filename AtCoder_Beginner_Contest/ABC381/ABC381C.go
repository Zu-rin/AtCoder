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
	n, s := io.NextInt(), io.Text()
	ans := 0
	for i := 0; i < n; i++ {
		if s[i] == '/' {
			for j := 1; ; j++ {
				if i-j >= 0 && i+j < n && s[i-j] == '1' && s[i+j] == '2' {
					continue
				}
				ans = max(ans, j<<1-1)
				break
			}
		}
	}
	fmt.Println(ans)
}
