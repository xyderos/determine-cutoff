CC := clang
CFLAGS := -fsanitize=address -fno-omit-frame-pointer -Wall -Wextra -O3 -g
SRC := src
BIN := comparison
LIBS := -lm
TARGET := cmp
OBJDIR := obj
OBJS :=$(addprefix $(OBJDIR)/,comparison.o isort.o qsort.o msort.o)

$(BIN): directories $(OBJS) $(SRC)/$(BIN).c
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(OBJDIR) $(OBJDIR)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p $(OBJDIR)

clean:
	rm -f *~ *.o $(TARGET)
	rm -rf obj

all: clean $(BIN)
