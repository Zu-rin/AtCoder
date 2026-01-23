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

func check(n int, s string, a, b byte) int {
	x, y := make([]int, 0, n), make([]int, 0, n)
	for i := 0; i < len(s); i++ {
		if i&1 == 0 && s[i] == a {
			x = append(x, i)
		} else if i&1 == 1 && s[i] == b {
			y = append(y, i)
		}
	}
	ans := 0
	for i := 0; i < len(x); i++ {
		ans += abs(x[i] - y[i])
	}
	return ans
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, s := io.NextInt(), io.Text()
	ans := check(n, s, 'A', 'B')
	ans = min(ans, check(n, s, 'B', 'A'))
	fmt.Println(ans)
}
