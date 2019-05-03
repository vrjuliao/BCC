# CC := g++-4.8
CC := g++
SRCDIR := src
OBJDIR := build
BINDIR := bin

MAIN := main.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
$(info SOURCES = $(SOURCES))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
#OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
$(info OBJECTS = $(OBJECTS))

# -g debug, --coverage para cobertura
CFLAGS := --coverage -g -Wall -O3 -std=c++11
#CFLAGS := -std=c++11
#INC := -I include/ -I third_party/
INC := -I include/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
# $(OBJDIR)/%: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(info here)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	# $(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	# @mkdir -p $(BINDIR)
	# $(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o main

all: main

run: main
	$(BINDIR)/main

clean:
	$(RM) -rf $(BINDIR) $(OBJDIR) *.gcda *.gcno main main.dSYM
	#$(RM) -r $(OBJDIR)/* $(BINDIR)/* *.gcda *.gcno
