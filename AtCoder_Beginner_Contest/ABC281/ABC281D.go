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
	n, k, d := io.NextInt(), io.NextInt(), io.NextInt()
	dp := make([][]int, k+1)
	for i := 0; i <= k; i++ {
		dp[i] = make([]int, d)
		for j := 0; j < d; j++ {
			dp[i][j] = -1
		}
	}
	dp[0][0] = 0
	for i := 0; i < n; i++ {
		a := io.NextInt()
		for j := k - 1; j >= 0; j-- {
			for l := d - 1; l >= 0; l-- {
				if dp[j][l] == -1 {
					continue
				}
				nx := (l + a) % d
				dp[j+1][nx] = max(dp[j+1][nx], dp[j][l]+a)
			}
		}
	}
	if dp[k][0] >= 0 {
		fmt.Println(dp[k][0])
	} else {
		fmt.Println(-1)
	}
}
