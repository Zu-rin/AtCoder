package main

import "fmt"

func main() {
	var (
		s string
	)
	fmt.Scan(&s)
	ans := 0
	for i := 0; i < len(s); i++ {
		if i < len(s)-1 && s[i] == '0' && s[i+1] == '0' {
			i++
		}
		ans++
	}
	fmt.Println(ans)
}
