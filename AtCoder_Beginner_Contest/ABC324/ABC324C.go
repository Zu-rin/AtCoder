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

func check(s, t string) bool {
	if len(s) > len(t) {
		s, t = t, s
	}
	if len(t)-len(s) > 1 {
		return false
	}
	a, b, diff := 0, 0, 0
	for a < len(s) && b < len(t) {
		if s[a] != t[b] {
			diff++
			if diff > 1 {
				return false
			}
			if len(s) == len(t) {
				a++
			}
		} else {
			a++
		}
		b++
	}
	return true
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, t := io.NextInt(), io.Text()
	ans := []int{}
	for i := 1; i <= n; i++ {
		s := io.Text()
		if check(s, t) {
			ans = append(ans, i)
		}
	}
	fmt.Println(len(ans))
	if len(ans) > 0 {
		for i := 0; i < len(ans)-1; i++ {
			fmt.Printf("%d ", ans[i])
		}
		fmt.Println(ans[len(ans)-1])
	}
}
