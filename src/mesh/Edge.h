#ifndef _EDGE_H_
#define _EDGE_H_

#include <algorithm>

struct Edge
{
  Edge() = delete;
  Edge(int id1_, int id2_)
   : id1(std::min(id1,id2))
   , id2(std::max(id1,id2))
  {}

  int id1;
  int id2;
};

#endif