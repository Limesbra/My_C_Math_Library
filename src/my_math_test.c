#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "my_math.h"

#define EPS 0.000001
/*------------------------EXP-------------------------*/
START_TEST(s21_exp_test) {
  ck_assert_double_eq_tol(exp(0), my_exp(0), EPS);
  ck_assert_double_eq(exp(INFINITY), my_exp(INFINITY));
  ck_assert_double_eq(exp(-INFINITY), my_exp(-INFINITY));
  ck_assert_double_eq(exp(MY_MAX_DOUBLE), my_exp(MY_MAX_DOUBLE));
  ck_assert_double_eq(exp(-MY_MAX_DOUBLE), my_exp(-MY_MAX_DOUBLE));
  ck_assert_ldouble_nan(my_exp(MY_NAN));
  ck_assert_double_eq_tol(exp(1), my_exp(1), EPS);
  ck_assert_double_eq_tol(exp(-1), my_exp(-1), EPS);
  ck_assert_double_eq_tol(exp(-0), my_exp(-0), EPS);
  ck_assert_double_eq_tol(exp(-0.04), my_exp(-0.04), EPS);
  ck_assert_double_eq_tol(exp(-7), my_exp(-7), EPS);
  ck_assert_double_eq_tol(exp(-21), my_exp(-21), EPS);
  ck_assert_double_eq_tol(exp(0.52), my_exp(0.52), EPS);
  ck_assert_double_eq_tol(exp(7), my_exp(7), EPS);
  ck_assert_double_eq_tol(exp(20), my_exp(20), EPS);
}
END_TEST
/*------------------------LOG-------------------------*/
START_TEST(my_log_test) {
  ck_assert_double_eq(log(0), my_log(0));
  ck_assert_double_eq(log(INFINITY), my_log(INFINITY));
  ck_assert_ldouble_nan(my_log(-INFINITY));
  ck_assert_ldouble_nan(my_log(NAN));
  ck_assert_double_eq(log(1), my_log(1));
  ck_assert_double_nan(my_log(-1));
  for (double x = 0.9; x < 1.1; x += 0.01) {
    ck_assert_double_eq_tol(log(x), my_log(x), EPS);
  }
}
END_TEST
/*------------------------POW-------------------------*/
START_TEST(my_pow_test) {
  ck_assert_double_eq(pow(123, 0), my_pow(123, 0));
  ck_assert_double_eq(pow(0, 123), my_pow(0, 123));
  ck_assert_ldouble_eq(pow(INFINITY, INFINITY), my_pow(INFINITY, INFINITY));
  ck_assert_ldouble_eq(pow(-INFINITY, INFINITY), my_pow(-INFINITY, INFINITY));
  ck_assert_ldouble_eq(pow(INFINITY, -INFINITY), my_pow(INFINITY, -INFINITY));
  ck_assert_double_eq(pow(INFINITY, 0), my_pow(INFINITY, 0));
  ck_assert_double_eq(pow(-INFINITY, 0), my_pow(-INFINITY, 0));
  ck_assert_double_eq(pow(0, INFINITY), my_pow(0, INFINITY));
  ck_assert_double_eq(pow(0, -INFINITY), my_pow(0, -INFINITY));
  ck_assert_double_eq(pow(INFINITY, 5), my_pow(INFINITY, 5));
  ck_assert_double_eq(pow(INFINITY, -5), my_pow(INFINITY, -5));
  ck_assert_double_eq(pow(-INFINITY, 5), my_pow(-INFINITY, 5));
  ck_assert_double_eq(pow(-INFINITY, 6), my_pow(-INFINITY, 6));
  ck_assert_double_eq(pow(-INFINITY, -5), my_pow(-INFINITY, -5));
  ck_assert_double_nan(my_pow(NAN, NAN));
  ck_assert_double_nan(my_pow(INFINITY, NAN));
  ck_assert_double_nan(my_pow(-INFINITY, NAN));
  ck_assert_double_nan(my_pow(NAN, INFINITY));
  ck_assert_double_nan(my_pow(NAN, -INFINITY));
  ck_assert_double_nan(my_pow(NAN, -2.5));
  ck_assert_double_nan(my_pow(NAN, 2.5));
  ck_assert_double_eq(pow(NAN, 0), my_pow(NAN, 0));
  ck_assert_double_nan(my_pow(2.5, NAN));
  ck_assert_double_nan(my_pow(-2.5, NAN));
  ck_assert_double_nan(my_pow(0, NAN));
  ck_assert_double_nan(my_pow(-2.5, 0.5));
  ck_assert_double_nan(my_pow(-2.5, -0.5));
  ck_assert_double_nan(my_pow(-2.5, 2.5));
  ck_assert_double_nan(my_pow(-2.5, -2.5));
  ck_assert_double_eq_tol(pow(2, 5), my_pow(2, 5), EPS);
  ck_assert_double_eq_tol(pow(-2, 5), my_pow(-2, 5), EPS);
  ck_assert_double_eq_tol(pow(2.5, 0), my_pow(2.5, 0), EPS);
  ck_assert_double_eq_tol(pow(-2.5, 0), my_pow(-2.5, 0), EPS);
  ck_assert_double_eq_tol(pow(0, 2.5), my_pow(0, 2.5), EPS);
  ck_assert_double_infinite(my_pow(0, -2.5));
  ck_assert_double_eq_tol(pow(2.5, 1), my_pow(2.5, 1), EPS);
  ck_assert_double_eq_tol(pow(2.5, -0), my_pow(2.5, -0), EPS);
  ck_assert_double_eq_tol(pow(-2.5, -0), my_pow(-2.5, -0), EPS);
  ck_assert_double_eq_tol(pow(0.0000045, 0.0000045),
                          my_pow(0.0000045, 0.0000045), EPS);
}
/*------------------------SQRT-------------------------*/
START_TEST(my_sqrt_test) {
  ck_assert_ldouble_nan(my_sqrt(NAN));
  ck_assert_ldouble_eq_tol(my_sqrt(0.5), sqrt(0.5), EPS);
  ck_assert_ldouble_nan(my_sqrt(-1));
  ck_assert_ldouble_nan(my_sqrt(-1.5));
  ck_assert_ldouble_eq_tol(my_sqrt(1), sqrt(1), EPS);
  ck_assert_ldouble_eq_tol(my_sqrt(1.1), sqrt(1.1), EPS);
  ck_assert_ldouble_eq_tol(my_sqrt(0), sqrt(0), EPS);
  ck_assert_ldouble_eq_tol(my_sqrt(-0), sqrt(-0), EPS);
  ck_assert_double_eq_tol(my_sqrt(25), sqrt(25), EPS);
  ck_assert_double_eq_tol(my_sqrt(43), sqrt(43), EPS);
  ck_assert_double_eq_tol(my_sqrt(12.34), sqrt(12.34), EPS);
  ck_assert_ldouble_nan(my_sqrt(-INFINITY));
  ck_assert_ldouble_nan(my_sqrt(INFINITY));
}
END_TEST
/*------------------------SIN-------------------------*/
START_TEST(my_sin_test) {
  ck_assert_ldouble_eq_tol(my_sin(0), sin(0), EPS);
  ck_assert_ldouble_eq_tol(my_sin(MY_PI), sin(MY_PI), EPS);
  ck_assert_ldouble_eq_tol(my_sin(MY_PI / 2), sin(MY_PI / 2), EPS);
  ck_assert_ldouble_eq_tol(my_sin(-1), sin(-1), EPS);
  ck_assert_ldouble_eq_tol(my_sin(-MY_PI), sin(-MY_PI), EPS);
  ck_assert_ldouble_eq_tol(my_sin(-MY_PI / 2), sin(-MY_PI / 2), EPS);
}
END_TEST
START_TEST(my_cos_test) {
  ck_assert_ldouble_eq_tol(my_cos(0), cos(0), EPS);
  ck_assert_ldouble_eq_tol(my_cos(MY_PI), cos(MY_PI), EPS);
  ck_assert_ldouble_eq_tol(my_cos(MY_PI / 2), cos(MY_PI / 2), EPS);
  ck_assert_ldouble_eq_tol(my_cos(-MY_PI), cos(-MY_PI), EPS);
  ck_assert_ldouble_eq_tol(my_cos(-MY_PI / 2), cos(-MY_PI / 2), EPS);
}
END_TEST
START_TEST(my_tan_test) {
  ck_assert_ldouble_eq_tol(my_tan(0), tan(0), EPS);
  ck_assert_ldouble_eq_tol(my_tan(MY_PI), tan(MY_PI), EPS);
  ck_assert_ldouble_eq_tol(my_tan(MY_PI / 4), tan(MY_PI / 4), EPS);
  ck_assert_ldouble_eq_tol(my_tan(-MY_PI), tan(-MY_PI), EPS);
  ck_assert_ldouble_eq_tol(my_tan(-MY_PI / 4), tan(-MY_PI / 4), EPS);
}
END_TEST

