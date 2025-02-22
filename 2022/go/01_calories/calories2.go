package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    elf_count := 1
    elves := make([]int, 3)
    calories := make([]int, 3)

    file, err := os.Open("input")
    if err != nil {
        fmt.Fprintf(os.Stderr, "%s", err)
    }
    defer file.Close()

    buf := bufio.NewScanner(file)

    elf := ""
    for buf.Scan() {
        fmt.Printf("\n Elf %d\n -------\n", elf_count)

        elf = buf.Text()
        if elf == "" {
            continue
        }

        total := 0
        for i := 1; elf != "" && buf.Scan(); i++ {
            calories, _ := strconv.Atoi(elf)
            fmt.Printf("%2d: %d\n", i, calories)
            total += calories
            elf = buf.Text()
        }

        fmt.Printf("total: %d\n", total)
        if total > calories[0] {
            calories[2] = calories[1]
            calories[1] = calories[0]
            calories[0] = total
            elves[2] = elves[1]
            elves[1] = elves[0]
            elves[0] = elf_count
        }
        elf_count++
    }
    fmt.Println("")

    total := 0
    for i, v := range calories {
        fmt.Printf("Elf %d: %d\n", elves[i], v)
        total += v
    }

    fmt.Printf("\nElf %d has them most calories: %d", elves[0], calories[0])
    fmt.Printf("\nSum of three largest elves: %d", total)
}

// https://kgrz.io/reading-files-in-go-an-overview.html
