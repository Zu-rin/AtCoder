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
	n := io.NextInt()
	d := make(map[int][]int)
	for i := 0; i < n; i++ {
		x := io.NextInt()
		d[x] = append(d[x], i)
	}
	ans := 1 << 60
	for _, v := range d {
		sort.Ints(v)
		for i := 0; i < len(v)-1; i++ {
			ans = min(ans, v[i+1]-v[i]+1)
		}
	}
	if ans == 1<<60 {
		ans = -1
	}
	fmt.Println(ans)
}
