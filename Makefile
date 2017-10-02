.SUFFIXES:	.o

EXAMPLE = example

CC	= gcc
CXX	= g++
DEFINES = -DINC=\"$(EXAMPLE).frag.c\" -DOFILE=\"$(EXAMPLE).out\"
CFLAGS	=  -O2 -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -MMD -I. $(DEFINES)
CXXFLAGS = $(CFLAGS)

SRCS	= aha.c simulator.c
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY:	all clean

all: aha

aha: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) -f $(OBJS) aha core *~ *.bak *.d

# Dependencies

aha.o:	$(EXAMPLE).frag.c

-include $(SRCS:.c=.d)

