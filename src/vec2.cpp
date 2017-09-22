#include "vec2.h"
#include <string>
#include <ctime>
#include <math.h>
#include <iomanip>
#include <sstream>
#include "math.h"
using namespace waglm;

vec2::vec2() {
  vec[0] = 0.0;
  vec[1] = 0.0;
}

vec2 vec2::create() {
  return vec2::fromValues(0.0, 0.0);
}

vec2 vec2::fromValues(float x, float y) {
  vec2 out;
  out[0] = x;
  out[1] = y;
  return out;
}

vec2 vec2::clone(vec2& a) {
  return vec2::fromValues(a[0], a[1]);
}

vec2 vec2::copy(vec2& out, vec2& a) {
  out[0] = a[0];
  out[1] = a[1];
  return out;
}

vec2 vec2::add(vec2& out, vec2& a, vec2& b) {
  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  return out;
}

vec2 vec2::subtract(vec2& out, vec2& a, vec2& b) {
  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  return out;
}

vec2 vec2::sub(vec2& out, vec2& a, vec2& b) {
  return subtract(out, a, b);
}

vec2 vec2::multiply(vec2& out, vec2& a, vec2& b) {
  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  return out;
}

vec2 vec2::divide(vec2& out, vec2& a, vec2& b) {
  out[0] = a[0] / b[0];
  out[1] = a[1] / b[1];
  return out;
}

vec2 vec2::ceil(vec2& out, vec2& a) {
  out[0] = ::ceil(a[0]);
  out[1] = ::ceil(a[1]);
  return out;
}

vec2 vec2::floor(vec2& out, vec2& a) {
  out[0] = ::floor(a[0]);
  out[1] = ::floor(a[1]);
  return out;
}

vec2 vec2::min(vec2& out, vec2& a, vec2& b) {
  out[0] = math::min(a[0], b[0]);
  out[1] = math::min(a[1], b[1]);
  return out;
}

vec2 vec2::max(vec2& out, vec2& a, vec2& b) {
  out[0] = math::max(a[0], b[0]);
  out[1] = math::max(a[1], b[1]);
  return out;
}

vec2 vec2::round(vec2& out, vec2& a) {
  out[0] = ::rint(a[0]);
  out[1] = ::rint(a[1]);
  return out;
}

vec2 vec2::scale(vec2& out, vec2& a, float s) {
  out[0] = a[0] * s;
  out[1] = a[1] * s;
  return out;
}

vec2 vec2::scaleAndAdd(vec2& out, vec2& a, vec2& b, float s) {
  out[0] = a[0] + (b[0] * s);
  out[1] = a[1] + (b[1] * s);
  return out;
}

float vec2::distance(vec2& a, vec2& b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  return ::sqrt(x*x + y*y);
}

float vec2::squaredDistance(vec2& a, vec2& b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  return x*x + y*y;
}

float vec2::length(vec2& a) {
  float x = a[0];
  float y = a[1];
  return ::sqrt(x*x + y+y);
}

float vec2::squaredLength(vec2& a) {
  float x = a[0];
  float y = a[1];
  return x*x + y*y;
}

vec2 vec2::negate(vec2& out, vec2& a) {
  out[0] = -a[0];
  out[1] = -a[1];
  return out;
}

vec2 vec2::inverse(vec2& out, vec2& a) {
  out[0] = 1.0f / a[0];
  out[1] = 1.0f / a[1];
  return out;
}

vec2 vec2::normalize(vec2& out, vec2& a) {
  float x = a[0];
  float y = a[1];
  float len = x*x + y*y;
  if(len > 0) {
    len = 1 / ::sqrt(len);
    out[0] = a[0] * len;
    out[1] = a[1] * len;
  }
  return out;
}

float vec2::dot(vec2& a, vec2& b) { return a[0] * b[0] + a[1] * b[1]; }

vec3 vec2::cross(vec3& out, vec2& a, vec2& b) {
  float z = a[0] * b[1] - a[1] * b[0];
  out[0] = out[1] = 0;
  out[2] = z;
  return out;
}

vec2 vec2::lerp(vec2& out, vec2& a, vec2& b, float t) {
  float ax = a[0];
  float ay = a[1];
  out[0] = ax + t * (b[0] - ax);
  out[1] = ay + t * (b[1] - ay);
  return out;
}

vec2 vec2::random(vec2& out, float s = 1.0) {
  srand((int) time(0));
  float r = rand();
  out[0] = ::cos(r) * s;
  out[1] = ::sin(r) * s;
  return out;
}

std::string vec2::str(vec2& a) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(3) << a[0];
  std::string a0(ss.str());
  ss.str(std::string());
  ss << std::fixed << std::setprecision(3) << a[1];
  std::string a1(ss.str());
  return "vec2(" + a0 + ", " + a1 + ")";
}

vec2& vec2::operator= (const vec2& v) {
  vec = v.vec;
  return *this;
}

vec2::~vec2 () {}