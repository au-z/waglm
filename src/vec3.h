#pragma once
#include <array>

namespace waglm {
  class vec3 {
    std::array <float, 2> vec;
    static const unsigned int N = 2;
  public:
    vec3();
    float x() { return vec[0]; }
    float y() { return vec[1]; }
    float z() { return vec[2]; }
    static vec3 create();
    static vec3 fromValues(float, float, float);
    static vec3 clone(vec3&);
    static vec3 copy(vec3&, vec3&);
    static vec3 add(vec3&, vec3&, vec3&);
    static vec3 subtract(vec3&, vec3&, vec3&);
    static vec3 sub(vec3&, vec3&, vec3&);
    static vec3 multiply(vec3&, vec3&, vec3&);
    static vec3 divide(vec3&, vec3&, vec3&);
    static vec3 ceil(vec3&, vec3&);
    static vec3 floor(vec3&, vec3&);
    static vec3 min(vec3&, vec3&, vec3&);
    static vec3 max(vec3&, vec3&, vec3&);
    static vec3 round(vec3&, vec3&);
    static vec3 scale(vec3&, vec3&, float);
    static vec3 scaleAndAdd(vec3&, vec3&, vec3&, float);
    static float distance(vec3&, vec3&);
    static float squaredDistance(vec3&, vec3&);
    static float length(vec3&);
    static float squaredLength(vec3&);
    static vec3 negate(vec3&, vec3&);
    static vec3 inverse(vec3&, vec3&);
    static vec3 normalize(vec3&, vec3&);
    static float dot(vec3&, vec3&);
    static vec3 cross(vec3&, vec3&, vec3&);
    static vec3 lerp(vec3&, vec3&, vec3&, float);
    static vec3 random(vec3&, float);
    static std::string str(vec3& a);
    vec3& operator=(const vec3& v);
    float& operator[](unsigned int i) { return vec[i]; }
    const float& operator[](unsigned int i) const { return vec[i]; }
    ~vec3 ();
  };
}