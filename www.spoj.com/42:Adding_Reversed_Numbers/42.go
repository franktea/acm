package main

import (
	"fmt"
)

func reverse(number int) int {
	var result int = 0
	for number != 0 {
		result = result * 10 + number % 10
		number /= 10
	}
	return result
}

func main() {
	var caseCount int
	fmt.Scan(&caseCount)
	for i := 0; i < caseCount; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		fmt.Println(reverse(reverse(a) + reverse(b)))
	}
}
