package main

import (
    "bufio"
    "fmt"
    "os"
)

var scores = map[string]int{
    "B X": 1,
    "C Y": 2,
    "A Z": 3,
    "A X": 4,
    "B Y": 5,
    "C Z": 6,
    "C X": 7,
    "A Y": 8,
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
