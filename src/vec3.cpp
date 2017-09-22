#include "vec3.h"
#include <string>
#include <ctime>
#include <math.h>
#include <sstream>
#include <iomanip>
#include "math.h"
using namespace waglm;

vec3::vec3() {
  vec[0] = 0.0;
  vec[1] = 0.0;
  vec[2] = 0.0;
}

vec3 vec3::create() {
  return vec3::fromValues(0.0, 0.0, 0.0);
}

vec3 vec3::fromValues(float x, float y, float z) {
  vec3 out;
  out[0] = x;
  out[1] = y;
  out[2] = z;
  return out;
}

vec3 vec3::clone(vec3& a) {
  return vec3::fromValues(a[0], a[1], a[2]);
}

vec3 vec3::copy(vec3& out, vec3& a) {
  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  return out;
}

vec3 vec3::add(vec3& out, vec3& a, vec3& b) {
  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  return out;
}

vec3 vec3::subtract(vec3& out, vec3& a, vec3& b) {
  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  return out;
}

vec3 vec3::sub(vec3& out, vec3& a, vec3& b) {
  return vec3::subtract(out, a, b);
}

vec3 vec3::multiply(vec3& out, vec3& a, vec3& b) {
  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  return out;
}

vec3 vec3::divide(vec3& out, vec3& a, vec3& b) {
  out[0] = a[0] / b[0];
  out[1] = a[1] / b[1];
  out[2] = a[2] / b[2];
  return out;
}

vec3 vec3::ceil(vec3& out, vec3& a) {
  out[0] = ::ceil(a[0]);
  out[1] = ::ceil(a[1]);
  out[2] = ::ceil(a[2]);
  return out;
}

vec3 vec3::floor(vec3& out, vec3& a) {
  out[0] = ::floor(a[0]);
  out[1] = ::floor(a[1]);
  out[2] = ::floor(a[2]);
  return out;
}

vec3 vec3::min(vec3& out, vec3& a, vec3& b) {
  out[0] = math::min(a[0], b[0]);
  out[1] = math::min(a[1], b[1]);
  out[2] = math::min(a[2], b[2]);
  return out;
}

vec3 vec3::max(vec3& out, vec3& a, vec3& b) {
  out[0] = math::max(a[0], b[0]);
  out[1] = math::max(a[1], b[1]);
  out[2] = math::max(a[2], b[2]);
  return out;
}

vec3 vec3::round(vec3& out, vec3& a) {
  out[0] = ::rint(a[0]);
  out[1] = ::rint(a[1]);
  out[2] = ::rint(a[2]);
  return out;
}

vec3 vec3::scale(vec3& out, vec3& a, float s) {
  out[0] = a[0] * s;
  out[1] = a[1] * s;
  out[2] = a[2] * s;
  return out;
}

vec3 vec3::scaleAndAdd(vec3& out, vec3& a, vec3& b, float s) {
  out[0] = a[0] + (b[0] * s);
  out[1] = a[1] + (b[1] * s);
  out[2] = a[2] + (b[2] * s);
  return out;
}

float vec3::distance(vec3& a, vec3& b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  float z = b[2] - a[2];
  return ::sqrt(x*x + y*y + z*z);
}

float vec3::squaredDistance(vec3& a, vec3& b) {
  float x = b[0] - a[0];
  float y = b[1] - a[1];
  float z = b[2] - a[2];
  return x*x + y*y + z*z;
}

float vec3::length(vec3& a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  return ::sqrt(x*x + y*y + z*z);
}

float vec3::squaredLength(vec3& a) {
  float x = a[0];
  float y = a[1];
  float z = a[2];
  return x*x + y*y + z*z;
}

vec3 vec3::negate(vec3& out, vec3& a) {
  out[0] = -a[0];
  out[1] = -a[1];
  out[2] = -a[2];
  return out;
}

vec3 vec3::inverse(vec3& out, vec3& a) {
  out[0] = 1.0f / a[0];
  out[1] = 1.0f / a[1];
  out[2] = 1.0f / a[2];
  return out;
}

vec3 vec3::normalize(vec3& out, vec3& a) {
  float len = vec3::length(a);
  if(len > 0) {
    len = 1 / ::sqrt(len);
    out[0] = a[0] * len;
    out[1] = a[1] * len;
    out[2] = a[2] * len;
  }
  return out;
}

float vec3::dot(vec3& a, vec3& b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

vec3 vec3::cross(vec3& out, vec3& a, vec3& b) {
  float ax = a[0]; float ay = a[1]; float az = a[2];
  float bx = b[0]; float by = b[1]; float bz = b[2];

  out[0] = ay * bz - az * by;
  out[1] = az * bx - ax * bz;
  out[2] = ax * by - ay * bx;
  return out;
}

vec3 vec3::lerp(vec3& out, vec3& a, vec3& b, float t) {
  float ax = a[0];
  float ay = a[1];
  float az = a[2];
  out[0] = ax + t * (b[0] - ax);
  out[1] = ay + t * (b[1] - ay);
  out[2] = az + t * (b[2] - az);
  return out;
}

vec3 vec3::random(vec3& out, float s = 1.0) {
  srand((int) time(0));
  float r = rand();
  out[0] = ::cos(r) * s;
  out[1] = ::sin(r) * s;
  out[2] = ::tan(r) * s;
  return out;
}

std::string vec3::str(vec3& a) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(3) << a[0];
  std::string a0(ss.str());
  ss.str(std::string());
  ss << std::fixed << std::setprecision(3) << a[1];
  std::string a1(ss.str());
  ss.str(std::string());
  ss << std::fixed << std::setprecision(3) << a[2];
  std::string a2(ss.str());
  return "vec3(" + a0 + ", " + a1 + ", " + a2 + ")";
}

vec3& vec3::operator= (const vec3& v) {
  vec = v.vec;
  return *this;
}

vec3::~vec3 () {}