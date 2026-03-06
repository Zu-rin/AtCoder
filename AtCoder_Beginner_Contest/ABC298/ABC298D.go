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

func pow(x, n int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	q := io.NextInt()
	a, d := 1, make([]int, 0, q)
	d = append(d, 1)
	for ; q > 0; q-- {
		k := io.NextInt()
		switch k {
		case 1:
			x := io.NextInt()
			a = (a*10 + x) % mod
			d = append(d, x)
		case 2:
			x := d[0]
			a = (a - x*pow(10, len(d)-1)) % mod
			d = d[1:]
			if a < 0 {
				a += mod
			}
		case 3:
			fmt.Fprintln(io.Out, a)
		}
	}
}
