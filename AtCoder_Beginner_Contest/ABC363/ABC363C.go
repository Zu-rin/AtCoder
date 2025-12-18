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

func (io *Io) NextInt64() int64 {
	x, err := strconv.ParseInt(io.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

func next_permutation(arr []byte) bool {
	len := len(arr) - 1
	i := len
	for i > 0 && !(arr[i-1] < arr[i]) {
		i--
	}
	if i <= 0 {
		return false
	}
	j := len
	for !(arr[i-1] < arr[j]) {
		j--
	}
	arr[i-1], arr[j] = arr[j], arr[i-1]
	j = len
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
	return true
}

func check(d []byte, n, k int) bool {
	ok := true
	for i := 0; i < n-k+1; i++ {
		kb := true
		for l, r := i, i+k-1; l < r; l, r = l+1, r-1 {
			if d[l] != d[r] {
				kb = false
				break
			}
		}
		if kb {
			ok = false
			break
		}
	}
	return ok
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, k := io.NextInt(), io.NextInt()
	s := io.Text()
	d := []byte(s)
	db := make(map[string]bool)
	sort.Slice(d, func(i, j int) bool {
		return d[i] < d[j]
	})
	for {
		if _, exists := db[string(d)]; !exists && check(d, n, k) {
			db[string(d)] = true
		}
		if !next_permutation(d) {
			break
		}
	}
	fmt.Println(len(db))
}
