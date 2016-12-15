package main

import (
	"fmt"
)

func main() {
	var results [101]int
	results[0] = 0
	for i := 1; i < 101; i++ {
		results[i] = i*i + results[i - 1]
	}
	var number int
	for fmt.Scan(&number); number != 0; fmt.Scan(&number) {
		fmt.Println(results[number])
	}
}