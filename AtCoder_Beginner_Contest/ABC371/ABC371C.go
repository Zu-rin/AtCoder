package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
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

func next_permutation(arr sort.Interface) bool {
	len := arr.Len() - 1
	i := len
	for i > 0 && !arr.Less(i-1, i) {
		i--
	}
	if i <= 0 {
		return false
	}
	j := len
	for !arr.Less(i-1, j) {
		j--
	}
	arr.Swap(i-1, j)
	j = len
	for i < j {
		arr.Swap(i, j)
		i++
		j--
	}
	return true
}

func createEdges(n int, io *Io) [][]bool {
	ans := make([][]bool, n)
	for i := 0; i < n; i++ {
		ans[i] = make([]bool, n)
	}
	m := io.NextInt()
	for i := 0; i < m; i++ {
		a, b := io.NextInt()-1, io.NextInt()-1
		ans[a][b] = true
		ans[b][a] = true
	}
	return ans
}

func cost(a, b [][]bool, d [][]int, k []int, n int) int {
	ans := 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			if a[i][j] != b[k[i]][k[j]] {
				ans += d[k[i]][k[j]]
			}
		}
	}
	return ans
}

func main() {
	io := NewIo(os.Stdin, os.Stdout)
	defer io.Out.Flush()
	n := io.NextInt()
	a := createEdges(n, io)
	b := createEdges(n, io)
	k := []int{0, 1, 2, 3, 4, 5, 6, 7}[:n]
	d := make([][]int, n)
	for i := 0; i < n; i++ {
		d[i] = make([]int, n)
	}
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			x := io.NextInt()
			d[i][j] = x
			d[j][i] = x
		}
	}
	ans := 1 << 60
	for {
		ans = min(ans, cost(a, b, d, k, n))
		if !next_permutation(sort.IntSlice(k)) {
			break
		}
	}
	fmt.Println(ans)
}
