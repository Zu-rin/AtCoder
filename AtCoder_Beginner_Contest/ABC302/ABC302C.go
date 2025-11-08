package main

import (
	"fmt"
)

func next_permutation(arr []int) bool {
	i := len(arr) - 1
	for i > 0 && arr[i-1] >= arr[i] {
		i--
	}
	if i <= 0 {
		return false
	}
	j := len(arr) - 1
	for arr[j] <= arr[i-1] {
		j--
	}
	arr[i-1], arr[j] = arr[j], arr[i-1]
	j = len(arr) - 1
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
	return true
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	s := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}
	d := make([][]int, n)
	for i := 0; i < n; i++ {
		d[i] = make([]int, n)
		for j := 0; j < n; j++ {
			diff := 0
			for k := 0; k < m; k++ {
				if s[i][k] != s[j][k] {
					diff++
				}
			}
			if diff == 1 {
				d[i][j] = 1
			} else {
				d[i][j] = 0
			}
		}
	}
	x := make([]int, n)
	for i := 0; i < n; i++ {
		x[i] = i
	}
	for {
		for i := 0; i < n-1; i++ {
			if d[x[i]][x[i+1]] == 0 {
				break
			}
			if i == n-2 {
				fmt.Println("Yes")
				return
			}
		}
		if !next_permutation(x) {
			break
		}
	}
	fmt.Println("No")
}
