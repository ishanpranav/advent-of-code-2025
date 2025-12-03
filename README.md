# Advent of Code 2025

Efficient Advent of Code 2025 solutions in C language

## Day 1: Secret Entrance

```
given input

let dial := 50
let count := 0
```

### Part A

```
foreach (direction, distance) in input:
    if direction = 'L' then negate distance

    dial := (dial + distance) mod 100

    if dial = 0 then increment count

return count
```

### Part B

```
foreach (direction, distance) in input:
    if direction = 'L' then negate distance

    let nextDial := dial + distance

    if dial ≠ 0 and nextDial < 0 then increment count

    count := count + ⌊|dial| / 100⌋

    if nextDial = 0 then increment count

    dial := nextDial mod 100

return count
```

## Day 2: Gift Shop

```
given input

let result := 0
```

### Part A

```

foreach (left, right) in input:
    let minK := ⌈(log_10(left) + 1) / 2⌉
    let maxK := ⌊(log_10(right) + 1) / 2⌋

    foreach k in (minK, ..., maxK):
        let mask := 10^k + 1
        let minX := max(10^(k - 1), ⌈left / mask⌉)
        let maxX := min(10^k - 1, ⌊right / mask⌋)

        result := result + [sum of x = minX to maxX over (x * mask)]

return result
```

### Part B

```
foreach (left, right) in input:
    let maxK := ⌊log_10(right)⌋ + 1

    foreach k in (1, ..., maxK):
        let maxR := maxK / k

        foreach r in (2, ..., maxR):
            let mask := (10^(k * r) - 1) / (10^k - 1)
            let minX := max(10^(k - 1), ⌈left / mask⌉)
            let maxX := min(10^k - 1, ⌊right / mask⌋)

            result := result + [sum of x = minX to maxX over (x * mask)]

return result
```

### Day 3: Lobby

```
given input
let result := 0

foreach (a_1, ..., a_n) in input:
    let first := a_1
    let second := a_2

    for i in (3, ..., n - 1):
        if a_i > first then:
            first := a_i
            second := a_[i + 1]
            continue
        
        if a_i > second then second := a_i

    result := (first * 10) + second
```
