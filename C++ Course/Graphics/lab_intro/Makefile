EXE = lab_intro
OBJS = main.o png.o rgbapixel.o

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall -Werror -I/opt/homebrew/opt/libpng/include/libpng16
LIB_PNG_PATH = -L/opt/homebrew/opt/libpng/lib
LINKER = g++
LINKER_OPTS = -lpng

all : $(EXE)

$(EXE) : $(OBJS) 
	$(LINKER) $(OBJS) $(LINKER_OPTS) $(LIB_PNG_PATH) -o $(EXE)

main.o : main.cpp png.h rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp

png.o : png.cpp png.h rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(COMPILER) $(COMPILER_OPTS) rgbapixel.cpp

clean :
	-rm -f *.o $(EXE)
