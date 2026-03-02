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
	s, t := io.Text(), io.Text()
	i, j := 0, 0
	ans := 0
	ok := true
	for i < len(s) && j < len(t) {
		if s[i] == t[j] {
			i++
			j++
		} else if s[i] == 'A' {
			i++
			ans++
		} else if t[j] == 'A' {
			j++
			ans++
		} else {
			ok = false
			break
		}
	}
	for ; i < len(s); i++ {
		if s[i] != 'A' {
			ok = false
			break
		}
		ans++
	}
	for ; j < len(t); j++ {
		if t[j] != 'A' {
			ok = false
			break
		}
		ans++
	}
	if !ok {
		fmt.Println("-1")
	} else {
		fmt.Println(ans)
	}
}
