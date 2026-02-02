package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
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
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, x, y := io.NextInt(), io.NextInt(), io.NextInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	lcm := x * y / gcd(x, y)
	sort.Ints(a)
	ans := a[0]
	xx := lcm / x
	yy := lcm / y
	k := xx - yy
	for i := 1; i < n; i++ {
		if (a[i]-a[0])%k != 0 {
			fmt.Println("-1")
			return
		}
		d := a[0] - (a[i]-a[0])/k*yy
		if d < 0 {
			fmt.Println("-1")
			return
		}
		ans += d
	}
	fmt.Println(ans)
}
