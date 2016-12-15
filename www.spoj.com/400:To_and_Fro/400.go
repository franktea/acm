package main

import (
	"fmt"
)

func main() {
	var rowCount int
	fmt.Scan(&rowCount)
	for rowCount != 0 {
		var line string
		fmt.Scan(&line)
		arr := make([][]byte, 0, len(line)/rowCount)
		for i := 0; i < len(line)/rowCount; i++ {
			arr = append(arr, make([]byte, rowCount))
			if i % 2 == 0 {
				for j := 0; j < rowCount; j++ {
					arr[i][j] = line[i*rowCount + j]
				}
			} else {
				for j := 0; j < rowCount; j++ {
					arr[i][j] = line[(i+1)*rowCount - 1 -j];
				}
			}
		}
		for j := 0; j < rowCount; j++ {
			for i := 0; i < len(arr); i++ {
				fmt.Print(string(arr[i][j]))
			}
		}
		fmt.Println("")
		fmt.Scan(&rowCount)
	}
}
