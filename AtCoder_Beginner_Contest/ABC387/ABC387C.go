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

func pow(a, b int) int {
	ans := 1
	for i := 0; i < b; i++ {
		ans *= a
	}
	return ans
}

func count(x int) int {
	d := []int{}
	for x > 0 {
		d = append([]int{x % 10}, d...)
		x /= 10
	}
	ans, n := 0, len(d)
	for i := 1; i <= n; i++ {
		if i == n {
			ans++
			break
		}
		ans += pow(d[0], n-1-i) * min(d[0], d[i])
		if d[0] <= d[i] {
			break
		}
	}
	for i := 0; i < n; i++ {
		ma := 9
		if i == 0 {
			ma = d[0] - 1
		}
		for j := 1; j <= ma; j++ {
			ans += pow(j, n-1-i)
		}
	}
	return ans
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	l, r := io.NextInt(), io.NextInt()
	fmt.Println(count(r) - count(l-1))
}
