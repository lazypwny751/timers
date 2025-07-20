// main.c
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h> // for usleep
#include "include/ton.h"

uint32_t getSystemTimeMs() {
    static uint32_t simulatedTime = 0;
    simulatedTime += 100; // Simulate time increment (e.g., 100 ms per loop)
    return simulatedTime;
}

int main() {
    TON myTimer;
    TON_Init(&myTimer, 1000); // 1-second delay

    for (int i = 0; i < 20; ++i) {
        bool inputSignal = (i >= 3); // Activate input at iteration 3

        TON_Update(&myTimer, inputSignal, getSystemTimeMs());

        printf("Cycle %d | IN: %d | Q: %d | ET: %u ms\n",
               i, inputSignal, myTimer.Q, myTimer.ET_ms);

        usleep(100000); // Delay 100 ms
    }

    return 0;
}
