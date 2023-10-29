OBJECTS = add.o sub.o mul.o div.o
CC = gcc
CFLAGS = -Wall
STATICTARGET = libstatic.a 
SHAREDTARGET = libshared.so 
DYNAMICTARGET = libdynamic.so

all: $(STATICTARGET) $(SHAREDTARGET) $(DYNAMICTARGET)

$(STATICTARGET): $(OBJECTS)
	ar rcs $@ $^

$(SHAREDTARGET): $(OBJECTS)
	$(CC) -shared -o $@ $^

$(DYNAMICTARGET): $(OBJECTS)
	$(CC) -shared -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(STATICTARGET) $(SHAREDTARGET) $(DYNAMICTARGET)
