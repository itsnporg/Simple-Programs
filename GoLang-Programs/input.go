package main

import "fmt"

func main() {
	fmt.Printf("Hello, what is your name? : ")
	var name string
	fmt.Scanln(&name)
	fmt.Printf("what year were you born? : ")
	var age int
	fmt.Scanln(&age)
	fmt.Print("Nice to meet you ", name, " you are ", 2021-age, " years old!")
}
