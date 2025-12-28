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

type Queue struct {
	data []pos
}

func NewQueue(size int) *Queue {
	return &Queue{
		data: make([]pos, 0, size),
	}
}

func (que *Queue) push(p *pos) {
	que.data = append(que.data, *p)
}

func (que *Queue) pop() *pos {
	ans := que.data[0]
	que.data = que.data[1:]
	return &ans
}

func (que *Queue) empty() bool {
	return len(que.data) == 0
}

type pos struct {
	i, j, k int
}

type point struct {
	i, j int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	h, w, k := io.NextInt(), io.NextInt(), io.NextInt()
	s := make([]string, h)
	d := make(map[point]bool)
	q := NewQueue(h * w)
	for i := 0; i < h; i++ {
		s[i] = io.Text()
	}
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == 'H' {
				q.push(&pos{i, j, k + 1})
			}
		}
	}
	for !q.empty() {
		p := q.pop()
		if _, ok := d[point{p.i, p.j}]; ok {
			continue
		}
		d[point{p.i, p.j}] = true
		if p.k == 1 {
			continue
		}
		drc := []pos{{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}}
		for _, v := range drc {
			nx := pos{p.i + v.i, p.j + v.j, p.k - 1}
			if nx.i < 0 || nx.i >= h || nx.j < 0 || nx.j >= w {
				continue
			}
			if s[nx.i][nx.j] == '#' {
				continue
			}
			q.push(&nx)
		}
	}
	fmt.Println(len(d))
}
