package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func max(a, b int64) int64 {
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
	num, m, lim int64
	mp, dp      map[int64]int64
)

func search(n int64) {
	if _, ok := dp[n]; !ok {
		if _, ok := mp[(n+1)%m]; ok {
			x := mp[n]
			delete(mp, n)
			search((n + 1) % m)
			mp[n] = x
			dp[n] = mp[n]*n + dp[(n+1)%m]
		} else {
			dp[n] = mp[n] * n
		}
	}
}

var sc = bufio.NewScanner(os.Stdin)

func nextInt64() int64 {
	sc.Scan()
	ret, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return int64(ret)
}

func main() {
	sc.Split(bufio.ScanWords)

	var x, ans, s int64
	s = 0
	num, m = nextInt64(), nextInt64()
	mp = map[int64]int64{}
	dp = map[int64]int64{}
	for i := int64(0); i < num; i++ {
		x = nextInt64()
		mp[x]++
		ans += x
	}
	for k, _ := range mp {
		lim = k
		search(k)
		s = max(s, dp[k])
	}
	fmt.Println(ans - s)
}
