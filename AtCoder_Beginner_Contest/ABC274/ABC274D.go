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

func check(a []int, sx, x int) bool {
	dp := make([]map[int]bool, len(a)+1)
	dp[0] = map[int]bool{sx: true}
	for i := 0; i < len(a); i++ {
		dp[i+1] = map[int]bool{}
		for k := range dp[i] {
			dp[i+1][k+a[i]] = true
			dp[i+1][k-a[i]] = true
		}
	}
	return dp[len(a)][x]
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, x, y := io.NextInt(), io.NextInt(), io.NextInt()
	a, b := make([]int, n>>1+n&1), make([]int, n>>1)
	for i := 0; i < n; i++ {
		if i&1 == 0 {
			a[i>>1] = io.NextInt()
		} else {
			b[i>>1] = io.NextInt()
		}
	}

	if check(a[1:], a[0], x) && check(b, 0, y) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
