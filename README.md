# Advent of Code 2025

Efficient Advent of Code 2025 solutions in C language

## Day 1: Secret Entrance

```
given input

let dial := 50
let result := 0
```

### Part A

```
foreach (direction, distance) in input:
    if direction = 'L' then negate distance

    dial := (dial + distance) mod 100

    if dial = 0 then increment result

return result
```

### Part B

```
foreach (direction, distance) in input:
    if direction = 'L' then negate distance

    let nextDial := dial + distance

    if dial ≠ 0 and nextDial < 0 then increment result

    result := result + ⌊|dial| / 100⌋

    if nextDial = 0 then increment result

    dial := nextDial mod 100

return result
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

## Day 3: Lobby

```
given input
let result := 0
```

### Part A

```
foreach (a_1, ..., a_n) in input:
    let first := a_1
    let second := a_2

    for i in (2, ..., n - 1):
        if a_i > first then:
            first := a_i
            second := a_[i + 1]
            continue
        
        if a_i > second then second := a_i
    
    if a_n > second then second := a_n

    result := result + (first * 10) + second

return result
```

### Part B

```
foreach (a_1, ..., a_n) in input:
    let S be a stack

    foreach ai in (a_1, ..., a_n):
        while S is not empty
            and [peek S] < ai
            and (n - i + count of S) > 12:
            pop S
        
        if count of S < k: push ai onto S

    value := 0

    while S is not empty: value := (value * 10) + [pop S]

return result
```

### Day 4: Printing Department

```
given (
    a_[1,1], ..., a_[1,m],
    ...,
    a_[n,1], ..., a_[n,m]
)
```

### Part A

```
let B be an ((n + 2) × (m + 2)) matrix

b[1,1], ..., b_[1,m + 2] := 0

foreach i in (1, ..., n):
    b[i + 1,1] := 0
    b[i + 1,2], ..., b[i + 1,m + 1] := a[i,1], ..., a[i,m]
    b[i + 1,m + 2] := 0

b[n + 2,1], ..., b_[n + 2,m+2] := 0

let result := 0

foreach i in (2, ..., n + 1):
    foreach j in (2, ..., m + 1):
        if not a[i,j] then continue
        
        let statements := (
            a[i - 1,j - 1],
            a[i - 1,j],
            a[i - 1,j + 1],
            a[i,j - 1],
            a[i,j + 1],
            a[i + 1,j - 1],
            a[i + 1,j]
            a[i + 1,j + 1],
        )
        
        if [count of statements s where s] < 4 then increment result

return result
```
