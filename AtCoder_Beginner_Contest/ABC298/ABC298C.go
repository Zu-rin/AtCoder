package main

import (
	"bytes"
	"fmt"
	"sort"
	"strings"
)

func sorted_keys(m map[int]int) []int {
	keys := []int{}
	for k := range m {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	return keys
}

func main() {
	var n, q, k, a, b int
	fmt.Scan(&n, &q)
	n = 200000
	x := make([]map[int]int, n+1)
	y := make([]map[int]int, n+1)
	for i := 0; i <= n; i++ {
		x[i] = make(map[int]int)
		y[i] = make(map[int]int)
	}
	for i := 0; i < q; i++ {
		fmt.Scan(&k)
		switch k {
		case 1:
			fmt.Scan(&a, &b)
			x[b][a]++
			y[a][b]++
		case 2:
			fmt.Scan(&a)
			keys := sorted_keys(x[a])
			ans := []string{}
			for _, v := range keys {
				buf := []byte(fmt.Sprintf("%d ", v))
				ans = append(ans, strings.TrimSpace(string(bytes.Repeat(buf, x[a][v]))))
			}
			fmt.Println(strings.Join(ans, " "))
		case 3:
			fmt.Scan(&a)
			keys := sorted_keys(y[a])
			ans := []string{}
			for _, v := range keys {
				ans = append(ans, fmt.Sprintf("%d", v))
			}
			fmt.Println(strings.Join(ans, " "))
		}
	}
}