/*------------------------acos-------------------------*/
START_TEST(my_acos_test) {
  ck_assert_ldouble_eq_tol(my_acos(0), acos(0), EPS);
  ck_assert_ldouble_eq_tol(my_acos(1), acos(1), EPS);
  ck_assert_ldouble_eq_tol(my_acos(-1), acos(-1), EPS);
  ck_assert_double_nan(my_acos(MY_INFINITY));
  ck_assert_double_nan(my_acos(MY_NAN));
  for (double x = 0.9; x >= -0.9; x -= 0.01) {
    ck_assert_ldouble_eq_tol(my_acos(x), acos(x), EPS);
  }
  ck_assert_double_nan(my_acos(2));
}
END_TEST
/*------------------------asin-------------------------*/
START_TEST(my_asin_test) {
  ck_assert_ldouble_eq_tol(my_asin(0), asin(0), EPS);
  for (double x = 0.9; x >= -0.9; x -= 0.01) {
    ck_assert_ldouble_eq_tol(my_asin(x), asin(x), EPS);
  }
  ck_assert_ldouble_eq_tol(my_asin(0), asin(0), EPS);
  ck_assert_ldouble_eq_tol(my_asin(1), asin(1), EPS);
  ck_assert_ldouble_eq_tol(my_asin(-1), asin(-1), EPS);
  ck_assert_double_nan(my_asin(200));
  ck_assert_double_nan(my_asin(-200));
  ck_assert_double_nan(my_asin(MY_INFINITY));
  ck_assert_double_nan(my_asin(MY_NAN));
}
END_TEST
/*------------------------atan-------------------------*/
START_TEST(my_atan_test) {
  ck_assert_ldouble_eq_tol(my_atan(1), atan(1), EPS);
  ck_assert_ldouble_eq_tol(my_atan(-1), atan(-1), EPS);

  ck_assert_double_nan(my_atan(MY_NAN));
  ck_assert_ldouble_eq_tol(my_atan(-MY_INFINITY), atan(-MY_INFINITY), EPS);
  ck_assert_ldouble_eq_tol(my_atan(MY_INFINITY), atan(MY_INFINITY), EPS);
  for (double x = 0.9; x >= -0.9; x -= 0.001) {
    ck_assert_ldouble_eq_tol(my_atan(x), atan(x), EPS);
  }
  for (double y = 10; y <= 200; y += 10) {
    ck_assert_ldouble_eq_tol(my_atan(y), atan(y), EPS);
  }
  for (double z = -10; z >= -200; z -= 10) {
    ck_assert_ldouble_eq_tol(my_atan(z), atan(z), EPS);
  }
}

