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

const mod = 998244353

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	s := io.Text()
	d := make([]int, 0, len(s)+1)
	d = append(d, -1)
	for i := 0; i < len(s)-1; i++ {
		if s[i] == s[i+1] {
			d = append(d, i)
		}
	}
	d = append(d, len(s)-1)
	ans := 0
	for i := 0; i < len(d)-1; i++ {
		a := d[i+1] - d[i] + 2
		ans += (a*(a-1))>>1 - (a - 1)
		ans %= mod
	}
	fmt.Println(ans)
}
