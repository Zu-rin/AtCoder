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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, t, s := io.NextInt(), io.NextInt(), io.Text()
	a, b := make([]int, 0, n), make([]int, 0, n)
	for i := 0; i < n; i++ {
		x := io.NextInt()
		if s[i] == '1' {
			a = append(a, x)
		} else {
			b = append(b, x)
		}
	}
	sort.Ints(a)
	sort.Ints(b)
	ans := 0
	for i, j, x := 0, 0, 0; i < len(a); i++ {
		for x < len(b) && a[i] > b[x] {
			x++
		}
		for j < len(b) && a[i]+t >= b[j]-t {
			j++
		}
		ans += j - x
	}
	fmt.Println(ans)
}
