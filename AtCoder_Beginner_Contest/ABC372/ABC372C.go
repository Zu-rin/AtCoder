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
	n, q := io.NextInt(), io.NextInt()
	s := []byte(io.Text())
	ans := 0
	for i := 0; i < n-2; i++ {
		if string(s[i:i+3]) == "ABC" {
			ans++
		}
	}
	for i := 0; i < q; i++ {
		x, c := io.NextInt()-1, io.Text()[0]
		switch s[x] {
		case 'A':
			if x+2 < n && string(s[x:x+3]) == "ABC" {
				ans--
			}
		case 'B':
			if x-1 >= 0 && x+1 < n && string(s[x-1:x+2]) == "ABC" {
				ans--
			}
		case 'C':
			if x-2 >= 0 && string(s[x-2:x+1]) == "ABC" {
				ans--
			}
		}
		s[x] = c
		switch s[x] {
		case 'A':
			if x+2 < n && string(s[x:x+3]) == "ABC" {
				ans++
			}
		case 'B':
			if x-1 >= 0 && x+1 < n && string(s[x-1:x+2]) == "ABC" {
				ans++
			}
		case 'C':
			if x-2 >= 0 && string(s[x-2:x+1]) == "ABC" {
				ans++
			}
		}
		fmt.Println(ans)
	}
}
