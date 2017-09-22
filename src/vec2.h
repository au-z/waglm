#pragma once
#include <array>
#include "vec3.h"
// #include "mat2.h";
// #include "mat2d.h";

namespace waglm {
  class vec2 {
    std::array <float, 2> vec;
    static const unsigned int N = 2;
  public:
    vec2();
    float x() { return vec[0]; }
    float y() { return vec[1]; }
    static vec2 create();
    static vec2 fromValues(float, float);
    static vec2 clone(vec2&);
    static vec2 copy(vec2&, vec2&);
    static vec2 add(vec2&, vec2&, vec2&);
    static vec2 subtract(vec2&, vec2&, vec2&);
    static vec2 sub(vec2&, vec2&, vec2&);
    static vec2 multiply(vec2&, vec2&, vec2&);
    static vec2 divide(vec2&, vec2&, vec2&);
    static vec2 ceil(vec2&, vec2&);
    static vec2 floor(vec2&, vec2&);
    static vec2 min(vec2&, vec2&, vec2&);
    static vec2 max(vec2&, vec2&, vec2&);
    static vec2 round(vec2&, vec2&);
    static vec2 scale(vec2&, vec2&, float);
    static vec2 scaleAndAdd(vec2&, vec2&, vec2&, float);
    static float distance(vec2&, vec2&);
    static float squaredDistance(vec2&, vec2&);
    static float length(vec2&);
    static float squaredLength(vec2&);
    static vec2 negate(vec2&, vec2&);
    static vec2 inverse(vec2&, vec2&);
    static vec2 normalize(vec2&, vec2&);
    static float dot(vec2&, vec2&);
    static vec3 cross(vec3&, vec2&, vec2&);
    static vec2 lerp(vec2&, vec2&, vec2&, float);
    static vec2 random(vec2&, float);
    // static vec2 transformMat2(vec2&, vec2&, mat2&);
    // static vec2 transformMat2d(vec2&, vec2&, mat2d&);
    // static vec2 transformMat3(vec2&, vec2&, mat3&);
    // static vec2 transformMat4(vec2&, vec2&, mat4&);
    static std::string str(vec2& a);
    vec2& operator=(const vec2& v);
    float& operator[](unsigned int i) { return vec[i]; }
    const float& operator[](unsigned int i) const { return vec[i]; }
    ~vec2 ();
  };
}
