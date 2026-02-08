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

type pair struct {
	w, p int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	q := io.NextInt()
	for ; q > 0; q-- {
		n := io.NextInt()
		d := make([]pair, n)
		w, p := 0, 0
		for i := 0; i < n; i++ {
			d[i] = pair{io.NextInt(), io.NextInt()}
			p += d[i].p
		}
		sort.Slice(d, func(i, j int) bool {
			return d[i].w+d[i].p < d[j].w+d[j].p
		})
		ans := 0
		for i := 0; i < n; i++ {
			w += d[i].w
			p -= d[i].p
			if w > p {
				break
			}
			ans++
		}
		fmt.Fprintln(io.Out, ans)
	}
}
