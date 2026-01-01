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
	k := io.NextInt()
	a, b := io.Text(), io.Text()
	ok := true
	for i, d := 0, 0; i < min(len(a), len(b)); i++ {
		if max(len(a), len(b))-min(len(a), len(b)) > 1 {
			ok = false
			break
		}
		if len(a) < len(b) {
			if a[i] != b[i+d] {
				d++
			}
		} else if len(a) > len(b) {
			if a[i+d] != b[i] {
				d++
			}
		} else {
			if a[i] != b[i] {
				d++
			}
		}
		if d > k {
			ok = false
			break
		}
	}
	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

}
