****the project with the following directory structure:***

*.Folder
    makefile
    src
      prog.c
      prog.h
    tests
      test_linck.c
      test_prog.c
      makefile
    check-0.9.8


=======================================================================
src folder
         contains :
prog.c   : very simple C code tha do calculations on double numbers  (the reason of picking very simple one bcs this my first time in makefile)
prog.h

tests folder 
          contains :
test_link.c : lib linking test 
test_prog.c : unit testing  
makefile 

check-0.9.8 :
Check is a unit testing framework for C. It features a simple interface
for defining unit tests,

to compile the package :
1. `cd' to the directory containing the package's source code and type
     `./configure' to configure the package for your system.

  2. Type `make' to compile the package.

  3. Optionally, type `make check' to run any self-tests that come with
     the package.

  4. Type ` sudo make install' to install the programs and any data files and
     documentation.

To start:
type 'make'
 type ' make check' 
 
 


