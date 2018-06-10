#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <array>

struct Vector
{
  using Type = std::array<double,3>;

  Vector() : coords({0,0,0}) {}
  Vector(double x, double y, double z) : coords({x,y,z}) {}
  Vector(std::vector<double> coords_) : coords(coords_) {}

  struct Compare
  {
    bool operator() (Vector const & lhs, Vector const & rhs) const
    {
      if (lhs.coords[0] != rhs.coords[0])
      {
        return lhs.coords[0] < rhs.coords[0];
      }
      if (lhs.coords[1] != rhs.coords[1])
      {
        return lhs.coords[1] < rhs.coords[1];
      }
      return lhs.coords[2] < rhs.coords[2];
    }
  };

  double operator[](Type::size_type n) const
  {
    return coords[n];
  }


  Type coords;
};

#endif