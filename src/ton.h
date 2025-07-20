// ton.h
#ifndef TON_H
#define TON_H

#include <stdint.h>
#include <stdbool.h>

// TON Timer Data Structure
typedef struct {
    bool IN;             // Input signal
    bool Q;              // Output signal
    uint32_t PT_ms;      // Preset time in milliseconds
    uint32_t ET_ms;      // Elapsed time in milliseconds (read-only)
    uint32_t _startTime; // Internal use only
    bool _running;       // Internal use only
} TON;

// Initialization function
void TON_Init(TON* timer, uint32_t presetTimeMs);

// Update function (call periodically)
void TON_Update(TON* timer, bool input, uint32_t currentTimeMs);

#endif // TON_H
