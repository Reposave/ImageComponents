#How to Run

In the terminal, type 'make' to compile.

'make clean' to remove binary files.

'make clear' to erase .pgm files from Frames folder.

'make catch' to compile catch.hpp tests

to run, type the following:

```bash
./findcomp.exe img.pgm -s min max -t threshold -p -w outputname.pgm inputname.pgm
```

to Run catch tests.
```bash
./catch_test.exe
```
where min is the minimum component size
max is the maximum component size
-p will print all component data
-w will just output to the specified file.

#Put pgm files in the Image folder
#The output goes into the Output folder.

ConnectedComponent.h is the header file which contains the declarations for methods which are implemented in ConnectedComponent.cpp. This class is a container class which contains the coordinates for pixels that pass the condition of being above the threshold.

PGMimageProcessor.h is the header file which contains the declarations for methods which are implemented in PGMimageProcessor.cpp. This class will read in pgm image data and output the results as well. It peforms the calculations needed to process the image and output the contrasted image.

findcomp.cpp is the main driver file that runs the program and creates a PGMimageProcessor object.


.gitignore excludes binary files from the repository.