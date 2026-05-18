#	$SystemONE: (custom-commands) Makefile,v 1.0 2026/05/18		#

PROGS=ldd prime SystemONE-version

all: build

build: obj
	mkdir -p build/
	for i in $(PROGS); do \
		$(CC) -o build/$$i obj/$$i.o obj/custom.o -L../libcommon -lcommon; \
	done
obj:
	mkdir -p obj/
	$(CC) -o obj/custom.o -c custom.c -I../../Headers
	for i in $(PROGS); do \
		$(CC) -o obj/$$i.o -c $$i.c -I../../Headers; \
	done
clean: 
	rm -rf obj build
install:
	for i in $(PROGS); do \
		install -Dm755 build/$$i $(DESTDIR)$(BINDIR)/$$i; \
	done
.PHONY: all $(PROG) build obj clean install
