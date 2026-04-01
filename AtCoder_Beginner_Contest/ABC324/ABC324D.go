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

func pow(a int, b int) int {
	ans := 1
	for i := 0; i < b; i++ {
		ans *= a
	}
	return ans
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, s := io.NextInt(), []byte(io.Text())
	ans := 0
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})
	a, ma := string(s), pow(10, n)
	for x := 0; ; x++ {
		xx := x * x
		if xx > ma {
			break
		}
		t := []byte(strconv.Itoa(xx))
		sort.Slice(t, func(i, j int) bool {
			return t[i] < t[j]
		})
		b := "0000000000000000" + string(t)
		if a == b[len(b)-len(a):] {
			ans++
		}
	}
	fmt.Println(ans)
}
