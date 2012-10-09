#include <math.h>
#include "prog.h"

 static double calc1( double i ) { return i * i; }
  static double calc2( double i ) { return i + i; }
  static double calc3( double i ) { return pow( i, i ); }
//  static double calc4( double i ) { return i - i; }

double do_calc( double i ) { return calc3( calc2( calc1( i ) ) ); }


// =================================================================  UNIT TESTS */
#ifdef UNIT_TEST
#include <check.h>
#include <stdlib.h>    /* for rand() */

START_TEST (test_calc1)
{
    double d = (double) rand();
    fail_unless( calc1(d) == (d * d), "Step 1 does not square" );
}
END_TEST

START_TEST (test_calc2)
{
    double d = (double) rand();
    fail_unless( calc2(d) == (d + d), "Step 2 does not double" );
}
END_TEST

START_TEST (test_calc3)
{
    double d = (double) rand();
    fail_unless( calc3(d) == pow(d, d), "Step 3 does not exponentiate" );
}
END_TEST

TCase * create_static_testcase(void) {
    TCase * tc = tcase_create("Static Functions");
    tcase_add_test(tc, test_calc1);
    tcase_add_test(tc, test_calc2);
    tcase_add_test(tc, test_calc3);
    return tc;
}

#endif
