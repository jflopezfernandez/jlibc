
vpath %.c src

export RM       :=  rm -f

export CC       :=  gcc
export CFLAGS   := -std=c17 -Wall -Wextra -Wpedantic -fPIC -O0 -ggdb -g3 -fanalyzer -fsanitize=address -fstack-protector-strong
export CPPFLAGS := -Iinclude -D_GNU_SOURCE
export LDFLAGS  := -Wl,-O1,--sort-common,--as-needed,-z,relro,-z,now
export LIBS     :=

SRCS            := $(notdir $(wildcard src/*.c))
OBJS            := $(patsubst %.c,%.o,$(SRCS))

TARGET          := libjc.so

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -shared -o $@ $^ $(LIBS)

%: %.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

.PHONY: check
check: $(TARGET)
	$(MAKE) -C tests/ check

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
