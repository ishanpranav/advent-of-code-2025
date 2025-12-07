# Advent of Code 2025

Efficient Advent of Code 2025 solutions in C language

## Day 1: Secret Entrance

Time complexity: $O(n)$ (linear)

```
given input

let dial := 50
let result := 0
```

### Part A

```
for all (direction, distance) in input:
    if direction = 'L' then negate distance

    dial := (dial + distance) mod 100

    if dial = 0 then increment result

return result
```

### Part B

```
for all (direction, distance) in input:
    if direction = 'L' then negate distance

    let nextDial := dial + distance

    if dial ≠ 0 and nextDial < 0 then increment result

    result := result + ⌊|dial| / 100⌋

    if nextDial = 0 then increment result

    dial := nextDial mod 100

return result
```

## Day 2: Gift Shop

Time complexity: $O(n)$ (linear)

```
given input

let result := 0
```

### Part A

```
for all (left, right) in input:
    let minK := ⌈(log_10(left) + 1) / 2⌉
    let maxK := ⌊(log_10(right) + 1) / 2⌋

    for all k in (minK, ..., maxK):
        let mask := 10^k + 1
        let minX := max(10^(k - 1), ⌈left / mask⌉)
        let maxX := min(10^k - 1, ⌊right / mask⌋)

        result := result + [sum of x = minX to maxX over (x * mask)]

return result
```

### Part B

```
for all (left, right) in input:
    let maxK := ⌊log_10(right)⌋ + 1

    for all k in (1, ..., maxK):
        let maxR := maxK / k

        for all r in (2, ..., maxR):
            let mask := (10^(k * r) - 1) / (10^k - 1)
            let minX := max(10^(k - 1), ⌈left / mask⌉)
            let maxX := min(10^k - 1, ⌊right / mask⌋)

            result := result + [sum of x = minX to maxX over (x * mask)]

return result
```

## Day 3: Lobby

Time complexity: $O(m\times n)$ (linear)

```
given input
let result := 0
```

### Part A

```
for all (a_1, ..., a_n) in input:
    let first := a_1
    let second := a_2

    for all i in (2, ..., n - 1):
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
for all (a_1, ..., a_n) in input:
    let S be a stack

    for all ai in (a_1, ..., a_n):
        while S is not empty
            and [peek S] < ai
            and (n - i + count of S) > 12:
            pop S
        
        if count of S < k: push ai onto S

    value := 0

    until S is empty: value := (value * 10) + [pop S]

return result
```

## Day 4: Printing Department

Time complexity: $O(n\times m)$ (linear)

```
given (
    a_[1,1], ..., a_[1,m],
    ...,
    a_[n,1], ..., a_[n,m]
)

define neighbors(i, j) as return (
    (i - 1, j - 1)
    (i - 1, j),
    (i - 1, j + 1),
    (i, j - 1),
    (i, j + 1),
    (i + 1, j - 1),
    (i + 1, j),
    (i + 1, j + 1)
)

let B be an ((n + 2) × (m + 2)) boolean matrix

b_[1,1], ..., b_[1,m + 2] := false

for all i in (1, ..., n):
    b_[i + 1,1] := false
    b_[i + 1,2], ..., b_[i + 1,m + 1] := a_[i,1], ..., a_[i,m]
    b_[i + 1,m + 2] := false

b_[n + 2,1], ..., b_[n + 2,m + 2] := false

let result := 0
```

### Part A

```
for all i in (2, ..., n + 1):
    for all j in (2, ..., m + 1):
        if not b_[i,j] then continue
        
        let d := count of (x, y) in neighbors(i, j) where b_[x,y]

        if d < 4 then increment result

return result
```

### Part B

```
let Q be a queue
let D be an ((n + 2) × (m + 2)) matrix

for all i in (2, ..., n + 1):
    for all j in (2, ..., m + 1):
        if not b_[i,j] then continue

        d_[i,j] := count of (x, y) in neighbors(i, j) where b_[x,y]

        if d_[i,j] < 4 then enqueue (i, j) onto Q

until Q is empty:
    let (i, j) := dequeue Q

    if not b_[i,j] then continue

    b_[i,j] := false

    for all (x, y) in neighbors(i, j) where b_[x,y]:
        decrement d_[x,y]
        
        if d_[x,y] < 4 then enqueue (x, y) onto Q
    
    increment result

return result
```

## Day 5: Cafeteria

Time complexity (Part A): $O((n+m)\log{n})$ (log-linear)

Time complexity (Part B): $O(n\log{n})$ (log-linear)

```
given (intervals, values)

(a_1, ..., a_n) := [
    sort [left, right] in intervals ordering by left, then by right descending
]

let [currentLeft, currentRight] := a_1
let L be a list

for all i in (2, ..., n):
    let [nextLeft, nextRight] := a_i

    if nextLeft ≤ currentRight then:
        currentRight := max(currentRight, nextRight)

        continue
    
    append [currentLeft, currentRight] onto L

    [currentLeft, currentRight] := (nextLeft, nextRight)

append [currentLeft, currentRight] onto L

let result := 0
```

### Part A

```
for all value in values:
    if binary search value in L then increment result

return result
```

### Part B

```
for all [left, right] in L
    result := result + right - left + 1

return result
```
