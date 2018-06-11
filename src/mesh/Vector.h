#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <array>

struct Vector
{
  using Type = std::array<double,3>;

  Vector() : coords({0,0,0}) {}
  Vector(double x, double y, double z) : coords({x,y,z}) {}

  double operator[](Type::size_type n) const
  {
    return coords[n];
  }

  Vector scale(double const factor)
  {
    return Vector(factor*coords[0], factor*coords[1], factor*coords[2]);
  }

// struct hashFunc{
//     size_t operator()(const TPoint3D &k) const{
//     size_t h1 = std::hash<double>()(k.x);
//     size_t h2 = std::hash<double>()(k.y);
//     size_t h3 = std::hash<double>()(k.z);
//     return (h1 ^ (h2 << 1)) ^ h3;
//     }
// };

// struct equalsFunc{
//   bool operator()( const TPoint3D& lhs, const TPoint3D& rhs ) const{
//     return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
//   }
// };

  Type coords;
};

#endif