package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	s := make([]string, 3)
	for i := 0; i < 3; i++ {
		s[i] = io.Text()
	}
	ans := 1 << 30

	for i := 0; i < 3*n; i++ {
		for j := 0; j < 3*n; j++ {
			for k := 0; k < 3*n; k++ {
				if i != j && j != k && k != i && s[0][i%n] == s[1][j%n] && s[1][j%n] == s[2][k%n] {
					ans = min(ans, max(i, max(j, k)))
				}
			}
		}
	}
	if ans != 1<<30 {
		fmt.Println(ans)
	} else {
		fmt.Println(-1)
	}
}
