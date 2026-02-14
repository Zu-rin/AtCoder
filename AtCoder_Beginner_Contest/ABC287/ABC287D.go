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

func mutch(a, b byte) bool {
	return a == '?' || b == '?' || a == b
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	s, t := io.Text(), io.Text()
	a, b := make([]bool, len(t)+1), make([]bool, len(t)+1)
	a[0], b[0] = true, true
	for i := 0; i < len(t); i++ {
		if mutch(s[i], t[i]) {
			a[i+1] = true
		} else {
			break
		}
	}
	for i := 0; i < len(t); i++ {
		if mutch(s[len(s)-1-i], t[len(t)-1-i]) {
			b[i+1] = true
		} else {
			break
		}
	}
	for i := 0; i <= len(t); i++ {
		if a[i] && b[len(t)-i] {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
