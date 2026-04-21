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

func dfs(n int, nx [][]int, visited []bool) {
	visited[n] = true
	for _, nn := range nx[n] {
		if !visited[nn] {
			dfs(nn, nx, visited)
		}
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, m := io.NextInt(), io.NextInt()
	nx := make([][]int, n+1)
	visited := make([]bool, n+1)
	for i := 1; i <= n; i++ {
		nx[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		a, b := io.NextInt(), io.NextInt()
		nx[a] = append(nx[a], b)
	}
	dfs(1, nx, visited)
	ans := 0
	for i := 1; i <= n; i++ {
		if visited[i] {
			ans++
		}
	}
	fmt.Println(ans)
}
