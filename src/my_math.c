#include "my_math.h"

#include <stdio.h>

int my_abs(int x) {
  if (x < 0) x = -x;
  return x;
}

long double my_fabs(double x) {
  if (x < 0) x = -x;
  return (double)x;
}

long double my_ceil(double x) {
  long double result = (long long)x;
  if (MY_INFINITY_EQ(x) || x != x || x == -0.) {
    result = x;
  } else if (x > -1 && x <= 0)
    result = -0.;

  else if (x > 0)
    result++;

  return result;
}

long double my_floor(double x) {
  long double result = (long long)x;
  if (MY_INFINITY_EQ(x) || x != x || x == -0.) {
    result = x;
  } else if (x < 0)
    result--;

  return result;
}

long double my_fmod(double x, double y) {
  long long sfmod = x / y;
  long double result = (long double)x - sfmod * (long double)y;
  if ((y == 0) || MY_INFINITY_EQ(x))
    result = MY_NAN;
  else if (MY_INFINITY_EQ(y))
    result = x;
  return result;
}

long double my_sin(double x) {
  int minus = 0;
  if (x < 0) {
    x = -x;
    minus++;
  }
  while (x > 2 * MY_PI) x -= 2 * MY_PI;
  long double result = 0.0, term = x;
  int n = 1;
  for (int i = 0; term > 1e-16; i++) {
    result += ((i % 2) == 0) ? term : -term;
    term *= (x / ++n);
    term *= (x / ++n);
  }
  return minus ? -result : result;
}

long double my_cos(double x) { return my_sin(x + MY_PI / 2); }

long double my_tan(double x) { return my_sin(x) / my_cos(x); };

long double my_acos(double x) {
  long double acos = 0;
  if (x != x)
    acos = MY_NAN;
  else if (x == MY_INFINITY || x == -MY_INFINITY)
    acos = MY_NAN;
  else if (x == 0)
    acos = MY_PI / 2;
  else if (x == 1)
    acos = 0;
  else if (x == -1)
    acos = MY_PI;
  if (0 < x && x < 1)
    acos = my_atan(my_sqrt(1 - x * x) / x);
  else if (-1 < x && x < 0)
    acos = MY_PI + my_atan(my_sqrt(1 - x * x) / x);
  else if (x < -1 || x > 1)
    acos = MY_NAN;
  return acos;
}

long double my_asin(double x) {
  long double asin = 0;
  if (x != x)
    asin = MY_NAN;
  else if (x == MY_INFINITY || x == -MY_INFINITY)
    asin = MY_NAN;
  else if (x == 1)
    asin = MY_PI / 2;
  else if (x == -1)
    asin = -MY_PI / 2;
  else if (x < -1. || x > 1.)
    asin = MY_NAN;
  else if (-1. < x && x < 1.)
    asin = my_atan(x / my_sqrt(1 - x * x));
  return asin;
}

long double my_atan(double x) {
  const long double MY_ATAN_1 = 0.7853981633974480L;
  long double atan_sum = 0;
  int z = 1;
  long double k = x;
  long double v = 1 / x;
  if (x != x)
    atan_sum = MY_NAN;
  else if (x == MY_INFINITY)
    atan_sum = MY_PI / 2;
  else if (x == -MY_INFINITY)
    atan_sum = -MY_PI / 2;
  else if (x == 1)
    atan_sum = MY_ATAN_1;
  else if (x == -1)
    atan_sum = -MY_ATAN_1;
  else if (-1. < x && x < 1.) {
    for (int i = 0; i < 5000; i++) {
      atan_sum += (z * k) / (1 + (2 * i));
      z *= -1;
      k *= x * x;
    }
  } else if (x < -1. || x > 1.) {
    for (int i = 0; i < 7000; i++) {
      atan_sum += (z * v) / (1 + (2 * i));
      z *= -1;
      v /= x * x;
    }
    if (x > 0) {
      atan_sum = (MY_PI * x) / (2 * x) - atan_sum;
    } else {
      atan_sum = (MY_PI * (-1 * x)) / (2 * x) - atan_sum;
    }
  }
  return atan_sum;
}

