#define DEBUG
/*
 *  FILE   : fcfs.c
 *  AUTHOR : Matthew Smith
 *  AUTHOR : Denis Dionne
 *  NOTES  : Implement First Come First Serve
 *           scheduler simulation.
 */

#include "fcfs.h"
#define QUEUE_SIZE 10

Queue job;
Queue ready;
Queue waiting;

int main(int argc, char **argv) { //run a specific filename using the name as a second parameter when running
    char* file_name = argv[1];
    int running = 1;
    int result = 0;
    PCB running_process;

    #ifndef DEBUG
    if(argc != 2) {
        printf("Incorrect Parameters, please specify a file name");
        return -1;
    }
    #else
    scanf("%s",file_name);
    #endif

    job = CreateQueue(QUEUE_SIZE);
    ready = CreateQueue(QUEUE_SIZE);
    waiting = CreateQueue(QUEUE_SIZE); //create the 3 queues

    parseFile(&job, file_name); //parse the file into the job queue

    //transfer the files from the job queue to the ready queue in the proper schedule order
    transferToRunning(&job, &ready);

    while(running) {

        running_process = FrontAndDequeue(ready); //get the next process in the queue

        result = simulateCPUWork(running_process);//simulate the process accessing the cpu

        switch(result) { //check what state the process is in after simulating the work
            case TERMINATED_STATE:
                if(IsEmpty(ready)) { //if there is nothing left in the queue, the simulation is done
                    running = 0;
                }
                running_process = NULL;
            break;
            case WAITING_STATE:
                //TODO move pcb to waiting
            break;
        }
    }

    return 0;
}

void parseFile(Queue *job, char *file_name) {
    printf("Opening %s",file_name);
    //open file with passed file name
    //loop over every line
    //parse line into PCB
    //put PCB into job queue
    //add as sorted by arrival time
}

int simulateCPUWork(PCB pcb) {
    pcb->state = RUNNING_STATE;
    printf("PCB with pid:%i is now running", pcb->pid);
    if(pcb->cpu_time < pcb->io_freq) { //if the time left is shorter than the io frequency
        #ifdef DEBUG
        sleep(pcb->cpu_time); //actually wait to slow the program down if in debug
        #endif /*DEBUG*/
        pcb->cpu_time = 0;
        pcb->state = TERMINATED_STATE;
        printf("PCB with pid:%i is terminated", pcb->pid);
        return TERMINATED_STATE;
    }
    pcb->cpu_time-=pcb->io_duration; //take the time off that the process would spend in i/o
    pcb->state = WAITING_STATE;
    printf("PCB with pid:%i is now waiting", pcb->pid);
    return WAITING_STATE;
}

void transferToRunning(Queue *job, Queue *running) {

}

