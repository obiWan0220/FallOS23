/* timer.c */
/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 100
int alarms = 0;
time_t start, end, total;
char buf[MAXSIZE];

void handler(int signum) { //signal handler
  printf("Hello World!\n");
  alarms += 1;
  //exit(1); //exit after printing
}

void stats(int signum) { //signal handler
  end = time(NULL);
  total = end - start;
  printf("\nNumber of Alarms: %d\n", alarms);
  printf("Total program runtime: %ld seconds\n", total);
  exit(1);
}

int main(int argc, char * argv[])
{
  start = time(NULL);
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  signal(SIGINT, stats); //register handler to handle SIGINT

  while(1) {
    alarm(1); //Schedule a SIGALRM for 1 second 
    sleep(1);
    sprintf(buf, "Turing was right!\n");
    write(1, buf, strlen(buf));

  } //busy wait for signal to be delivered
  return 0; //never reached
}