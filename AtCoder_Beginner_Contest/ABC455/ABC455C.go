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

type priorityQueue struct {
	data []pair
	comp func(i, j int) bool
}

func NewPriorityQueue(size int) *priorityQueue {
	p := &priorityQueue{
		data: make([]pair, 0, size),
	}
	p.comp = func(i, j int) bool {
		return p.data[i].x > p.data[j].x
	}
	return p
}

func (q *priorityQueue) push(x pair) {
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

func (q *priorityQueue) pop() pair {
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

func (q *priorityQueue) top() pair {
	return q.data[0]
}

func (q *priorityQueue) len() int {
	return len(q.data)
}

type pair struct {
	k, x int
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, k := io.NextInt(), io.NextInt()
	d := make(map[int]int, n)
	pq := NewPriorityQueue(n)
	for i := 0; i < n; i++ {
		a := io.NextInt()
		d[a] += a
	}
	for k, v := range d {
		pq.push(pair{k, v})
	}
	for k > 0 && pq.len() > 0 {
		pq.pop()
		k--
	}
	ans := 0
	for pq.len() > 0 {
		ans += pq.pop().x
	}
	fmt.Println(ans)
}