long double my_exp(double x) {
  long double result = 1, term_of_series = 1;
  int negative_flag = 0;
  long int i = 1;
  long double eps = 1e-17;
  if (x < 0) {
    x = -x;
    negative_flag++;
  }
  if (x != x) {
    result = MY_NAN;
  } else if (x == MY_INFINITY) {
    result = MY_INFINITY;
  } else {
    while (term_of_series > eps && i < 1e10 && result <= MY_MAX_DOUBLE) {
      term_of_series = term_of_series * x / i;
      result += term_of_series;
      i++;
    }
    if (result > MY_MAX_DOUBLE) {
      result = MY_INFINITY;
    }
  }
  if (negative_flag) result = 1 / result;
  return result;
}

long double my_log(double x) {
  long double result = 0;
  long double eps = 1e-17;
  if (x == 1) {
    result = 0;
  } else if (x == MY_INFINITY) {
    result = MY_INFINITY;
  } else if (x == 0)
    result = -MY_INFINITY;
  else if (x != x || x < 0)
    result = MY_NAN;
  else {
    long int i = 1;
    long double z = (x - 1.0) / (x + 1.0);
    long double term_of_series = 2 * z;
    long double temp = term_of_series;
    while ((term_of_series > eps || term_of_series < -eps) && i < 1e10 &&
           result <= MY_MAX_DOUBLE) {
      term_of_series = temp / i;
      temp *= z * z;
      result += term_of_series;
      if (result > MY_MAX_DOUBLE) {
        result = MY_INFINITY;
        break;
      }
      i += 2;
    }
    if (result > MY_MAX_DOUBLE) {
      result = MY_INFINITY;
    }
  }
  return result;
}

long double my_pow(double base, double exponent) {
  long double result = 0;
  long long int exponent_int = (long long int)exponent;
  long double exponent_float = exponent - (long double)exponent_int;
  int negative_flag = 0;
  if (exponent == 0)
    result = 1;
  else if (exponent == 1)
    result = base;
  else if ((base != base || exponent != exponent) && exponent != 0)
    result = MY_NAN;
  else if ((exponent == MY_INFINITY && base > 1) ||
           (exponent == -MY_INFINITY && base < 1 && base > 0))
    result = MY_INFINITY;
  else if ((exponent == MY_INFINITY && base < 1 && base > 0) ||
           (exponent == -MY_INFINITY && base > 1))
    result = 0;
  else if (base == MY_INFINITY && exponent > 0)
    result = MY_INFINITY;
  else if (base == MY_INFINITY && exponent < 0)
    result = 0;
  else if (base == -MY_INFINITY && exponent > 0 && exponent_int % 2 == 1 &&
           exponent_float == 0)
    result = -MY_INFINITY;
  else if (base == -MY_INFINITY &&
           ((exponent > 0 && exponent_int % 2 == 0 && exponent_float == 0) ||
            exponent == MY_INFINITY))
    result = MY_INFINITY;
  else if (base == -MY_INFINITY && exponent < 0)
    result = 0;
  else {
    if (base < 0) {
      negative_flag++;
      base = -base;
    }
    if (negative_flag && exponent_float != 0)
      result = MY_NAN;
    else {
      result = (exponent_float == 0)
                   ? my_pow_int(base, exponent_int)
                   : my_pow_int(base, exponent_int) *
                         my_exp(exponent_float * my_log(base));
    }
    if (negative_flag && exponent_int % 2 == 1 && exponent_float == 0)
      result = -result;
  }
  if (result >= MY_VERY_BIG_NUMBER) result = MY_INFINITY;
  return result;
}

long double my_pow_int(double base, long long int exponent) {
  long double result = 1;
  if (exponent > 0) {
    for (long long int i = 0; i < exponent; i++) {
      result *= base;
    }
  } else {
    for (long long int i = 0; i < -exponent; i++) {
      result /= base;
    }
  }
  return result;
}
long double my_sqrt(double x) {
  long double result = 1, y = 0;
  if (x < 0 || x != x)
    result = MY_NAN;
  else if (x == MY_INFINITY)
    result = x;
  while (my_fabs(result - y) > 1e-7) {
    y = result;
    result = (y + x / y) / 2;
  }
  return result;
}