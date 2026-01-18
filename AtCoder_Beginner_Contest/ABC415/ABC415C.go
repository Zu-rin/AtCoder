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

func search(a []map[int]bool, m map[int]bool, n, k, x int) bool {
	if n == k {
		return true
	}
	if val, ok := m[x]; ok {
		return val
	}
	for i := 0; i < n; i++ {
		if x&(1<<i) == 0 && !a[k+1][x|(1<<i)] {
			if search(a, m, n, k+1, x|(1<<i)) {
				m[x|(1<<i)] = true
				return true
			} else {
				m[x|(1<<i)] = false
			}
		}
	}
	return false
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	q := io.NextInt()
	for i := 0; i < q; i++ {
		n, s := io.NextInt(), io.Text()
		a := make([]map[int]bool, n+1)
		m := make(map[int]bool)
		for j := 0; j < n+1; j++ {
			a[j] = make(map[int]bool)
		}
		for i, c := range s {
			if c == '1' {
				x, k := i+1, 0
				for x > 0 {
					if x&1 == 1 {
						k++
					}
					x >>= 1
				}
				a[k][i+1] = true
			}
		}
		if search(a, m, n, 0, 0) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
