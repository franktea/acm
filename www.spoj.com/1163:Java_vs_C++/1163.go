package main

//spoj 1163	Java vs C ++
// spoj has go 1.4.2, got runtime error, but can't find the problem on go 1.7
import (
	"fmt"
	"bufio"
	"os"
	"bytes"
	"strings"
)

func Solve(str string) {
	if strings.Contains(str, "_") {
		words := strings.Split(str, "_")
		for i := 0; i < len(words); i++ {
			if strings.ToLower(words[i]) != words[i] {
				fmt.Println("Error!")
				return
			}
		}
		for i := 0; i < len(words); i++ {
			if i == 0 {
				fmt.Print(words[i])
				continue
			}
			
			fmt.Print(strings.ToUpper(words[i][:1]))
			fmt.Print(words[i][1:])
		}
		fmt.Println("")
		return
	}
	
	if strings.ToLower(str) == str {
		fmt.Println(str)
		return
	}
	
	var first byte = byte(str[0])
	if first >= 'A' && first <= 'Z' {
		fmt.Println("Error!")
		return
	}
	
	fmt.Print(string(first))
	str = str[1:]
	for _, v := range str {
		var b byte = byte(v)
		if b >= 'A' && b <= 'Z' {
			fmt.Print("_", string('a' + b - 'A'))
		} else {
			fmt.Print(string(b))
		}
	}
	fmt.Println("")
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadBytes('\n')
		if err != nil {
			break
		}
		line = bytes.TrimRight(line, "\r\n")
		if len(line) == 0 {
			break
		}
		Solve(string(line))
	}
}