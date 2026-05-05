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
	s := io.Text()
	d := make(map[byte][]int, 26)
	for i := 0; i < len(s); i++ {
		d[s[i]] = append(d[s[i]], i)
	}
	ans := 0
	for _, v := range d {
		l, r := 0, len(v)
		for i := 0; i < len(v)-1; i++ {
			l++
			r--
			ans += l * r * (v[i+1] - v[i] - 1)
		}
		l = len(v)
		ans += (l * (l - 1) * (l - 2)) / 6
	}
	fmt.Println(ans)
}
