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

func dfs(ans [][]int, i, j, n, size int) {
	di, dj := []int{0, 1, 0, -1}, []int{1, 0, -1, 0}
	for x := 0; ; x++ {
		k := x % 4
		for {
			ni, nj := i+di[k], j+dj[k]
			if ni < 0 || ni >= size || nj < 0 || nj >= size || ans[ni][nj] != 0 {
				break
			}
			n++
			ans[ni][nj] = n
			i, j = ni, nj
		}
		if n == size*size-1 {
			break
		}
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	ans := make([][]int, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]int, n)
	}
	ans[0][0], ans[n>>1][n>>1] = 1, -1
	dfs(ans, 0, 0, 1, n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if ans[i][j] == -1 {
				fmt.Fprint(io.Out, "T ")
				continue
			}
			fmt.Fprint(io.Out, ans[i][j], " ")
		}
		fmt.Fprintln(io.Out)
	}
}
