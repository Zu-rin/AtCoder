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
	h, w, k := io.NextInt(), io.NextInt(), io.NextInt()
	s := make([]string, h)
	ans := 1 << 60
	for i := 0; i < h; i++ {
		s[i] = io.Text()
		q := make([]byte, 0, w)
		a := 0
		for j := 0; j < w; j++ {
			if s[i][j] == 'x' {
				q, a = make([]byte, 0, w), 0
			} else {
				q = append(q, s[i][j])
				if s[i][j] == '.' {
					a++
				}
				if len(q) == k {
					ans = min(ans, a)
					if q[0] == '.' {
						a--
					}
					q = q[1:]
				}
			}
		}
	}
	for j := 0; j < w; j++ {
		q := make([]byte, 0, h)
		a := 0
		for i := 0; i < h; i++ {
			if s[i][j] == 'x' {
				q, a = make([]byte, 0, h), 0
			} else {
				q = append(q, s[i][j])
				if s[i][j] == '.' {
					a++
				}
				if len(q) == k {
					ans = min(ans, a)
					if q[0] == '.' {
						a--
					}
					q = q[1:]
				}
			}
		}
	}
	if ans == 1<<60 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}
