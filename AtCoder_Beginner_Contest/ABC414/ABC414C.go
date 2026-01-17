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

func check(x, a int) bool {
	d := []int{}
	for x > 0 {
		d = append(d, x%a)
		x /= a
	}
	for i := 0; i < len(d)/2; i++ {
		if d[i] != d[len(d)-1-i] {
			return false
		}
	}
	return true
}

func search(s string, a, n int) int {
	x, _ := strconv.Atoi(s)
	if x > n || len(s) > 12 {
		return 0
	}
	ans := 0
	if check(x, 10) && check(x, a) {
		ans = x
	}
	d := "0123456789"
	for _, c := range d {
		ss := string(c) + s + string(c)
		ans += search(ss, a, n)
	}
	return ans
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	a, n := io.NextInt(), io.NextInt()
	ans := 0
	d := "0123456789"
	for _, c := range d {
		ans += search(string(c), a, n)
	}
	ans += search("", a, n)
	fmt.Println(ans)
}
