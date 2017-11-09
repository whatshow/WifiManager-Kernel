obj-m := WifiManager-Kernel.o
PWD=$(shell pwd)  
KERNEL_DIR=/home/sky/develop/openWrt/openwrt/build_dir/target-mipsel_24kec+dsp_glibc-2.21/linux-ramips_mt7620/linux-3.18.29/  
TOOLCHAIN=/home/sky/develop/openWrt/openwrt/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_glibc-2.21/bin/mipsel-openwrt-linux-gnu-  
  
###############################################################################  
all:  
	make -C $(KERNEL_DIR) \  
		ARCH=mips \  
		CROSS_COMPILE=$(TOOLCHAIN) \  
		M=$(PWD) \  
		modules  
clean:  
	rm -f *.ko  
	rm -f *.o  
	rm -f *.mod.c  
	rm -f *.mod.o  
	rm -f *.order  
	rm -f *.sysvers  
