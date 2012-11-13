/*
 *  FILE   : fcfs.h
 *  AUTHOR : Matthew Smith
 *  AUTHOR : Denis Dionne
 *  NOTES  : Define the First Come First Serve
 *           scheduler simulation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"
#include "PCB.h"

#ifndef _fcfs_h
#define _fcfs_h

    int main();
    void parseFile(Queue *job, char *file_name);
    int simulateCPUWork(PCB pcb);
    void transferToRunning(Queue *job, Queue *running);

#endif /*_fcfs_h*/
