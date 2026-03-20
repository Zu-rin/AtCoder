package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
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

type pair struct {
	i int
	c byte
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	_, s, a := io.NextInt(), []byte(io.Text()), 0
	que := make([]pair, 0, len(s))
	for q := io.NextInt(); q > 0; q-- {
		k, x, c := io.NextInt(), io.NextInt(), io.Text()[0]
		if k == 1 {
			que = append(que, pair{x - 1, c})
		} else {
			if k == 2 {
				a = -1
			} else {
				a = 1
			}
			for _, p := range que {
				s[p.i] = p.c
			}
			que = que[:0]
		}
	}
	if a == -1 {
		s = []byte(strings.ToLower(string(s)))
	} else if a == 1 {
		s = []byte(strings.ToUpper(string(s)))
	}
	for _, p := range que {
		s[p.i] = p.c
	}
	fmt.Fprintln(io.Out, string(s))
}
