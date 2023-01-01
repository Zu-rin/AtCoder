package main

import (
	"fmt"
	"math"
)

var (
	num, x int
)

func main() {
	ans := 0
	mi2 := 50
	mi3 := 50
	mp := map[int]int{}
	fmt.Scan(&num)
	for i := 0; i < num; i++ {
		a := 0
		b := 0
		fmt.Scan(&x)
		for x%2 == 0 {
			a++
			x >>= 1
		}
		for x%3 == 0 {
			b++
			x /= 3
		}
		mi2 = int(math.Min(float64(mi2), float64(a)))
		mi3 = int(math.Min(float64(mi3), float64(b)))
		ans += a + b
		mp[x] = 0
	}
	if len(mp) == 1 {
		fmt.Println(ans - (mi2+mi3)*num)
	} else {
		fmt.Println(-1)
	}
}
