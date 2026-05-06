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

type priorityQueueMax struct {
	data []int
	comp func(i, j int) bool
}

func NewPriorityQueueMax(size int) *priorityQueueMax {
	p := &priorityQueueMax{
		data: make([]int, 0, size),
	}
	p.comp = func(i, j int) bool {
		return p.data[i] > p.data[j]
	}
	return p
}

func (q *priorityQueueMax) push(x int) {
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

func (q *priorityQueueMax) pop() int {
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

func (q *priorityQueueMax) top() int {
	return q.data[0]
}

func (q *priorityQueueMax) len() int {
	return len(q.data)
}

type priorityQueueMin struct {
	data []int
	comp func(i, j int) bool
}

func NewPriorityQueueMin(size int) *priorityQueueMin {
	p := &priorityQueueMin{
		data: make([]int, 0, size),
	}
	p.comp = func(i, j int) bool {
		return p.data[i] < p.data[j]
	}
	return p
}

func (q *priorityQueueMin) push(x int) {
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

func (q *priorityQueueMin) pop() int {
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

func (q *priorityQueueMin) top() int {
	return q.data[0]
}

func (q *priorityQueueMin) len() int {
	return len(q.data)
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n, k := io.NextInt(), io.NextInt()
	d, del := make(map[int]int, n), make(map[int]bool, n)
	mi, ma := NewPriorityQueueMin(n), NewPriorityQueueMax(n)
	for i := 0; i < n; i++ {
		x := io.NextInt()
		d[x] = i
	}
	for i := 1; i <= k; i++ {
		mi.push(d[i])
		ma.push(d[i])
	}
	ans := ma.top() - mi.top()
	for i := 1; i <= n-k; i++ {
		del[d[i]] = true
		for mi.len() > 0 && del[mi.top()] {
			mi.pop()
		}
		for ma.len() > 0 && del[ma.top()] {
			ma.pop()
		}
		mi.push(d[i+k])
		ma.push(d[i+k])
		ans = min(ans, ma.top()-mi.top())
	}
	fmt.Println(ans)
}
