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

type pair struct {
	x, n int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, x := io.NextInt(), io.NextInt()
	a := make([]pair, n)
	dp := make([]bool, x+1)
	dp[0] = true
	for i := 0; i < n; i++ {
		a[i] = pair{io.NextInt(), io.NextInt()}
	}
	for i := 0; i < n; i++ {
		for j := x; j >= 0; j-- {
			if !dp[j] {
				continue
			}
			for k := 1; k <= a[i].n; k++ {
				if j+a[i].x*k > x {
					break
				}
				dp[j+a[i].x*k] = true
			}
		}
	}
	if dp[x] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
