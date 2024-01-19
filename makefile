CC = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14 -O3 -fsanitize=address -fsanitize=undefined -Wshadow -Wformat=2 -Wfloat-equal -Wconversion
LIBS = -lncurses

SOURCES = tetris.cc block.cc interface.cc
OBJECTS = ${SOURCES:.cc=.o}

# all: ${OBJECTS}

# %.o: %.cc
# 	${CC} ${CXXFLAGS} -c $< -o $@

main: tetris.o block.o interface.o
	${CC} ${CXXFLAGS} -o tetris tetris.o block.o interface.o ${LIBS}

tetris.o: tetris.cc 
	${CC} ${CXXFLAGS} -c tetris.cc

block.o: block.cc
	${CC} ${CXXFLAGS} -c block.cc
	
interface.o: interface.cc
	${CC} ${CXXFLAGS} -c interface.cc

clean:
	rm -f ${OBJECTS}