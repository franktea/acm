package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	for fmt.Scan(&a, &b, &c); !(a == 0 && b == 0 && c == 0); fmt.Scan(&a, &b, &c) {
		if b - a == c - b && b != a {
			fmt.Println("AP", c + b-a)
		} else {
			fmt.Println("GP", c * b / a)
		}
	}
}