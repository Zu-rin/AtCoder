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

func bfs(d map[int][]int, N, n int) int {
	v := make([]int, N+1)
	q := []int{n}
	v[n] = 1
	ans := 1
	for len(q) > 0 {
		cur := q[0]
		q = q[1:]
		for _, nx := range d[cur] {
			if v[nx] == 0 {
				v[nx] = v[cur] + 1
				ans = max(ans, v[nx])
				q = append(q, nx)
			}
		}
	}
	return ans - 1
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	A, B, m := io.NextInt(), io.NextInt(), io.NextInt()
	d := make(map[int][]int, A+B+1)
	for i := 0; i < m; i++ {
		x, y := io.NextInt(), io.NextInt()
		d[x] = append(d[x], y)
		d[y] = append(d[y], x)
	}
	a, b := bfs(d, A+B, 1), bfs(d, A+B, A+B)
	fmt.Println(a + b + 1)
}
