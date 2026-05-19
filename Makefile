all:
	$(MAKE) -C Source all
clean:
	$(MAKE) -C Source clean
install:
	$(MAKE) -C Source install
.PHONY: all clean install
