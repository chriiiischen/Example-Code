
CXXFLAGS = -ggdb -Wall -Wno-sign-compare -std=c++11


concord: concord.o Table.o listFuncs.o
	g++ $(CXXFLAGS) -o concord concord.o Table.o listFuncs.o

grades: grades.o Table.o listFuncs.o
	g++ $(CXXFLAGS) -o grades grades.o Table.o listFuncs.o

pa5list: pa5list.cpp listFuncs.o listFuncs.h
	g++ $(CXXFLAGS) pa5list.cpp listFuncs.o -o pa5list

concord.o: concord.cpp Table.h
	g++ $(CXXFLAGS) -c concord.cpp

Table.o: Table.cpp Table.h listFuncs.h
	g++ $(CXXFLAGS) -c Table.cpp

grades.o: grades.cpp Table.h
	g++ $(CXXFLAGS) -c grades.cpp

listFuncs.o: listFuncs.cpp listFuncs.h
	g++ $(CXXFLAGS) -c listFuncs.cpp

