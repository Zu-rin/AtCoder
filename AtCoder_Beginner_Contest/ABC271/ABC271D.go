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
	n, s := io.NextInt(), io.NextInt()
	dp := make([]string, s+1)
	dp[0] = " "
	for i := 1; i <= n; i++ {
		a, b := io.NextInt(), io.NextInt()
		for j := s - 1; j >= 0; j-- {
			if len(dp[j]) == i {
				if j+a <= s {
					dp[j+a] = dp[j] + "H"
				}
				if j+b <= s {
					dp[j+b] = dp[j] + "T"
				}
			}
		}
	}
	if len(dp[s]) == n+1 {
		fmt.Println("Yes")
		fmt.Println(dp[s][1:])
	} else {
		fmt.Println("No")
	}
}
