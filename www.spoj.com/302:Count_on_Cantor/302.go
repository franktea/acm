package main

import (
	"fmt"
	"math"
)

func FindLine(number int) int {
	if number == 1 {
		return 1
	}
	guess := int(math.Sqrt(float64(number*2)))
	for i := guess-1; i <= guess+1; i++ {
		if i*(i-1)/2+1 <= number && i*(i+1)/2 >= number {
			return i
		}
	}
	panic("impssible")
}

func FindValue(lineNo, number int) {
	if number == 1 {
		fmt.Println("TERM 1 IS 1/1")
		return
	}
	
	if lineNo % 2 == 0 {
		// from right to left
		fmt.Printf("TERM %d IS %d/%d\n", number, number - lineNo*(lineNo-1)/2, lineNo + 1 + lineNo*(lineNo-1)/2 - number) 
	} else {
		// from left to right
		fmt.Printf("TERM %d IS %d/%d\n", number, lineNo + 1 + lineNo*(lineNo-1)/2 - number, number - lineNo*(lineNo-1)/2)
	}
}

func main() {
	caseCount := 0
	fmt.Scan(&caseCount)
	for i := 0; i <caseCount; i++ {
		number := 0
		fmt.Scan(&number)
		FindValue(FindLine(number), number)
	}
}