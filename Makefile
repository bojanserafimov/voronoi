
CC = clang
CFLAGS = -std=c99
LDFLAGS = 

# GTK
LDFLAGS += $(shell pkg-config --cflags --libs gtk+-3.0)

SOURCES = $(wildcard *.c)
EXECUTABLE = voronoi
OBJECTS = $(SOURCES:.c=.o)
CRUFT = $(OBJECTS) + $(EXECUTABLE)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

$(OBJECTS): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	@rm -f $(CRUFT)

all:
