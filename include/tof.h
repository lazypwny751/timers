#ifndef TIMER_TOF
#define TIMER_TOF

typedef struct {
	int et;
	int q;
	int active;
} TOF;

extern int tof_clock;

#endif
