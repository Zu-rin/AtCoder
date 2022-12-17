package main

import "fmt"

func main() {
	var (
		num, t, sum int64 = 0, 0, 0
	)
	fmt.Scan(&num, &t)
	d := make([]int64, num)
	for i := int64(0); i < num; i++ {
		fmt.Scan(&d[i])
		sum += d[i]
	}
	t %= sum
	for i := int64(0); i < num; i++ {
		if t < d[i] {
			fmt.Println(i+1, t)
			break
		}
		t -= d[i]
	}
}
