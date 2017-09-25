.SUFFIXES:
.SUFFIXES: .c .o .h

EXAMPLE = aha

CC	= gcc
CXX	= g++
DEFINES = -DINC=\"$(EXAMPLE).h\" -DOFILE=\"$(EXAMPLE).out\"
CFLAGS	= -g -O2 -Wall -I. $(DEFINES)
CXXFLAGS = $(CFLAGS)

SRCS	= aha.c
OBJS	= $(SRCS:%.c=%.o)

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.c.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<



all: aha

aha: $(OBJS)
	$(CXX) $(CXXFLAGS) -o aha $(OBJS)

clean:
	$(RM) -f $(OBJS) aha core *~ *.bak
