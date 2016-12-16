package main

import (
	"fmt"
)

func FindIndex(arr []float64, value float64) int {
	for i := 0; i < len(arr); i++ {
		if arr[i] >= value {
			return i + 1
		}
	}
	return 0
}

func main() {
	arr := make([]float64, 0, 1000)
	arr = append(arr, 0.5)
	for i := 1; arr[i-1] < 5.20; i++ {
		arr = append(arr, arr[i-1] + 1.0/(2.0+float64(i)))
	}
	//fmt.Println(len(arr))
	value := 0.0
	fmt.Scan(&value)
	for value != 0.0 {
		fmt.Println(FindIndex(arr, value), "card(s)")
		fmt.Scan(&value)
	}
}