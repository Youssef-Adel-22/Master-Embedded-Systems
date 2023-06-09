#@Create by Eng.Youssef Adel
Project_Name=Lab2
CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
all: $(Project_Name).bin
	@echo "============== BUILD IS DONE ================"
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
%.o: %.s
	$(CC)as.exe  -c $(CFLAGS) $< -o $@
	
$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.elf *.bin *.map