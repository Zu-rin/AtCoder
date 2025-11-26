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
	d := [9][9]int{}
	ok := true
	k := (1 << 10) - 2
	for i := 0; i < 9; i++ {
		a := 0
		for j := 0; j < 9; j++ {
			d[i][j] = io.NextInt()
			a |= 1 << d[i][j]
		}
		if a != k {
			ok = false
		}
	}
	for j := 0; j < 9; j++ {
		a := 0
		for i := 0; i < 9; i++ {
			a |= 1 << d[i][j]
		}
		if a != k {
			ok = false
		}
	}
	for bi := 0; bi < 3; bi++ {
		for bj := 0; bj < 3; bj++ {
			a := 0
			for i := 0; i < 3; i++ {
				for j := 0; j < 3; j++ {
					a |= 1 << d[bi*3+i][bj*3+j]
				}
			}
			if a != k {
				ok = false
			}
		}
	}
	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
