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
	t, n := io.Text(), io.NextInt()
	dp := make([]int, len(t)+1)
	for i := 1; i <= len(t); i++ {
		dp[i] = 1 << 30
	}
	for i := 0; i < n; i++ {
		m := io.NextInt()
		pdp := make([]int, len(t)+1)
		copy(pdp, dp)
		for j := 0; j < m; j++ {
			s := io.Text()
			for k := 0; k <= len(t)-len(s); k++ {
				if t[k:k+len(s)] == s && pdp[k]+1 < dp[k+len(s)] {
					dp[k+len(s)] = pdp[k] + 1
				}
			}
		}
	}
	if dp[len(t)] == 1<<30 {
		fmt.Println(-1)
	} else {
		fmt.Println(dp[len(t)])
	}
}
