package main

import "fmt"

var mp map[int64]int64

func main() {
	var (
		num int64
	)
	mp = map[int64]int64{0: 1}
	fmt.Scan(&num)
	fmt.Println(f(num))
}

func f(x int64) int64 {
	if a, ok := mp[x]; ok {
		return a
	} else {
		mp[x] = f(x/2) + f(x/3)
		return mp[x]
	}
}
