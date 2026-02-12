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

func check(x int, d map[int]int) bool {
	ok := true
	for k, v := range d {
		if k == x {
			continue
		}
		if (x == k<<1 && v&1 == 1) || v != d[x-k] {
			ok = false
			break
		}
	}
	return ok
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	d := make(map[int]int, n)
	ma, mi := 0, 1<<60
	for i := 0; i < n; i++ {
		x := io.NextInt()
		d[x]++
		ma = max(ma, x)
		mi = min(mi, x)
	}
	ans := []int{}
	if check(ma, d) {
		ans = append(ans, ma)
	}
	if check(mi+ma, d) {
		ans = append(ans, mi+ma)
	}
	if len(ans) > 1 {
		fmt.Print(ans[0], " ")
	}
	fmt.Println(ans[len(ans)-1])
}
