#include <iostream>
#include <stdio.h>
#include "vec2.h"
#include "vec3.h"
using namespace waglm;

int main(int argc, char **argv) {
  vec2 s;
  vec2::random(s, 10);
  std::cout << vec2::str(s) << std::endl;
}