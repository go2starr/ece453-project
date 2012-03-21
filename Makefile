##############################################################################
#
##############################################################################
CROSS_COMPILE = /opt/arm-2011.03/bin/arm-none-eabi-
C_FLAGS = -Wall -O3 -mcpu=arm926ej-s -fno-strict-aliasing
LD_FLAGS = --section-start=.init=0xC0200000

##############################################################################
#
##############################################################################
OUTPUT_FILE = ps3
C_FILES = ps3c.cpp

##############################################################################
#
##############################################################################
OBJ_FILES = $(S_FILES:%.S=%.o) $(C_FILES:%.c=%.o)
DEP_FILES = $(S_FILES:%.S=%.d) $(C_FILES:%.c=%.d)

$(OUTPUT_FILE): $(OBJ_FILES)
	$(CROSS_COMPILE)g++ -Xlinker "$(LD_FLAGS)" -o $@ $^

%.o: %.cpp
	$(CROSS_COMPILE)g++ $(C_FLAGS) $(INCLUDES) -M -o $*.d $<
	$(CROSS_COMPILE)g++ $(C_FLAGS) $(INCLUDES) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OUTPUT_FILE) $(OBJ_FILES) $(DEP_FILES)

-include $(DEP_FILES)
