# This is a Makefile comment
CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref
MANDIR=~/CSC3022F/Assignment2/Frames

# Need object files tag.o and tagDriver.o to create exe tagENUM 
extractor: findcomp.o ConnectedComponent.o PGMimageProcessor.o 
	$(CC) findcomp.o ConnectedComponent.o PGMimageProcessor.o  -o findcomp.exe $(LIBS)
	
catch: catch_tests.o ConnectedComponent.o PGMimageProcessor.o 
	$(CC) catch_tests.o ConnectedComponent.o PGMimageProcessor.o -o catch_test.exe $(LIBS)
	
# Implicit pattern rule for compiling object files
%.o : %.cpp   # $< is the first dependancy and $@ is the target
	$(CC) -c $< -o $@
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
	@rm findcomp.exe
	@rm catch_test.exe

clear:
	rm ~/CSC3022F/Assignment3/Output/*.pgm
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
  
	@mv extractor ~/bin
	
run:
	./extractor larger_image.pgm -t 0 10 5000 5000 -s 640 480 -w invert largeinvseq -w none largesequence2
	
run1:
	./findcomp.exe -s 3 100 -t 128 -p -w out.pgm Ugly.pgm
	
runError:
	./findcomp.exe -s 3 100 -t 20 -p -w out.pgm Ugly.pgm
	
run3:
	./findcomp.exe -s 3 100 -t 100 -p -w out.pgm Ugly.pgm
	
run4:
	./findcomp.exe -s 3 100 -t 100 -p -w out.pgm knight.pgm
	
run5:
	./findcomp.exe -s 3 100 -t 100 -p -w out.pgm sloan_image.pgm
run6:
	./findcomp.exe -s 3 100 -t 200 -p -w out.pgm car.pgm
run7:
	./findcomp.exe -s 3 100 -t 255 -p -w out3.pgm soldier.pgm
noprint:
	./findcomp.exe -s 3 100 -t 120 -w out3.pgm soldier.pgm
	
