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

type ran struct {
	l, r int
}

func join(s ...[]byte) []byte {
	ans := []byte{}
	for _, v := range s {
		ans = append(ans, v...)
	}
	return ans
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	_, k := io.NextInt(), io.NextInt()-1
	s := []byte("0" + io.Text() + "0")
	d := []ran{}
	for i := 0; i < len(s)-1; i++ {
		if s[i] == '0' && s[i+1] == '1' {
			d = append(d, ran{l: i + 1})
		} else if s[i] == '1' && s[i+1] == '0' {
			d[len(d)-1].r = i + 1
		}
	}
	ans := join(s[1:d[k-1].r], s[d[k].l:d[k].r], s[d[k-1].r:d[k].l], s[d[k].r:len(s)-1])
	fmt.Println(string(ans))
}
