CC = gcc
CFLAGS = -g -Wall

# List of object files, generated from corresponding source files
OBJS = main.o random.o 1_sens_velc_vento.o 2_sens_dir_vento.o 3_sens_temp.o 4_sens_pluvio.o 5_sens_humd_atm.o 6_sens_humd_solo.o

# Target executable file
EXE = output

# Default target
all: $(EXE)

# Rule to link object files to create executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rules for generating object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.o: %.s
	$(CC) $(CFLAGS) -c $<

run: output
	./output
	
clean:
	rm -f $(EXE) $(OBJS)