package main

import "fmt"

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

var (
	num int
	s   string
)

func main() {
	var ans, k int64 = 0, 1

	fmt.Scan(&s)
	for i := 0; i < len(s); i++ {
		ans += k * int64(s[len(s)-i-1]-'A'+1)
		k *= 26
	}
	fmt.Println(ans)
}
