package main

import "fmt"

func main() {
	var (
		num int
		s   string
	)
	fmt.Scan(&num, &s)
	ans := make([]byte, 0, num)
	in := false
	for i := 0; i < num; i++ {
		if s[i] == '"' {
			in = !in
			ans = append(ans, '"')
		} else {
			if s[i] == ',' {
				if in {
					ans = append(ans, s[i])
				} else {
					ans = append(ans, '.')
				}
			} else {
				ans = append(ans, s[i])
			}
		}
	}
	fmt.Println(string(ans))
}
