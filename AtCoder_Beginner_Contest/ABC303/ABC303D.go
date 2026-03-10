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
	x, y, z := io.NextInt(), io.NextInt(), io.NextInt()
	s := io.Text()
	dp := make([][]int, len(s)+1)
	for i := range dp {
		dp[i] = make([]int, 2)
		for j := range dp[i] {
			dp[i][j] = 1 << 60
		}
	}
	dp[0][0], dp[0][1] = 0, z
	for i, c := range s {
		if c == 'a' {
			dp[i+1][0] = min(dp[i+1][0], min(dp[i][0]+x, dp[i][1]+y+z))
			dp[i+1][1] = min(dp[i+1][1], min(dp[i][0]+x+z, dp[i][1]+y))
		} else {
			dp[i+1][0] = min(dp[i+1][0], min(dp[i][0]+y, dp[i][1]+x+z))
			dp[i+1][1] = min(dp[i+1][1], min(dp[i][0]+y+z, dp[i][1]+x))
		}
	}
	ans := min(dp[len(s)][0], dp[len(s)][1])
	fmt.Println(ans)
}
