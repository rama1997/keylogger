# Keylogger for Mac

Simple keylogger for mac that logs keystroke and time.

Two mode: textmode and loggermode

**Logger mode** prints out in a logger style format with date, time, and specific keystroke. This mode offers the cleanest output compared to text mode.

**Text mode** tries to print out in a more readable format like a text file. Tries to print out segment of words or single complete words as oppose to indivual keystrokes. Text mode determines if a segment is complete based on keystroke input of certain keys such as enter, delete, and command. Text mode works to some degree but doesn't always offer the best clarity when it comes to non single character keystrokes or keys that have funtionality. As of now, it is set to look like what I think is best based on my own personalization.

Default is logger mode


## Install

By default, the program is put in /usr/local/bin/keylogger. The log file is stored in /var/log/keylogger.log. The plist file is stored in /Library/LaunchDaemon. All these paths can be changed in the files.

Install using the makefile

```
$ make install
```

Can also run the application on startup using

```
$ make startup
```

## Logging

Start application by using the keylogger command

```
$ keylogger
```

You can either open the log file manually or use one of the following two commands.

```
$ keylogger open
```

```
$ make openlog
```

You can clear the log using one of the following two commands

```
$ keylogger clear
```

```
$ make clearlog
```


## Uninstall

Uninstall using the makefile


```
$ make uninstall
```

Will not delete existing logs
