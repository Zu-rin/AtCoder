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
	a := make([]int, 0)
	ans := make([]byte, 0)
	for i := 0; i < n; i++ {
		switch s[i] {
		case '(':
			a = append(a, len(ans))
			ans = append(ans, '(')
		case ')':
			if len(a) > 0 {
				ans = ans[:a[len(a)-1]]
				a = a[:len(a)-1]
			} else {
				ans = append(ans, ')')
			}
		default:
			ans = append(ans, s[i])
		}
	}
	fmt.Println(string(ans))
}
