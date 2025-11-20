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

func next_permutation(arr sort.Interface) bool {
	len := arr.Len() - 1
	i := len
	for i > 0 && !arr.Less(i-1, i) {
		i--
	}
	if i <= 0 {
		return false
	}
	j := len
	for !arr.Less(i-1, j) {
		j--
	}
	arr.Swap(i-1, j)
	j = len
	for i < j {
		arr.Swap(i, j)
		i++
		j--
	}
	return true
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()

	n, m := io.NextInt(), io.NextInt()
	d := make([][]int, n+1)
	a := make(sort.IntSlice, n)
	for i := 1; i <= n; i++ {
		d[i] = make([]int, n+1)
		a[i-1] = i
	}
	for i := 0; i < m; i++ {
		a, b, c := io.NextInt(), io.NextInt(), io.NextInt()
		d[a][b] = c
		d[b][a] = c
	}
	ans := 0
	con := true
	for con {
		s := 0
		for i := 0; i < n-1; i++ {
			if d[a[i]][a[i+1]] == 0 {
				s = 0
			}
			s += d[a[i]][a[i+1]]
			ans = max(ans, s)
		}
		con = next_permutation(a)
	}
	fmt.Println(ans)
}
