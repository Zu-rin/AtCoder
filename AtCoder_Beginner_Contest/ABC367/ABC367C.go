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
	n, k := io.NextInt(), io.NextInt()
	d, r := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		r[i] = io.NextInt()
		d[i] = 1
	}
	sum := n
	for {
		if sum%k == 0 {
			for i := 0; i < n-1; i++ {
				fmt.Printf("%v ", d[i])
			}
			fmt.Println(d[n-1])
		}
		for i := n - 1; i >= 0; i-- {
			d[i]++
			if i == 0 && d[0] > r[0] {
				return
			} else if d[i] > r[i] {
				sum -= r[i] - 1
				d[i] = 1
			} else {
				sum += 1
				break
			}
		}
	}
}
