package main

import (
	"fmt"
	"sort"
)

func main() {
	testCases := 0
	fmt.Scan(&testCases)
	for i := 0; i < testCases; i++ {
		count := 0
		fmt.Scan(&count)
		men := make([]int, count)
		women := make([]int, count)
		for j := 0; j < count; j++ {
			fmt.Scan(&men[j])
		}
		sort.Ints(men)
		for j := 0; j < count; j++ {
			fmt.Scan(&women[j])
		}
		sort.Ints(women)
		sum := 0
		for j := 0; j < count; j++ {
			sum += men[j]*women[j]
		}
		fmt.Println(sum)
	}
}