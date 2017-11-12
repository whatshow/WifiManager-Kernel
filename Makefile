# Kernel module WifiManager-Kernel
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

PKG_NAME:=WifiManager-Kernel
PKG_RELEASE:=1

define KernelPackage/WifiManager-Kernel
	SUBMENU:=Other modules
	TITLE:=Support Module for WifiManager-Kernel
	AUTOLOAD:=$(call AutoLoad,81,WifiManager-Kernel)
　　	FILES:=$(PKG_BUILD_DIR)/WifiManager-Kernel/WifiManager-Kernel.$(LINUX_KMOD_SUFFIX)
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) -R ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
		CROSS_COMPILE="$(TARGET_CROSS)" \
		ARCH="$(LINUX_KARCH)" \
		SUBDIRS="$(PKG_BUILD_DIR)/WifiManager-Kernel" \
		EXTRA_CFLAGS="-g $(BUILDFLAGS)" \
		modules
endef
$(eval $(call KernelPackage,WifiManager-Kernel))
