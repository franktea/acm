package main

import (
	"fmt"
)

func main() {
	var caseCount int
	fmt.Scan(&caseCount)
	for i := 0; i < caseCount; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		if a == b || a == b + 2 {
			if a % 2 == 0 {
				fmt.Println(a+b)
			} else {
				fmt.Println(a+b-1)
			}
		} else {
			fmt.Println("No Number")
		}
	}
}