PROGRAM_NAME = decoder
SRC_FILES = decoder.c

CROSS_COMPILE ?= arm-none-linux-gnueabi-
OBJ_FILES = $(SRC_FILES:%.c=%.o)
DEP_FILES = $(SRC_FILES:%.c=%.d)

$(PROGRAM_NAME): $(OBJ_FILES)
	$(CROSS_COMPILE)gcc -o $@ $?

%.o: %.c
	$(CROSS_COMPILE)gcc -M -c -o $*.d $<
	$(CROSS_COMPILE)gcc -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(PROGRAM_NAME) $(OBJ_FILES) $(DEP_FILES)

-include $(DEP_FILES)
