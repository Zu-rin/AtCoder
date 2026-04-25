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

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m, k := io.NextInt(), io.NextInt(), io.NextInt()
	gcd := gcd(n, m)
	lcm := n / gcd * m
	p := lcm/n + lcm/m - 2
	a, b := k/p, k%p
	x, y := n, m
	ans := 0
	for b > 0 {
		ans = min(x, y)
		b--
		if x < y {
			x += n
		} else {
			y += m
		}
	}
	if ans == 0 {
		fmt.Println(lcm*a - min(n, m))
	} else {
		fmt.Println(lcm*a + ans)
	}
}
