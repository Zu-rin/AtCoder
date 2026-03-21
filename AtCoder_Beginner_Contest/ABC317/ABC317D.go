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
	dp := make([]int, 100001)
	for i := range dp {
		dp[i] = 1 << 60
	}
	dp[0] = 0
	zsum := 0
	for i := 0; i < n; i++ {
		x, y, z := io.NextInt(), io.NextInt(), io.NextInt()
		zsum += z
		a := max(0, (x+y+1)>>1-x)
		for j := 100000 - z; j >= 0; j-- {
			dp[j+z] = min(dp[j+z], dp[j]+max(0, a))
		}
	}
	ans := 1 << 60
	for i := (zsum + 1) >> 1; i <= zsum; i++ {
		ans = min(ans, dp[i])
	}
	fmt.Println(ans)
}
