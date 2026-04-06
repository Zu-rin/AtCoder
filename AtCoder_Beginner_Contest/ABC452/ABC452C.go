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
	n := io.NextInt()
	a, b := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		a[i], b[i] = io.NextInt(), io.NextInt()
	}
	m := io.NextInt()
	s := make([]string, m)
	d := make(map[int][]map[byte]bool)
	for i := 0; i < m; i++ {
		s[i] = io.Text()
		l := len(s[i])
		if _, exists := d[l]; !exists {
			d[l] = make([]map[byte]bool, l+1)
			for j := 0; j <= l; j++ {
				d[l][j] = make(map[byte]bool)
			}
		}
		for j, c := range s[i] {
			d[l][j+1][byte(c)] = true
		}
	}
	for i := 0; i < m; i++ {
		if len(s[i]) != n {
			fmt.Fprintln(io.Out, "No")
			continue
		}
		ok := true
		for j, c := range s[i] {
			row, exists := d[a[j]]
			if !exists || !row[b[j]][byte(c)] {
				fmt.Fprintln(io.Out, "No")
				ok = false
				break
			}
		}
		if ok {
			fmt.Fprintln(io.Out, "Yes")
		}
	}
}
