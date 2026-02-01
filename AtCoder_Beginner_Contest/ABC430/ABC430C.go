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
	n, A, B := io.NextInt(), io.NextInt(), io.NextInt()
	s := io.Text()
	a, b := make([]int, n+1), make([]int, n+1)
	for i := 0; i < n; i++ {
		if s[i] == 'a' {
			a[i+1] = a[i] + 1
			b[i+1] = b[i]
		} else {
			a[i+1] = a[i]
			b[i+1] = b[i] + 1
		}
	}
	ans := 0
	for l := 0; l <= n; l++ {
		la, ra := l, n+1
		for la+1 < ra {
			mid := (la + ra) >> 1
			if a[mid]-a[l] > A-1 {
				ra = mid
			} else {
				la = mid
			}
		}
		la++
		lb, rb := l, n+1
		for lb+1 < rb {
			mid := (lb + rb) >> 1
			if b[mid]-b[l] >= B {
				rb = mid
			} else {
				lb = mid
			}
		}
		if la <= n && a[la]-a[l] >= A && b[la]-b[l] < B {
			ans += max(0, lb-la+1)
		}
	}
	fmt.Println(ans)
}
