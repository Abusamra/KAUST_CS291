
 # Unit-test Makefile
#--------------------------------------------------------- Definitions
TGT_NAME    =    prog
TGT_SRC     =    ../prog.c

OPT         =    -O3 -fprofile-arcs -ftest-coverage
ERR         =    -Wall
INC_PATH    =    -I. -I.. -I../src -I.. -I../check-0.9.8/src
LIB_PATH    =    -L..
LD_PATH     =     ..

#---------------------------------------------------------
CC          =     gcc
RM          =    rm -f

# NOTE: check libs must be enclosed by --whole-archive directives
CHECK_LIBS  =    -Wl,--whole-archive -lcheck -Wl,--no-whole-archive
LIBS        =    -lm $(CHECK_LIBS)  

# NOTE: UNIT_TEST enables the static-function test case in stuff.c
CC_FLAGS    =     $(INC_PATH) $(OPT) $(ERR) -DUNIT_TEST
# NOTE: check libs must be enclosed by --whole-archive directives
LD_FLAGS    =    $(LIB_PATH)


 # Test 1 : Simple test to ensure that linking against the library succeeds
TEST1        =    test_link
TEST1_SRC    =    test_link.c

TEST1_FLAGS  =    $(CC_FLAGS)  $(LD_FLAGS)
TEST1_LIBS   =    $(LIBS) -l$(TGT_NAME)

TESTS        =    $(TEST1)

# ...

$(TEST1): $(TEST1_SRC)
	$(CC) $(TEST1_FLAGS) -o $@ $^ $(TEST1_LIBS)
#---------------------------------------------------------- Targets
all: $(TESTS)
.PHONY: all clean check


clean:
	$(RM) $(TESTS) *.gcno *.gcda


check:
	@for t in $(TESTS); do                          \
	LD_LIBRARY_PATH='$(LD_PATH)' ./$$t;     \
	done


