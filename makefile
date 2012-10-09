 # Library Makefile
# -------------------------------------------------------------------
NAME        =   prog
LIBNAME     =    lib$(NAME).so
ARCHIVE     =    lib$(NAME).a

DEBUG       =    -DDEBUG -ggdb
OPT         =    -O3
ERR         =    -Wall
INC_PATH    =    -I. -I.. -I../src -I.. -I../check-0.9.8/src
LIB_PATH    =   

#----------------------------------------------------------------
CC          =     gcc
LD          =    ld
AR          =    ar rc
RANLIB      =    ranlib
RM          =    rm -f

LIBS        =    -lm
CC_FLAGS    =     $(INC_PATH) $(DEBUG) $(OPT) $(ERR) -fPIC
LD_FLAGS    =    $(LIB_PATH) $(LIBS) -shared -soname=$(LIBNAME)
           

SRC         =    src/prog.c

OBJ         =    src/prog.o

#---------------------------------------------------------- Targets
all: $(LIBNAME)
.PHONY: all clean check

$(ARCHIVE): $(OBJ)
	$(AR) $(ARCHIVE) $^
	$(RANLIB) $(ARCHIVE)

$(LIBNAME): $(ARCHIVE)
	$(LD) $(LD_FLAGS) --whole-archive $< --no-whole-archive -o $@ 


.c.o: $(SRC)
	$(CC) $(CC_FLAGS) -o $@ -c $<

clean:
	[ -f $(LIBNAME) ] && $(RM) $(LIBNAME)|| [ 1 ]
	[ -f $(ARCHIVE) ] && $(RM) $(ARCHIVE)|| [ 1 ]
	[ -f $(OBJ) ] && $(RM) $(OBJ) || [ 1 ]
	cd tests && make clean

check: $(LIBNAME)
	cd tests && make && make check
