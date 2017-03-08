#include <stdio.h>
#include <stdlib.h>

#include <check.h>


START_TEST (test1)
{
    int n=0;
    ck_assert_int_eq(n, 0);
}
END_TEST

Suite *test_suite() {
  Suite *s = suite_create("Module");
  TCase *tc_test;

  tc_test = tcase_create("TestCase");
  tcase_add_test(tc_test, test1);

  suite_add_tcase(s, tc_test);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);  // important for debugging!

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return num_tests_failed;
}
