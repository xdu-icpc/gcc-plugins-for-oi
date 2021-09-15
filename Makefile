HOST_CXX = g++
TARGET_GCC = gcc
GCCPLUGINS_DIR := $(shell $(TARGET_GCC) -print-file-name=plugin)
CXXFLAGS += -I$(GCCPLUGINS_DIR)/include -fPIC -fno-rtti -O2

all: no_opt_attr_plugin.so

no_opt_attr_plugin.o: no_opt_attr_plugin.cc \
                      gcc-common.h gcc-generate-gimple-pass.h
	$(HOST_CXX) -c -o $@ $(CXXFLAGS) $<

no_opt_attr_plugin.so: no_opt_attr_plugin.o
	$(HOST_CXX) -shared -o $@ $<

GENERATED = *.o *.so

.PHONY: clean
clean:
	rm -fv $(GENERATED)

.PHONY: .gitignore
.gitignore:
	echo "$(GENERATED)" | sed 's/ /\n/g' > $@
