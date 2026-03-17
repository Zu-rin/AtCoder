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
	n, l, r := io.NextInt(), io.NextInt(), io.NextInt()
	s := io.Text()
	d := make(map[byte][]int)
	for i := 0; i < n; i++ {
		d[s[i]] = append(d[s[i]], i)
	}
	ans := 0
	for _, v := range d {
		a, b := 1, 1
		for i := 0; i < len(v); i++ {
			for a < len(v) && v[a]-v[i] < l {
				a++
			}
			for b < len(v) && v[b]-v[i] <= r {
				b++
			}
			ans += b - a
		}
	}
	fmt.Println(ans)
}