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

func binarySearch(d []int, tag int) int {
	if tag < d[0] {
		return -1
	}
	l, r := 0, len(d)
	for l+1 < r {
		p := (l + r) >> 1
		if d[p] <= tag {
			l = p
		} else {
			r = p
		}
	}
	return l
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	q := io.NextInt()
	for i := 0; i < q; i++ {
		n := io.NextInt()
		d := make([]int, n)
		for j := 0; j < n; j++ {
			d[j] = io.NextInt()
		}
		if d[0]<<1 >= d[n-1] {
			fmt.Println(2)
			continue
		}
		a := make([]int, 0, n)
		for _, v := range d {
			if d[0] < v && v < d[n-1] {
				a = append(a, v)
			}
		}
		a = append(a, d[0], d[n-1])
		sort.Ints(a)
		ans, ok := 1, true
		k := 0
		for k < len(a)-1 {
			q := binarySearch(a, a[k]<<1)
			if q == k {
				ok = false
				break
			}
			ans++
			k = q
		}
		if ok {
			fmt.Println(ans)
		} else {
			fmt.Println(-1)
		}
	}
}
