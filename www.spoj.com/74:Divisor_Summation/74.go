package main

import (
	"fmt"
	"math"
)

func solve(num int) {
	if num == 1 {
		fmt.Println(0)
		return
	}
	sum := 1
	sqrt := int(math.Sqrt(float64(num)))
	for i := 2; i <= sqrt; i++ {
		if(num % i != 0) {
			continue
		}
		
		another := num / i
		sum += i
		if another != i {
			sum += another
		}
	}
	fmt.Println(sum)
}

func main() {
	var caseCount int
	fmt.Scan(&caseCount)
	for i := 0; i < caseCount; i++ {
		var number int
		fmt.Scan(&number)
		solve(number)
	}
}
