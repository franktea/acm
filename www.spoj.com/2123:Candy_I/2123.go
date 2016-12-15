package main

import (
	"fmt"
)

func solve(lineCount int) {
	arr := make([]int, 0)
	var sum int = 0
	for i := 0; i < lineCount; i++ {
		var number int
		fmt.Scan(&number)
		arr = append(arr, number)
		sum += number
	}
	if sum % len(arr) != 0 {
		fmt.Println(-1)
	} else {
		average := sum / len(arr)
		result := 0
		for _, v := range arr {
			if v < average {
				result += average - v
			}
		}
		fmt.Println(result)
	}
}

func main() {
	var lineCount int
	fmt.Scan(&lineCount)
	for lineCount != -1 {
		solve(lineCount)
		fmt.Scan(&lineCount)
	}
}