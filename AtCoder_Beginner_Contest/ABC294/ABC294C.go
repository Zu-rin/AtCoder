package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, n)
	ansa := make([]int, n)
	b := make([]int, m)
	ansb := make([]int, m)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < m; i++ {
		fmt.Scan(&b[i])
	}
	i, j, ans := 0, 0, 0
	for i < n || j < m {
		ans++
		if i == n {
			ansb[j] = ans
			j++
		} else if j == m {
			ansa[i] = ans
			i++
		} else if a[i] < b[j] {
			ansa[i] = ans
			i++
		} else {
			ansb[j] = ans
			j++
		}
	}
	for i = 0; i < n-1; i++ {
		fmt.Print(ansa[i])
		fmt.Print(" ")
	}
	fmt.Println(ansa[n-1])
	for i = 0; i < m-1; i++ {
		fmt.Print(ansb[i])
		fmt.Print(" ")
	}
	fmt.Println(ansb[m-1])
}
