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

func pow(a, b int) int {
	if b == 0 {
		return 1
	}
	if b%2 == 0 {
		x := pow(a, b>>1)
		return x * x
	}
	return a * pow(a, b-1)
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	k := io.NextInt()
	d := make(map[int]int)
	for k&1 == 0 {
		d[2]++
		k >>= 1
	}
	for i := 3; i*i <= k; i += 2 {
		for k%i == 0 {
			d[i]++
			k /= i
		}
	}
	if k > 1 {
		d[k]++
	}
	ans := 1
	for x, v := range d {
		for i := x; v > 0; i += x {
			ans = max(ans, i)
			a := i
			for a%x == 0 {
				a /= x
				v--
			}
		}
	}
	fmt.Println(ans)
}
