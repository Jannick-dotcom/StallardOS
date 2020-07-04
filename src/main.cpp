#include <mbed.h>
Serial pc(PD_8, PD_9); // tx, rx

#include "TaskScheduler.hpp"
TaskScheduler Tasker1;

int i = 0;

void task1(void)
{
  DigitalOut red(PB_14);
  while (1)
  {
    red.write(!red.read());
    //Tasker1.setContextSwitch(false);
    printf("task1\n");
    //Tasker1.setContextSwitch(true);
  }
}

void task2(void)
{
  DigitalOut blue(PB_7);
  while (1)
  {
    blue.write(!blue.read());
    //Tasker1.setContextSwitch(false);
    printf("\ttask2\n");
    //Tasker1.setContextSwitch(true);
  }
}

void task3(void)
{
  DigitalOut green(PB_0);
  while (1)
  {
    green.write(!green.read());
    //Tasker1.setContextSwitch(false);
    printf("\t\ttask3\n");
    //Tasker1.setContextSwitch(true);
  }
}

int main()
{
  Tasker1.addFunction(task1, 1, 100);
  Tasker1.addFunction(task2, 2, 100);
  Tasker1.addFunction(task3, 2, 100);
  Tasker1.startOS();
  while (1)
  {
    //Tasker1.schedule();
  }
}