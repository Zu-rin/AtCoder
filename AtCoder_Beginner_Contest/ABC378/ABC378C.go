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
	n := io.NextInt()
	ans := make([]int, n)
	d := make(map[int]int)
	for i := 0; i < n; i++ {
		a := io.NextInt()
		if _, ok := d[a]; ok {
			ans[i] = d[a]
		} else {
			ans[i] = -1
		}
		d[a] = i + 1
	}
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Println(ans[n-1])
}
