obj-m := sbd.o
KDIR := /scratch/spring2018/group24/OS2-Group24/linux-yocto/
PWD_C := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD_C) modules
clean:
	
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD_C) clean
