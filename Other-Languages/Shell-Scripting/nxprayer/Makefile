# nxprayer - Next Islamic prayer
.POSIX:

include config.mk

SRC = local_api.cpp

all: local_api

local_api: $(SRC)
	g++ $(WFLAGS) $(DFLAGS) $(OFLAGS) $(CPP) -o local_api $(SRC)

install: local_api
	mkdir -p $(DESTDIR)$(CONFIG)/nxprayer
	cp -iv init.json $(DESTDIR)$(CONFIG)/nxprayer/params.json
	chown -R "$(LGUSER):$(LGUSER)" $(DESTDIR)$(CONFIG)/nxprayer
	chmod 754 $(DESTDIR)$(CONFIG)/nxprayer
	chmod 644 $(DESTDIR)$(CONFIG)/nxprayer/params.json
	mkdir -p $(DESTDIR)$(LPREFIX)/share/nxprayer/calendar/{2021..2026}/{1..12}
	sed -i "s|^params_path.*|params_path = \"$(DESTDIR)$(CONFIG)/nxprayer/params.json\"|g" ./remote_api.py
	sed -i "s|^data_path.*|data_path = \"$(DESTDIR)$(LPREFIX)/share/nxprayer/calendar\"|g" ./remote_api.py
	python3 remote_api.py
	sed -i "s|^params_path.*|params_path = \"$(CONFIG)/nxprayer/params.json\"|g" ./remote_api.py
	sed -i "s|^data_path.*|data_path = \"$(LPREFIX)/share/nxprayer/calendar\"|g" ./remote_api.py
	chown -R "$(LGUSER):$(LGUSER)" $(DESTDIR)$(LPREFIX)/share/nxprayer
	chmod -R 754 $(DESTDIR)$(LPREFIX)/share/nxprayer
	mkdir -p $(DESTDIR)$(LPREFIX)/bin
	cp -f local_api $(DESTDIR)$(LPREFIX)/bin
	cp -f remote_api.py $(DESTDIR)$(LPREFIX)/bin
	cp -f nxprayer $(DESTDIR)$(LPREFIX)/bin
	chmod 755 $(DESTDIR)$(LPREFIX)/bin/local_api
	chown "$(LGUSER):$(LGUSER)" $(DESTDIR)$(LPREFIX)/bin/remote_api.py
	chmod 755 $(DESTDIR)$(LPREFIX)/bin/nxprayer
	mkdir -p $(DESTDIR)$(MAN)/man1
	cp -f nxprayer.1 $(DESTDIR)$(MAN)/man1
	chmod 644 $(DESTDIR)$(MAN)/man1/nxprayer.1

uninstall:
	rm -f $(DESTDIR)$(LPREFIX)/bin/nxprayer
	rm -f $(DESTDIR)$(LPREFIX)/bin/local_api
	rm -f $(DESTDIR)$(LPREFIX)/bin/remote_api.py
	rm -f $(DESTDIR)$(MAN)/man1/nxprayer.1
	rm -rf $(DESTDIR)$(LPREFIX)/share/nxprayer

clean:
	rm -f local_api

.PHONY: all clean install uninstall
