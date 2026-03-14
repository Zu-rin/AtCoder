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

func dfs(s []string, mem [][]bool, rule map[byte]byte, x, y int) {
	if mem[x][y] {
		return
	}
	mem[x][y] = true
	dx, dy := []int{0, 0, -1, 1}, []int{-1, 1, 0, 0}
	for i := 0; i < 4; i++ {
		nx, ny := x+dx[i], y+dy[i]
		if 0 <= nx && nx < len(s) && 0 <= ny && ny < len(s[0]) && s[nx][ny] == rule[s[x][y]] {
			dfs(s, mem, rule, nx, ny)
		}
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	h, w := io.NextInt(), io.NextInt()
	s, mem := make([]string, h), make([][]bool, h)
	nx := map[byte]byte{'s': 'n', 'n': 'u', 'u': 'k', 'k': 'e', 'e': 's'}
	for i := 0; i < h; i++ {
		s[i] = io.Text()
		mem[i] = make([]bool, w)
	}
	if s[0][0] != 's' {
		fmt.Println("No")
		return
	}
	dfs(s, mem, nx, 0, 0)
	if mem[h-1][w-1] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
