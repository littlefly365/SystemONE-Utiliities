ROOT ?=../

all: libcommon progs

libcommon:
	@$(MAKE) -C libcommon
progs: libcommon
	@$(MAKE) -C coreutils
	@$(MAKE) -C custom
clean:
	@$(MAKE) -C libcommon clean
	@$(MAKE) -C coreutils clean
	@$(MAKE) -C custom clean
	rm -rf $(ROOT)/build
install:
	@$(MAKE) -C coreutils install
	@$(MAKE) -C custom install

.PHONY: all libcommon coreutils custom clean install
