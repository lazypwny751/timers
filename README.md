# TON Timer in C

This repository implements a PLC-style TON (Timer ON Delay) function block in standard C, with a test harness and CI pipeline via GitHub Actions.

## Build

To build the project, run:

```
make
```

## Run

To execute the test binary after building:

```
./build/ton_demo
```

## CI/CD

All commits and pull requests targeting the `main` branch are automatically built and tested using GitHub Actions.

---

## Algorithm

```pseudocode
Input: 
    IN     // Boolean input condition to start timer
    PT     // Preset time value (time delay)
Variables:
    ET     // Elapsed time
    Q      // Output
    StartTime // System time when IN first became true
    TimerRunning // Internal flag

Initialize:
    Q = FALSE
    ET = T#0s
    TimerRunning = FALSE

Algorithm:
IF IN = TRUE THEN
    IF TimerRunning = FALSE THEN
        StartTime = CURRENT_TIME()
        TimerRunning = TRUE
    END_IF

    ET = CURRENT_TIME() - StartTime

    IF ET >= PT THEN
        Q = TRUE
        ET = PT  // Clamp ET to PT after timeout
    ELSE
        Q = FALSE
    END_IF

ELSE
    Q = FALSE
    ET = T#0s
    TimerRunning = FALSE
END_IF
```
