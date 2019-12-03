CFLAGS    = -g
CFLAGS    += -DSOLN
CC        = g++ -std=c++17
SRCS      = main.cpp controller.cpp helpers.cpp
SRCS			+= dec1.cpp
OBJS      = $(SRCS:.cpp=.o)
PROG      = ca2019

LIBS = -lstdc++fs # using C++17 <filesystem>

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm $(OBJS) $(PROG)
