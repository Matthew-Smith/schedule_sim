/*
 *  FILE   : PCB.h
 *  AUTHOR : Matthew Smith
 *  AUTHOR : Denis Dionne
 *  NOTES  : Define the PCB struct used
 *           in the scheduler simulation.
 */
#define READY_STATE       0
#define RUNNING_STATE     1
#define WAITING_STATE     2
#define TERMINATED_STATE  3

#ifndef _PCB_h
#define _PCB_h

struct _pcb{
    int pid;
    int arrival_time;
    int cpu_time;
    int io_freq;
    int io_duration;
    int state;
};

typedef struct _pcb *PCB;

#endif /*_PCB_h*/
