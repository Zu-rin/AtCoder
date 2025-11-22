package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

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

type bitmap struct {
	bits []uint64
	w, h int
}

func NewBitmap(s []string) *bitmap {
	w, h := len(s[0]), len(s)
	bits := make([]uint64, h)
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if s[y][x] == '#' {
				bits[y] |= 1 << (x)
			}
		}
	}
	return &bitmap{
		bits: bits,
		w:    w,
		h:    h,
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()

	ha, _ := io.NextInt(), io.NextInt()
	sa := make([]string, ha)
	for i := 0; i < ha; i++ {
		sa[i] = io.Text()
	}
	hb, _ := io.NextInt(), io.NextInt()
	sb := make([]string, hb)
	for i := 0; i < hb; i++ {
		sb[i] = io.Text()
	}
	hc, wc := io.NextInt(), io.NextInt()
	sc := make([]string, hc+18)
	for i := 0; i < 9; i++ {
		sc[i] = strings.Repeat(".", wc+18)
		sc[len(sc)-i-1] = strings.Repeat(".", wc+18)
	}
	for i := 0; i < hc; i++ {
		sc[i+9] = strings.Repeat(".", 9) + io.Text() + strings.Repeat(".", 9)
	}
	a, b, c := NewBitmap(sa), NewBitmap(sb), NewBitmap(sc)
	for ay := 0; ay <= c.h-a.h; ay++ {
		for ax := 0; ax <= c.w-a.w; ax++ {
			d := make([]uint64, c.h)
			for y := 0; y < a.h; y++ {
				d[ay+y] |= a.bits[y] << (ax)
			}
			for by := 0; by <= c.h-b.h; by++ {
				for bx := 0; bx <= c.w-b.w; bx++ {
					buf := append([]uint64{}, d...)
					for y := 0; y < b.h; y++ {
						buf[by+y] |= b.bits[y] << (bx)
					}
					ans := true
					for y := 0; y < c.h; y++ {
						if buf[y] != c.bits[y] {
							ans = false
							break
						}
					}
					if ans {
						fmt.Println("Yes")
						return
					}
				}
			}
		}
	}
	fmt.Println("No")
}
