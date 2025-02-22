package main

import (
    "bufio"
    "fmt"
    "os"
    "unicode"
)

func main() {
    file, err := os.Open("input")
    if err != nil {
        fmt.Fprintf(os.Stderr, "%s", err)
    }
    defer file.Close()

    buf := bufio.NewScanner(file)

    total := 0
    for buf.Scan() {
        line := buf.Text()
        found := search(line)

        fmt.Printf("line: ")
        for _, v := range line {
            if found == v {
                fmt.Printf("(%c)", found)
            } else {
                fmt.Printf("%c", v)
            }
        }
        fmt.Printf("\nfound: %c\n", found)
        s := get_score(found)
        fmt.Printf("score: %d\n\n", s)
        total += s
    }
    fmt.Printf("total: %d", total)
}

func search(s string) rune {
    l := len(s)

    // split
    a := s[:l/2]
    b := s[l/2:]

    // search
    for _, i := range a {
        for _, j := range b {
            if i == j {
                return i
            }
        }
    }
    return 0
}

func get_score(found rune) int {
    if unicode.IsLower(found) {
        return int(found) - 96
    }
    return int(found) - 38
}
