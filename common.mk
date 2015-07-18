CC = clang
CFLAGS = -std=c99
LDFLAGS = 
DEPENDENCIES = 

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
CRUFT = $(OBJECTS) + $(NAME)

all:: $(NAME)

$(NAME): $(OBJECTS)
	@mkdir -p $(PREFIX)
	@$(CC) $(OBJECTS) -o $(PREFIX)/$(NAME) $(LDFLAGS)

$(OBJECTS): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@ $(LDFLAGS)

clean::
	@rm -f $(CRUFT)


