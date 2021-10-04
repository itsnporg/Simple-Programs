package main

import "fmt"

func odd_Even(n int) { 
	if n%2 == 0 {
		fmt.Println("It's even")
	} else {
		fmt.Println("It's odd")
	}
}

func main() {
	odd_Even(112)

}