/*------------------------abs-------------------------*/

START_TEST(my_abs_test) {
  ck_assert_int_eq(my_abs(0), abs(0));
  ck_assert_int_eq(my_abs(1), abs(1));
  ck_assert_int_eq(my_abs(-1), abs(-1));
  ck_assert_int_eq(my_abs(2), abs(2));
  ck_assert_int_eq(my_abs(-7), abs(-7));
  ck_assert_int_eq(my_abs(-9), abs(-9));
}
END_TEST
/*------------------------fabs-------------------------*/

START_TEST(my_fabs_test) {
  ck_assert_ldouble_eq_tol(my_fabs(0.1), fabs(0.1), EPS);
  ck_assert_ldouble_eq_tol(my_fabs(-0.4), fabs(-0.4), EPS);
  ck_assert_ldouble_eq_tol(my_fabs(-7.659), fabs(-7.659), EPS);
  ck_assert_ldouble_eq(my_fabs(-INFINITY), fabs(-INFINITY));
  ck_assert_double_nan(my_fabs(MY_NAN));
}
END_TEST
/*------------------------ceil-------------------------*/

START_TEST(my_ceil_test) {
  ck_assert_double_nan(my_ceil(MY_NAN));
  ck_assert_ldouble_eq(my_ceil(-1.0 / 0.0), ceil(-1.0 / 0.0));
  ck_assert_ldouble_eq_tol(my_ceil(-0.5), ceil(-0.5), EPS);
  ck_assert_ldouble_eq_tol(my_ceil(1.000000001), ceil(1.000000001), EPS);
  ck_assert_ldouble_eq_tol(my_ceil(-2.000000001), ceil(-2.000000001), EPS);
  ck_assert_ldouble_eq_tol(my_ceil(-0.0), ceil(-0.0), EPS);
}
END_TEST
/*------------------------floor-------------------------*/

