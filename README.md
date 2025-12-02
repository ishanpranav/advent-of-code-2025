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

    count := count + (|dial| / 100)

    if nextDial = 0 then increment count

    dial := nextDial mod 100

return count
```
