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
	x, a int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	d := make([]pair, m)
	for i := 0; i < m; i++ {
		d[i].x = io.NextInt()
	}
	for i := 0; i < m; i++ {
		d[i].a = io.NextInt()
	}
	sort.Slice(d, func(i, j int) bool {
		return d[i].x < d[j].x
	})
	if d[0].x != 1 {
		fmt.Println(-1)
		return
	}
	if d[m-1].x != n {
		d = append(d, pair{x: n, a: 0})
	}
	ans := 0
	for i := 0; i < len(d)-1; i++ {
		k := d[i+1].x - d[i].x
		if d[i].a < k {
			fmt.Println(-1)
			return
		}
		ans += k*(k-1)/2 + (d[i].a-k)*k
		d[i+1].a += d[i].a - k
	}
	if d[len(d)-1].a != 1 {
		fmt.Println(-1)
		return
	}
	fmt.Println(ans)
}
