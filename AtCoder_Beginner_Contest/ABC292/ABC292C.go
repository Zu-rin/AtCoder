package main

import (
	"fmt"
)

func main() {
	var n uint64
	fmt.Scan(&n)
	d := make([]uint64, n)
	d[1] = 1
	for i := uint64(2); i < n; i++ {
		a := make(map[uint64]uint64)
		x := i
		for j := uint64(2); j*j <= i; j++ {
			for x%j == 0 {
				x /= j
				a[j]++
			}
		}
		d[i] = 1
		if x > 1 {
			d[i] = 2
		}
		for _, v := range a {
			d[i] *= v + 1
		}
	}
	ans := uint64(0)
	for i := uint64(1); i <= n>>1; i++ {
		if i != n-i {
			ans += d[i] * d[n-i] * 2
		} else {
			ans += d[i] * d[i]
		}
	}
	fmt.Println(ans)
}
