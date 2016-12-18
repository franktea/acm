package main

import (
	"fmt"
)

func main() {
	var num int
	fmt.Scan(&num)
	fmt.Print("W")
	for i := 0; i <num; i++ {
		fmt.Print("o")
	}
	fmt.Println("w")
}