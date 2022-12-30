package main

import "fmt"

var (
	s  string
	mp = map[byte]int{}
)

func main() {
	fmt.Scan(&s)
	if a, _ := search(0); a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func search(n int) (bool, int) {
	ans := true
	x := map[byte]int{}
	for i := n; i < len(s); i++ {
		if s[i] == '(' {
			a, b := search(i + 1)
			ans = ans && a
			i = b
		} else if s[i] == ')' {
			for k, _ := range x {
				delete(mp, k)
			}
			return ans, i
		} else {
			if _, ok := mp[s[i]]; ok {
				ans = false
				break
			} else {
				mp[s[i]] = 1
				x[s[i]] = 1
			}
		}
	}
	return ans, len(s)
}
