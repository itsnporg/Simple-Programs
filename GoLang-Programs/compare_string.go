package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(strings.Compare("Hacker", "Haler"))
	fmt.Println(strings.Compare("HAcker", "Hacker"))
	fmt.Println(strings.Compare("Hacker", "Hacker"))
}
