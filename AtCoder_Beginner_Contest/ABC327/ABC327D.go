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
	a, t := make([]int, m), make([]int, n+1)
	nx := make([][]int, n+1)
	for i := 0; i < m; i++ {
		a[i] = io.NextInt()
	}
	for i := 0; i < m; i++ {
		b := io.NextInt()
		nx[a[i]] = append(nx[a[i]], b)
		nx[b] = append(nx[b], a[i])
	}
	for i := 0; i <= n; i++ {
		t[i] = -1
	}
	ok := true
	for i := 1; i <= n; i++ {
		q := make([]int, 0)
		if t[i] == -1 {
			q = append(q, i)
			t[i] = 0
			for len(q) > 0 {
				x := q[0]
				q = q[1:]
				for _, v := range nx[x] {
					if t[v] == -1 {
						t[v] = t[x] ^ 1
						q = append(q, v)
					} else if t[v] == t[x] {
						ok = false
					}
				}
			}
		}
	}
	for i := 1; i <= n; i++ {
		for _, v := range nx[i] {
			if t[i] == t[v] {
				ok = false
				break
			}
		}
	}
	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
