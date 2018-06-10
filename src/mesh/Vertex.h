#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <vector>

struct Vertex
{
  Vertex() : coords({0,0,0}) {}
  Vertex(double x, double y, double z) : coords({x,y,z}) {}
  Vertex(std::vector<double> coords_) : coords(coords_) {}

  struct Compare
  {
    bool operator() (Vertex const & lhs, Vertex const & rhs) const
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

  std::vector<double> coords;
};

#endif