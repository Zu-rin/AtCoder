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

const MOD = 998244353

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	dp := make([][]int, 2)
	dp[0], dp[1] = make([]int, n), make([]int, n)
	dp[0][0], dp[1][0] = 1, 1
	p := []int{io.NextInt(), io.NextInt()}
	for i := 0; i < n-1; i++ {
		x := []int{io.NextInt(), io.NextInt()}
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				if x[j] != p[k] {
					dp[j][i+1] += dp[k][i]
				}
			}
			dp[j][i+1] %= MOD
		}
		p = x
	}
	fmt.Println((dp[0][n-1] + dp[1][n-1]) % MOD)
}
