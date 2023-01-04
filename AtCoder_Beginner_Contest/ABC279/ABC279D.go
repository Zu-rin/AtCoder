package main

import (
	"fmt"
	. "math"
)

var (
	A, B int64
	a, b float64
)

func time(g int64) float64 {
	return a/Sqrt(float64(g)) + float64(B*(g-1))
}

func diff(g int64) float64 {
	return b - a/2.0/Pow(float64(g), 1.5)
}

func main() {
	fmt.Scan(&A, &B)
	a, b = float64(A), float64(B)
	ans := a
	var l, r int64 = 1, A/B + 1
	for l+1 < r {
		p := (l + r) / 2
		if diff(p) <= 0 {
			l = p
		} else {
			r = p
		}
	}
	for i := l - 10; i < l+10; i++ {
		if i <= 0 {
			continue
		}
		ans = Min(ans, time(i))
	}
	fmt.Println(ans)
}
