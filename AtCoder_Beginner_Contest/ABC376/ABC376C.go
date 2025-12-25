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

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	a := make([]int, n)
	b := make([]int, n-1)
	for i := 0; i < n; i++ {
		a[i] = io.NextInt()
	}
	for i := 0; i < n-1; i++ {
		b[i] = io.NextInt()
	}
	sort.Ints(a)
	sort.Ints(b)
	ans, e := 0, 0
	for i, j := 0, 0; j < n-1; i++ {
		if a[i] > b[j] {
			ans = a[i]
			e++
			if e > 1 {
				fmt.Println(-1)
				return
			}
		} else {
			j++
		}
	}
	if ans == 0 {
		for i := n - 1; i >= 0; i-- {
			if i == 0 {
				ans = a[0]
			} else if a[i] > b[i-1] {
				ans = a[i]
				break
			}
		}
	}
	fmt.Println(ans)
}
