#### DIRECTORIES
DIRSRC 	= ./src/

#### COMPILER FLAGS
COMP 	= g++
CFLAGS 	= -O3 -std=c++11
CC 	= $(COMP) $(CFLAGS) -c
CO	= $(COMP) $(CFLAGS) -o

#### EXECUTABLES
EXE 	= main.exe 
all: $(EXE)

#### LINKING OBJECT FILES
main.exe: main.o vec3.o
	$(CO) main.exe main.o vec3.o

#### BUILDING OBJECT FILES
main.o: $(DIRSRC)main.cpp vec3.o
	$(CC) $(DIRSRC)main.cpp -I$(DIRSRC)

vec3.o: $(DIRSRC)vec3.h $(DIRSRC)vec3.cpp
	$(CC) $(DIRSRC)vec3.cpp -I$(DIRSRC)

#### MAKE CLEAN
clean:
	rm -f *~
	rm -f *.o
	rm -f *.exe
	rm -f -r ccache
	rm -f .fuse*
