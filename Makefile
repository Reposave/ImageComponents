# This is a Makefile comment
CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref
MANDIR=~/CSC3022F/Assignment2/Frames

# Need object files tag.o and tagDriver.o to create exe tagENUM 
extractor: findcomp.o PGMimageProcessor.o ConnectedComponent.o
	$(CC) findcomp.o PGMimageProcessor.o ConnectedComponent.o -o findcomp.exe $(LIBS)
	
catch: catch_tests.o PGMimageProcessor.o ConnectedComponent.o
	$(CC) catch_tests.o PGMimageProcessor.o ConnectedComponent.o -o catch_test.exe $(LIBS)
	
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
