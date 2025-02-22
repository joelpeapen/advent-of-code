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
        l1 := buf.Text()
        buf.Scan()
        l2 := buf.Text()
        buf.Scan()
        l3 := buf.Text()
        found := search(l1, l2, l3)

        fmt.Printf("a: %s\nb: %s\nc: %s ", l1, l2, l3)
        fmt.Printf("\nfound char: %c\n", found)
        s := get_score(found)
        fmt.Printf("score: %d\n\n", s)
        total += s
    }
    fmt.Printf("total: %d", total)
}

func search(a string, b string, c string) rune {
    for _, i := range a {
        for _, j := range b {
            for _, k := range c {
                if i == j && i == k {
                    return i
               }
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
