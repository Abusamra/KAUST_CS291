
#include <math.h>
#include <stdlib.h>

#include <stuff.h>
#include <check.h>
#define SUITE_NAME "Stuff"

/* ----------------------------------------------------------------- */
/* TESTS */

START_TEST (test_stuff_diff)
{
    double d = (double) rand();

    fail_unless ( do_stuff(d) != d, "do_stuff doesn't!" );
}
END_TEST

START_TEST (test_stuff_rand)
{
    double d = (double) rand();
    double dd = d * d;
    double sumdd = dd + dd;
    fail_unless ( do_stuff(d) == pow(sumdd, sumdd), "Incorrect result" );
}
END_TEST

/* ----------------------------------------------------------------- */
/* SUITE */

extern TCase * create_static_testcase(void);

Suite * create_suite(void) {
    Suite *s = suite_create( SUITE_NAME );

    /* Create test cases against library API */
    TCase *tc_core = tcase_create ("Core");
    tcase_add_test(tc_core, test_stuff_diff);
    tcase_add_test(tc_core, test_stuff_rand);
    suite_add_tcase(s, tc_core);

    /* Create test cases against static functions */
    suite_add_tcase( s, create_static_testcase() );

    return s;
}

int main( void ) {
    int num_fail;
    Suite *s = create_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all (sr, CK_NORMAL);
    num_fail = srunner_ntests_failed (sr);
    srunner_free (sr);
    return (num_fail == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
