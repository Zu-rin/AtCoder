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
	n := io.NextInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	m := io.NextInt()
	b := make(map[int]bool, m)
	for i := 0; i < m; i++ {
		b[io.NextInt()] = true
	}
	x := io.NextInt()
	dp := make([]bool, x+1)
	dp[x] = true
	for i := x; i >= 0; i-- {
		if !dp[i] {
			continue
		}
		for j := 0; j < n; j++ {
			if i-a[j] >= 0 && !b[i-a[j]] {
				dp[i-a[j]] = true
			}
		}
	}
	if dp[0] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
