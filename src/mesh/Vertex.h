#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <vector>

struct Vertex
{
  Vertex() = delete;
  Vertex(std::vector<double> coords_) : coords(coords_) {}

  std::vector<double> coords;
};

#endif