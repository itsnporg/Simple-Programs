package main

import (
	"fmt"
	"math/rand"
	"net/http"
	"text/template"
)

type todo struct {
	ID    string
	Title string
	Done  bool
}

var mapMake = make(map[string]*todo)

var tmp *template.Template

func init() {
	tmp = template.Must(template.ParseGlob("templates/*.html"))

}

func main() {

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		if r.Method == http.MethodGet {
			tmp.Execute(w, mapMake)
			return
		}
	})

	http.HandleFunc("/addTodo", addTodo)
	http.HandleFunc("/deleteTodo", deleteTodo)
	http.HandleFunc("/completeTodo", completeTodo)

	fmt.Println(http.ListenAndServe(":8000", nil))
}

func addTodo(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		tmp.Execute(w, mapMake)
		return
	}

	ramdomID := randomString()

	mapMake[ramdomID] = &todo{ID: ramdomID, Title: r.FormValue("title"), Done: false}

	http.Redirect(w, r, "/", http.StatusSeeOther)

	tmp.Execute(w, mapMake)

}
func deleteTodo(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		tmp.Execute(w, mapMake)
		return
	}

	id, ok := r.URL.Query()["Id"]

	if !ok || len(id[0]) < 1 {
		fmt.Println("Url Param 'id' is missing")
		return
	}

	delete(mapMake, id[0])

	http.Redirect(w, r, "/", http.StatusSeeOther)

	tmp.Execute(w, mapMake)

}
func completeTodo(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		tmp.Execute(w, mapMake)
		return
	}
	id, ok := r.URL.Query()["Id"]

	if !ok || len(id[0]) < 1 {
		fmt.Println("Url Param 'id' is missing")
		return
	}

	mapMake[id[0]].Done = !mapMake[id[0]].Done

	http.Redirect(w, r, "/", http.StatusSeeOther)

	tmp.Execute(w, mapMake)

}

func randomString() string {
	var letter = []rune("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")

	b := make([]rune, 10)
	for i := range b {
		b[i] = letter[rand.Intn(len(letter))]
	}
	return string(b)
}
