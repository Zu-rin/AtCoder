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

func chmax(a, b *int64) {
	if *a < *b {
		*a = *b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

var (
	num int
)

func main() {
	k := 0
	fmt.Scan(&num)
	t, x, a := make([]int, num), make([]int, num), make([]int64, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&t[i], &x[i], &a[i])
	}
	dp := make([][]int64, 5)
	for i := 0; i < 5; i++ {
		dp[i] = make([]int64, 100002)
		for j := 0; j < len(dp[i]); j++ {
			dp[i][j] = math.MinInt64
		}
	}
	dp[0][0] = 0
	for j := 0; j < len(dp[0])-1; j++ {
		if k < num && j == t[k] {
			dp[x[k]][t[k]] += a[k]
			k++
		}
		for i := 0; i < 5; i++ {
			chmax(&dp[max(0, i-1)][j+1], &dp[i][j])
			chmax(&dp[i][j+1], &dp[i][j])
			chmax(&dp[min(4, i+1)][j+1], &dp[i][j])
		}
	}
	var ans int64 = math.MinInt64
	for i := 0; i < 5; i++ {
		chmax(&ans, &dp[i][100001])
	}
	fmt.Println(ans)
}
