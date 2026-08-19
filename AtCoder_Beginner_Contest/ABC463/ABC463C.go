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

type pair struct {
	x, i int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	h, l := make([]int, n), make([]int, n)
	d := make(map[int]int)
	for i := 0; i < n; i++ {
		h[i], l[i] = io.NextInt(), io.NextInt()
		d[h[i]]++
	}
	dd := make([]int, 0, len(d))
	for k := range d {
		dd = append(dd, k)
	}
	sort.Ints(dd)
	q := io.NextInt()
	ans, t := make([]int, q), make([]pair, q)
	for i := 0; i < q; i++ {
		t[i] = pair{io.NextInt(), i}
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i].x < t[j].x
	})
	j := 0
	for i := 0; i < q; i++ {
		for j < n && l[j] <= t[i].x {
			d[h[j]]--
			j++
		}
		k := len(dd) - 1
		for d[dd[k]] == 0 {
			k--
		}
		dd = dd[:k+1]
		ans[t[i].i] = dd[k]
	}
	for i := 0; i < q; i++ {
		fmt.Println(ans[i])
	}
}
