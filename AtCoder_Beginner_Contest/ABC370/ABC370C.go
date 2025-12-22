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
	s, t := []byte(io.Text()), io.Text()
	ans := make([]string, 0, len(s))
	for i := 0; i < len(s); i++ {
		if s[i] > t[i] {
			s[i] = t[i]
			ans = append(ans, string(s))
		}
	}
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] < t[i] {
			s[i] = t[i]
			ans = append(ans, string(s))
		}
	}
	fmt.Println(len(ans))
	for _, v := range ans {
		fmt.Println(v)
	}
}
