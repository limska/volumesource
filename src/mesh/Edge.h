#ifndef _EDGE_H_
#define _EDGE_H_

#include <algorithm>
#include <cstddef>

struct Edge
{
  Edge() = delete;
  Edge(std::size_t id1_, std::size_t id2_)
   : id1(std::min(id1,id2))
   , id2(std::max(id1,id2))
  {}

  std::size_t id1;
  std::size_t id2;
};

#endif