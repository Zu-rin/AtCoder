package main

import (
	"fmt"
	"math"
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

type eratos struct {
	d []bool
	p []int64
	a int
}

func newEratos(n int) *eratos {
	d := make([]bool, n+1)
	p := make([]int64, 0)
	for i := 2; i < len(d); i++ {
		if !d[i] {
			p = append(p, int64(i))
			for j := i << 1; j < len(d); j += i {
				d[j] = true
			}
		}
	}
	return &eratos{
		d: d,
		p: p,
		a: 0,
	}
}

var (
	t, num int
)

func main() {
	fmt.Scan(&t)
	e := newEratos(3000000)
	for i := 0; i < t; i++ {
		var x int64
		fmt.Scan(&x)
		for j := 0; j < len(e.p); j++ {
			if x%e.p[j] == 0 {
				var a, b int64
				x /= e.p[j]
				if x%e.p[j] == 0 {
					a, b = e.p[j], x/e.p[j]
				} else {
					a, b = int64(math.Sqrt(float64(x))), e.p[j]
					for k := int64(-5); k < 5; k++ {
						if (a+k)*(a+k) == x {
							a += k
							break
						}
					}
				}
				fmt.Printf("%v %v\n", a, b)
				break
			}
		}
	}
}