START_TEST(my_floor_test) {
  ck_assert_double_nan(my_floor(MY_NAN));
  ck_assert_ldouble_eq(my_floor(-1.0 / 0.0), floor(-1.0 / 0.0));
  ck_assert_ldouble_eq_tol(my_floor(-0.5), floor(-0.5), EPS);
  ck_assert_ldouble_eq_tol(my_floor(1.000000001), floor(1.000000001), EPS);
  ck_assert_ldouble_eq_tol(my_floor(-2.000000001), floor(-2.000000001), EPS);
  ck_assert_ldouble_eq_tol(my_floor(-0.0), floor(-0.0), EPS);
}
END_TEST
/*------------------------fmod-------------------------*/

START_TEST(my_fmod_test) {
  ck_assert_double_nan(my_fmod(0, 0));
  ck_assert_ldouble_eq_tol(my_fmod(8, 2), fmod(8, 2), EPS);
  ck_assert_ldouble_eq_tol(my_fmod(8, 3), fmod(8, 3), EPS);
  ck_assert_ldouble_eq_tol(my_fmod(4, 3), fmod(4, 3), EPS);
  ck_assert_ldouble_nan(my_fmod(-1, 0));
  ck_assert_ldouble_nan(my_fmod(INFINITY, 1));
  ck_assert_ldouble_eq(my_fmod(1, INFINITY), fmod(1, INFINITY));
  ck_assert_ldouble_eq(my_fmod(14.7, -INFINITY), fmod(14.7, -INFINITY));
  ck_assert_ldouble_nan(my_fmod(INFINITY, 14.7));
}
END_TEST

int main() {
  Suite *test = suite_create("math");
  TCase *tc_1 = tcase_create("math");
  SRunner *sr = srunner_create(test);

  int fail;
  suite_add_tcase(test, tc_1);

  tcase_add_test(tc_1, my_sin_test);
  tcase_add_test(tc_1, my_cos_test);
  tcase_add_test(tc_1, my_tan_test);
  tcase_add_test(tc_1, my_acos_test);
  tcase_add_test(tc_1, my_asin_test);
  tcase_add_test(tc_1, my_atan_test);
  tcase_add_test(tc_1, my_exp_test);
  tcase_add_test(tc_1, my_log_test);
  tcase_add_test(tc_1, my_pow_test);
  tcase_add_test(tc_1, my_sqrt_test);
  tcase_add_test(tc_1, my_abs_test);
  tcase_add_test(tc_1, my_fabs_test);
  tcase_add_test(tc_1, my_ceil_test);
  tcase_add_test(tc_1, my_floor_test);
  tcase_add_test(tc_1, my_fmod_test);

  srunner_run_all(sr, CK_ENV);
  fail = srunner_ntests_failed(sr);
  srunner_free(sr);
  return fail == 0 ? 0 : 1;
}
