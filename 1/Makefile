# Compile day1 coding programs
# Usage: make

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -O3
OBJ = day1_part2.o

# load library
LDLIBS = -lm

all:  day1_part2

day1_part2: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o day1_part1 day1_part2
