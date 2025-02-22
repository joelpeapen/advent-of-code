package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    file, err := os.Open("input")
    if err != nil {
        fmt.Fprintf(os.Stderr, "%s", err)
    }
    defer file.Close()

    buf := bufio.NewScanner(file)

    total := 0
    a, b, c, d := 0, 0, 0, 0
    for buf.Scan() {
        fmt.Sscanf(buf.Text(), "%d-%d,%d-%d", &a, &b, &c, &d)
        fmt.Printf("\n\n%d-%d", a, b)
        if a <= c && b >= d || c <= a && d >= b {
            total++
            fmt.Printf("\tyes")
        }
        fmt.Printf("\n%d-%d", c, d)
    }

    fmt.Printf("\ntotal: %d", total)
}
