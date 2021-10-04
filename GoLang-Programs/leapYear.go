package main

import "fmt"

func leapYear(n int) {
	if n%4 == 0 {
		if n%100 != 0 {
			fmt.Println("Leap")
		} else {
			fmt.Println("Not Leap ")
		}
	} else {
		fmt.Println("Not Leap ")
	}
}
func main() {
	leapYear(2020) 
}
