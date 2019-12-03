CFLAGS    = -g
CFLAGS    += -DSOLN
CC        = g++
SRCS      = main.cpp controller.cpp dec1.cpp 
OBJS      = $(SRCS:.cpp=.o)
PROG      = ca2019

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm $(OBJS) $(PROG)
