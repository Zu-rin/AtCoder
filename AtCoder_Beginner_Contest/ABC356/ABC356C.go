package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
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

type query struct {
	c, d int
	r    byte
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, q, k := io.NextInt(), io.NextInt(), io.NextInt()
	qs := make([]query, q)
	for i := 0; i < q; i++ {
		c, d := io.NextInt(), 0
		for j := 0; j < c; j++ {
			d |= 1 << (io.NextInt() - 1)
		}
		r := io.Text()[0]
		qs[i] = query{c: c, d: d, r: r}
	}
	ans := 0
	for bits := 0; bits < (1 << n); bits++ {
		ok := true
		for _, v := range qs {
			d := bits & v.d
			cnt := 0
			if v.r == 'o' {
				if v.c < k {
					fmt.Println(0)
					return
				}
				for d > 0 {
					if d&1 == 1 {
						cnt++
					}
					d >>= 1
				}
				if cnt < k {
					ok = false
					break
				}
			} else {
				for d > 0 {
					if d&1 == 1 {
						cnt++
					}
					d >>= 1
				}
				if cnt >= k {
					ok = false
					break
				}
			}
		}
		if ok {
			ans++
		}
	}
	fmt.Println(ans)
}
