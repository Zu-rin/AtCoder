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
	name string
	sum  int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	t := []int{io.NextInt(), io.NextInt(), io.NextInt(), io.NextInt(), io.NextInt()}
	d := []pair{}
	for i := 1; i < 1<<5; i++ {
		sum := 0
		name := []byte{}
		for j := 0; j < 5; j++ {
			if (i>>j)&1 == 1 {
				name = append(name, byte('A'+j))
				sum += t[j]
			}
		}
		d = append(d, pair{name: string(name), sum: sum})
	}
	sort.Slice(d, func(i, j int) bool {
		if d[i].sum == d[j].sum {
			return d[i].name < d[j].name
		}
		return d[i].sum > d[j].sum
	})
	for i := 0; i < len(d); i++ {
		fmt.Println(d[i].name)
	}
}
