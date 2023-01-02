package main

import "fmt"

var (
	num        int
	p, q, r, x int64
)

func binarySearch(d []int64, tag int64) int {
	l, r := 0, len(d)
	tag += d[0]
	for l+1 < r {
		m := (l + r) / 2
		if d[m] <= tag {
			l = m
		} else {
			r = m
		}
	}
	if d[l] == tag {
		return l
	} else {
		return -1
	}
}

func main() {
	ok := false
	fmt.Scan(&num, &p, &q, &r)
	dp := make([]int64, num+1)
	for i := 0; i < num; i++ {
		fmt.Scan(&x)
		dp[i+1] = dp[i] + x
	}
	for a, b := 0, 1; b <= num; {
		if dp[b]-dp[a] < p {
			b++
		} else if dp[b]-dp[a] == p {
			if c := binarySearch(dp[b:], q); c >= 0 {
				if binarySearch(dp[b+c:], r) >= 0 {
					ok = true
					break
				}
			}
			b++
		} else {
			a++
		}
	}
	if ok {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
