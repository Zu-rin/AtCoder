package main

import "fmt"

func main() {
	var i int
	var s, t string
	fmt.Scan(&s, &t)
	for i = 0; i < len(s); i++ {
		if s[i] != t[i] {
			break
		}
	}
	fmt.Println(i + 1)
}
