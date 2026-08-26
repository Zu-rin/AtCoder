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
	n, s, k := io.NextInt(), io.Text(), 0
	ans := make([]int, 0, n)
	a, b := make([]int, 0, n), make([]int, 0, n)
	for i := 1; i <= n; i++ {
		if k&1 == 0 {
			a = append(a, i)
		} else {
			b = append(b, i)
		}
		if s[i-1] == 'o' {
			k++
		}
	}
	for i := len(b) - 1; i >= 0; i-- {
		ans = append(ans, b[i])
	}
	for i := 0; i < len(a); i++ {
		ans = append(ans, a[i])
	}
	if k&1 == 1 {
		for i := 0; i < len(ans)/2; i++ {
			ans[i], ans[len(ans)-1-i] = ans[len(ans)-1-i], ans[i]
		}
	}
	for i := 0; i < len(ans)-1; i++ {
		fmt.Printf("%v ", ans[i])
	}
	fmt.Println(ans[n-1])
}
