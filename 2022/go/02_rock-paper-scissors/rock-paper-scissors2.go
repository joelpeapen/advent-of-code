package main

import (
    "bufio"
    "fmt"
    "os"
)

var scores = map[string]int{
    "B X": 1,
    "C X": 2,
    "A X": 3,
    "A Y": 4,
    "B Y": 5,
    "C Y": 6,
    "C Z": 7,
    "A Z": 8,
    "B Z": 9,
}

func main() {
    file, err := os.Open("input")
    if err != nil {
        fmt.Fprintf(os.Stderr, "%s", err)
    }
    defer file.Close()

    buf := bufio.NewScanner(file)

    score := 0
    for buf.Scan() {
        score += scores[buf.Text()]
    }
    fmt.Println(score)
}
