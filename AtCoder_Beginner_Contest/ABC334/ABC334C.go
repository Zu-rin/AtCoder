package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	_, k := io.NextInt(), io.NextInt()
	d := make([]int64, k)
	for i := 0; i < k; i++ {
		d[i] = io.NextInt64()
	}
	if k == 1 {
		fmt.Println(0)
		return
	}
	for i := 0; i < k-1; i++ {
		d[i] = d[i+1] - d[i]
	}
	for i := 0; i < k-2; i += 2 {
		d[i+2] += d[i]
	}
	if k%2 == 0 {
		fmt.Println(d[len(d)-2])
		return
	}
	for i := k - 2; i-2 >= 0; i -= 2 {
		d[i-2] += d[i]
	}
	ans := min(d[1], d[k-3])
	for i := 2; i < k-1; i += 2 {
		ans = min(ans, d[i-2]+d[i+1])
	}
	fmt.Println(ans)
}
