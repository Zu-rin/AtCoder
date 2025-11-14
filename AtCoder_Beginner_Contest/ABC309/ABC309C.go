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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

type medic struct {
	a, b int64
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, k := io.NextInt(), io.NextInt64()
	d := make([]medic, n)
	sum := int64(0)
	for i := 0; i < n; i++ {
		a, b := io.NextInt64(), io.NextInt64()
		sum += b
		d[i] = medic{a + 1, b}
	}
	if sum <= k {
		fmt.Println(1)
		return
	}
	sort.Slice(d, func(i, j int) bool {
		return d[i].a < d[j].a
	})
	for i := 0; i < n; i++ {
		sum -= d[i].b
		if sum <= k {
			fmt.Println(d[i].a)
			return
		}
	}
}
