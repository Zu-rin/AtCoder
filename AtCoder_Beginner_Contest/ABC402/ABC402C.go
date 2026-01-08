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
	n, m := io.NextInt(), io.NextInt()
	a := make([][]int, n+1)
	k := make([]int, m+1)
	ans := 0
	for i := 1; i <= m; i++ {
		k[i] = io.NextInt()
		for j := 0; j < k[i]; j++ {
			x := io.NextInt()
			a[x] = append(a[x], i)
		}
	}
	for i := 0; i < n; i++ {
		b := io.NextInt()
		for _, v := range a[b] {
			k[v]--
			if k[v] == 0 {
				ans++
			}
		}
		fmt.Println(ans)
	}
}
