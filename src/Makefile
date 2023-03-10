CXX=g++
CXXFLAGS= -std=c++11 -Wall -lstdc++
EXEC_FILES= tests ants

all: tests ants


%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

# fichiers objets
ants: coord.o enscord.o fourmi.o place.o grille.o functions.o colonie.o ecrfich.o main.o
	$(CXX) $(CXXFLAGS) -o ants coord.o enscord.o fourmi.o place.o grille.o functions.o colonie.o ecrfich.o main.o

tests: coord.o enscord.o fourmi.o place.o grille.o functions.o colonie.o ecrfich.o test.o
	$(CXX) $(CXXFLAGS) -o tests coord.o enscord.o fourmi.o place.o grille.o functions.o colonie.o ecrfich.o test.o

main.o: main.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c main.cpp
	
test.o: test.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c test.cpp

coord.o: coord.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c coord.cpp

enscord.o: enscord.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c enscord.cpp

fourmi.o: fourmi.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c fourmi.cpp

place.o: place.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c place.cpp

grille.o:grille.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c grille.cpp

functions.o:functions.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c functions.cpp

colonie.o:colonie.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c colonie.cpp

ecrfich.o:ecrfich.cpp AllHeaders.h
	$(CXX) $(CXXFLAGS) -c ecrfich.cpp
    
check:tests
	./tests
    
goAnts:ants
	./ants
	convert -scale 300 -delay 10 img*.ppm movie.gif
	rm -f *.o *.ppm $(EXEC_FILES)

clean:
	rm -f *.o *.ppm $(EXEC_FILES)
