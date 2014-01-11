subdirs = blink serial ds1820 lcd

%:
	@for i in $(subdirs); do\
	  $(MAKE) -C $$i $@;\
	done
