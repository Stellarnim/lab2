CC = gcc
LDFLAGS = -I./lib -L./lib
STATIC_TARGET = staticmain
SHARED_TARGET = sharedmain
DYNAMIC_TARGET = dynamicmain

all: lib_all $(STATIC_TARGET) $(SHARED_TARGET) $(DYNAMIC_TARGET) 

lib_all:
	$(MAKE) -C lib -f Makefile
$(STATIC_TARGET):
	$(CC) -o $@ $(LDFLAGS) main.c -lstatic

$(SHARED_TARGET):
	$(CC) -o $@ $(LDFLAGS) main.c -Wl,-rpath,'$$ORIGIN/lib' -lshared

$(DYNAMIC_TARGET):
	$(CC) -o $@ $(LDFLAGS) -rdynamic dlmain.c -ldl

clean:
	rm -f $(STATIC_TARGET) $(SHARED_TARGET) $(DYNAMIC_TARGET)
	$(MAKE) -C lib -f Makefile clean