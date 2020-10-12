
vpath %.c src

RM := rm -f

CC := gcc
CFLAGS := -shared -std=c17 -Wall -Wextra -Wpedantic -fPIC -O0 -ggdb -g3 -fanalyzer -fsanitize=address -fstack-protector-strong
CPPFLAGS := -Iinclude -D_GNU_SOURCE
LDFLAGS := -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now
LIBS :=

SRCS := $(notdir $(wildcard src/*.c))
OBJS := $(patsubst %.c,%.o,$(SRCS))

TARGET := libjc.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%: %.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
