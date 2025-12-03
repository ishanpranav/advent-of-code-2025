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
```

### Part A

```
result := 0

foreach (minI, maxI) in input:
    let minK := ⌈(log_10(minI) + 1) / 2⌉
    let maxK := ⌊(log_10(maxI) + 1) / 2⌋

    foreach k in (minK, ..., maxK):
        let minX := max(10^(k - 1), ⌈minI / (10^k + 1)⌉)
        let maxX := min(10^k - 1, ⌊maxI / (10^k + 1)⌋)

        result := result + [sum of x = minX to maxX over (x * 10^k + x)]
```

### Part B

```
```
