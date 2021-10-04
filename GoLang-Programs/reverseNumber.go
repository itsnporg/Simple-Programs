package main

import (
	"fmt"
	"strconv"
)

func reverseNumber(number int) int {
	strNumber := strconv.Itoa(number)
	reverseStrNumber := ""
	for length := len(strNumber); length > 0; length-- {
		reverseStrNumber += string(strNumber[length-1])
	}
	reverseNum, error := strconv.Atoi(reverseStrNumber)
	if error != nil {
		fmt.Println("invalid")
	}
	return reverseNum
}

func main() {
	fmt.Printf("%d reverse is %d \n", 1234, reverseNumber(1234))
	fmt.Printf("%d reverse is %d \n", 2987, reverseNumber(2987))

}
