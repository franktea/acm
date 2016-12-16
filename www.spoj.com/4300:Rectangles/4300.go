package main

import (
	"fmt"
	"math"
)

func solve(number int) {
	n := int(math.Sqrt(float64(number)))
	count := 0
	for i := 1; i <= n; i++ {
		for j := i; j <= number; j++ {
			if i * j <= number {
				count++
			} else {
				continue
			}
		}
	}
		fmt.Println(count)
}

func main() {
	var number int
	fmt.Scan(&number)
	solve(number)
}