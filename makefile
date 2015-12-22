CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = ex4.o barbarian.o dice.o character.o reptilian.o blueMen.o goblin.o shadow.o

SRCS = ex4.cpp barbarian.cpp dice.cpp character.cpp reptilian.cpp blueMen.cpp goblin.cpp shadow.cpp

HEADERS = character.hpp barbarian.hpp dice.hpp reptilian.hpp blueMen.hpp goblin.hpp shadow.hpp

PROGS = ex4

#all: ex4

ex4: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ex4

ex4.o: ex4.cpp ${HEADERS} 
	${CXX} ${CXXFLAGS} -c ex4.cpp

shadow.o: shadow.cpp shadow.hpp character.hpp dice.hpp
	${CXX} ${CXXFLAGS} -c shadow.cpp

goblin.o: goblin.cpp goblin.hpp character.hpp dice.hpp
	${CXX} ${CXXFLAGS} -c goblin.cpp

blueMen.o: blueMen.cpp blueMen.hpp character.hpp dice.hpp
	${CXX} ${CXXFLAGS} -c blueMen.cpp

reptilian.o: reptilian.cpp reptilian.hpp character.hpp dice.hpp
	${CXX} ${CXXFLAGS} -c reptilian.cpp

barbarian.o: barbarian.cpp barbarian.hpp character.hpp dice.hpp
	${CXX} ${CXXFLAGS} -c barbarian.cpp

character.o: character.cpp character.hpp
	${CXX} ${CXXFLAGS} -c character.cpp

dice.o: dice.cpp dice.hpp
	${CXX} ${CXXFLAGS} -c dice.cpp

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f ex4 *.o *~

