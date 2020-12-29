# compiles all cpp files separate
#
LIBS  = -lpthread
CFLAGS = -Wall

SRC = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,%,$(SRC))

all: $(PROGS)

%: %.cpp
	g++ $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f $(PROGS)
