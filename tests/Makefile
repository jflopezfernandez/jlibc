
vpath %.c src

CFLAGS := $(CFLAGS) -L/home/jflopezfernandez/projects/c/jlibc
CPPFLAGS := $(CPPFLAGS) -I../include -Iinclude
LDFLAGS := $(LDFLAGS) -Wl,-rpath,/home/jflopezfernandez/projects/c/jlibc
LIBS := $(LIBS) -lcheck -ljc

SRCS := $(notdir $(wildcard src/*.c))
OBJS := $(patsubst %.c,%.o,$(SRCS))

TARGET := run-tests

all: $(TARGET)

.PHONY: display-build-info
display-build-info:
	@echo "CPPFLAGS := $(CPPFLAGS)"

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: check
check: $(TARGET)
	@./$(TARGET)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
