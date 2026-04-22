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

type node struct {
	a, x int
}

type priorityQueue struct {
	data []node
	comp func(i, j int) bool
}

func NewPriorityQueue(size int) *priorityQueue {
	p := &priorityQueue{
		data: make([]node, 0, size),
	}
	p.comp = func(i, j int) bool {
		return p.data[i].x < p.data[j].x
	}
	return p
}

func (q *priorityQueue) push(x node) {
	q.data = append(q.data, x)
	a := len(q.data) - 1
	for a > 0 {
		p := (a - 1) / 2
		if !q.comp(a, p) {
			break
		}
		q.data[a], q.data[p] = q.data[p], q.data[a]
		a = p
	}
}

func (q *priorityQueue) pop() node {
	ret := q.data[0]
	q.data[0] = q.data[len(q.data)-1]
	q.data = q.data[:len(q.data)-1]
	a := 0
	for {
		l := 2*a + 1
		r := 2*a + 2
		if l >= len(q.data) {
			break
		}
		tag := l
		if r < len(q.data) && q.comp(r, l) {
			tag = r
		}
		if !q.comp(tag, a) {
			break
		}
		q.data[a], q.data[tag] = q.data[tag], q.data[a]
		a = tag
	}
	return ret
}

func (q *priorityQueue) top() node {
	return q.data[0]
}

func (q *priorityQueue) len() int {
	return len(q.data)
}

func Dijkstra(d []map[int]int, ans []int) {
	q := NewPriorityQueue(len(d))
	q.push(node{1, 0})
	for q.len() > 0 {
		n := q.pop()
		if ans[n.a] <= n.x {
			continue
		}
		ans[n.a] = n.x
		for nn, x := range d[n.a] {
			if ans[nn] > n.x+x {
				q.push(node{nn, n.x + x})
			}
		}
	}
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	ans := make([]int, n+1)
	d := make([]map[int]int, n+1)
	for i := 1; i <= n; i++ {
		ans[i] = 1 << 60
	}
	for i := 1; i < n; i++ {
		a, b, x := io.NextInt(), io.NextInt(), io.NextInt()
		d[i] = make(map[int]int)
		d[i][i+1] = a
		d[i][x] = b
		if i+1 == x {
			d[i][x] = min(a, b)
		}
	}
	d[n] = make(map[int]int)
	Dijkstra(d, ans)
	fmt.Println(ans[n])
}
