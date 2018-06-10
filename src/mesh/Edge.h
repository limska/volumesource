#ifndef _EDGE_H_
#define _EDGE_H_

#include <algorithm>

struct Edge
{
  Edge() = delete;
  Edge(unsigned int id1_, unsigned int id2_)
   : id1(std::min(id1,id2))
   , id2(std::max(id1,id2))
  {}

  unsigned int id1;
  unsigned int id2;
};

#endif