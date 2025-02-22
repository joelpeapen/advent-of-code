package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    elf_count, max, max_elf := 1, 0, 0

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
        if total > max {
            max = total
            max_elf = elf_count
        }
        elf_count++
    }

    fmt.Printf("\nElf %d has %d calories", max_elf, max)
}
