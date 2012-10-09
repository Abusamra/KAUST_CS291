#include <math.h>
#include "stuff.h"

static double step1( double i ) { return i * i; }
static double step2( double i ) { return i + i; }
static double step3( double i ) { return pow( i, i ); }

double do_stuff( double i ) { return step3( step2( step1( i ) ) ); }


// ================================================================= 
/* UNIT TESTS */
#ifdef UNIT_TEST
#include <check.h>
#include <stdlib.h>    /* for rand() */

START_TEST (test_step1)
{
    double d = (double) rand();
    fail_unless( step1(d) == (d * d), "Step 1 does not square" );
}
END_TEST

START_TEST (test_step2)
{
    double d = (double) rand();
    fail_unless( step2(d) == (d + d), "Step 2 does not double" );
}
END_TEST

START_TEST (test_step3)
{
    double d = (double) rand();
    fail_unless( step3(d) == pow(d, d), "Step 3 does not exponentiate" );
}
END_TEST

TCase * create_static_testcase(void) {
    TCase * tc = tcase_create("Static Functions");
    tcase_add_test(tc, test_step1);
    tcase_add_test(tc, test_step2);
    tcase_add_test(tc, test_step3);
    return tc;
}

#endif
