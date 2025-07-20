// ton.c
#include "ton.h"

void TON_Init(TON* timer, uint32_t presetTimeMs) {
    timer->IN = false;
    timer->Q = false;
    timer->PT_ms = presetTimeMs;
    timer->ET_ms = 0;
    timer->_startTime = 0;
    timer->_running = false;
}

void TON_Update(TON* timer, bool input, uint32_t currentTimeMs) {
    timer->IN = input;

    if (timer->IN) {
        if (!timer->_running) {
            timer->_startTime = currentTimeMs;
            timer->_running = true;
        }

        timer->ET_ms = currentTimeMs - timer->_startTime;

        if (timer->ET_ms >= timer->PT_ms) {
            timer->Q = true;
            timer->ET_ms = timer->PT_ms; // Clamp
        } else {
            timer->Q = false;
        }

    } else {
        timer->Q = false;
        timer->ET_ms = 0;
        timer->_running = false;
    }
}
