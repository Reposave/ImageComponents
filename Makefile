# This is a Makefile comment
CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref
MANDIR=~/CSC3022F/Assignment2/Frames

# Need object files tag.o and tagDriver.o to create exe tagENUM 
extractor: PGMimageProcessor.o ConnectedComponent.o
	$(CC) PGMimageProcessor.o ConnectedComponent.o -o driver $(LIBS)

# Implicit pattern rule for compiling object files
%.o : %.cpp   # $< is the first dependancy and $@ is the target
	$(CC) -c $< -o $@
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
	@rm extractor

clear:
	rm ~/CSC3022F/Assignment2/Frames/*.pgm
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
  
	@mv extractor ~/bin
	
run:
	./extractor larger_image.pgm -t 0 10 5000 5000 -s 640 480 -w invert largeinvseq -w none largesequence2

largeinvert:
	./extractor larger_image.pgm -t 40 60 899 400 -s 1980 1080 -w revinvert largeRevInvseq
	

run1:
	./extractor sloan_image.pgm -t 0 10 3 13 -s 550 480 -w invert invseq -w none sequence1 -w revinvert test1
	
run2:
	./extractor sloan_image.pgm -t 0 10 5000 5000 -s 640 480 -w invert invseq2 -w none sequence2

run3:
	./extractor sloan_image.pgm -t 0 10 1 11 -s 640 480 -w invert invseq3 -w none sequence3
	
reverseSmall:
	./extractor sloan_image.pgm -t 0 10 3 13 -s 640 480 -w reverse revsequence4

reverseLarge:
	./extractor sloan_image.pgm -t 0 10 400 300 -s 640 480 -w reverse revsequence5
	
reverseLarge2:
	./extractor sloan_image.pgm -t 200 200 350 300 -s 640 480 -w none revsequence5
	
revinvert:
	./extractor sloan_image.pgm -t 0 10 4 14 -s 640 480 -w revinvert revinv6 -w none sequence6
	
revinvertLarge:
	./extractor sloan_image.pgm -t 0 10 400 300 -s 1280 720 -w revinvert revinv7 -w none sequence7
	
runbackwards:
	./extractor sloan_image.pgm -t 3 13 0 10 -s 550 480 -w none sequence8
	
runbackwards2:
	./extractor sloan_image.pgm -t 500 600 400 300 -s 550 480 -w none sequence9
	
runstraight:
	./extractor sloan_image.pgm -t 200 200 200 300 -s 640 480 -w none revsequence5
