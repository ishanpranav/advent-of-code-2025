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
sum := 0

foreach (iMin, iMax) in input:
    let nMin := ⌊log_10(iMin)⌋ + 1
    let kMin := (nMin + (nMin mod 2)) / 2
    let nMax := ⌊log_10(iMax)⌋ + 1
    let kMax := (nMax - (nMax mod 2)) / 2

    foreach k in (kMin, ..., kMax):
        let xMin := 10^(k - 1)
        
        xMin := max(xMin, ⌊iMin / 10^(nMin - k)⌋)
        
        let xMax := 10^k - 1
        
        xMax := min(xMax, ⌊iMax / 10^(nMax - k)⌋)

        foreach x in (xMin, ... xMax):
            x * 10^(2 * k) + x

```

### Part B

```
```
