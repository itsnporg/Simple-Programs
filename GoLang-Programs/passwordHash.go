package main

import (
	"bufio"
	"fmt"
	"os"

	"golang.org/x/crypto/bcrypt"
)

func HashPasswordString(password string) (string, error) {
	bytes, err := bcrypt.GenerateFromPassword([]byte(password), 14)
	return string(bytes), err
}

func CheckPassword(password, hash string) bool {
	err := bcrypt.CompareHashAndPassword([]byte(hash), []byte(password))
	return err == nil
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter password : ")
	password, _ := reader.ReadString('\n')
	hash, _ := HashPasswordString(password)

	fmt.Println("password : ", password)
	fmt.Println("hash:    ", hash)

	match := CheckPassword(password, hash)
	fmt.Println("match:   ", match)
}
