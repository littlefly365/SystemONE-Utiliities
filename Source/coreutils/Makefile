#	$SystemONE: (coreutils) Makefile,v 1.2 2026/05/18	#

PROGS=arch basename cat dirname domainname echo false hostid hostname
ROOT?= ../..

all: coreutils build

build: coreutils
	mkdir -p $(ROOT)/build/
	for i in $(PROGS); do \
		$(CC) -o $(ROOT)/build/$$i $$i.c coreutils.o $(CPPFLAGS) -I../../Headers -L../libcommon -lcommon; \
	done
coreutils:
	$(CC) -o coreutils.o -c coreutils.c -I../../Headers
clean: 
	for i in $(PROGS); do \
		rm -rf $(ROOT)/build/$$i; \
	done
	rm -rf coreutils.o
install:
	for i in $(PROGS); do \
		install -Dm755 build/$$i $(DESTDIR)$(BINDIR)/$$i; \
	done
.PHONY: all $(PROG) build coreutils clean install
