CFLAGS = -Wall

.PHONY: clean

all: dummy-server.bin

dummy-server.bin: main.c mongoose.o
	$(CC) $(CFLAGS) $^ -o $@

mongoose.o: mongoose.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	$(RM) $(PROG) *.o *.bin

