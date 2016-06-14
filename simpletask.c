/*
File         : simpletask.c
Programmer   : Liyamoll Paulose - 7441454
Description  : This file will reads the counter and
               prints the message. The monitor command 
               increments the counter
Date         : 14/06/2016
*/    
#include <stdio.h>
#include <stdint.h>
#include "common.h"

static uint32_t counter=0;    // initialise counter value

/*
Function     : TaskCounter() 
Description  : checks whether the count value is equal
               to zero and if not, print the count value 
               and decrements after printing each value
Parameters   : None
Returns      : None
*/
void TaskCounter(void)   
{
if(counter!=0)               // checks whether counter value 
                             // not equal to zero
{ 
 printf("The counter is %d\n",(unsigned int) count); 
counter--;                   // decrements the counter
}
}

/*
Function     : CmdCount() 
Description  : Read the numeric argument and add number to 
               current content of the global counter variable
Parameters   : mode
Returns      : None
*/
void CmdCount(int mode)
{
int rc;
uint32_t value = 0;         
if(mode != CMD_INTERACTIVE)  // checks the mode value
 {
    return;
 }
rc = fetch_uint32_arg(&value);// read the numeric argument
if(rc)
 {
    printf(" Enter value");
    return;
 }
else
counter=value;                // add number to the counter value
  }
ADD_CMD("count",CmdCount," Counting downwards");

