#ifndef _BOUNDING_BOX_H_
#define _BOUNDING_BOX_H_

#include <vector>

struct BoundingBox
{
  BoundingBox(std::vector<double> const & min_, 
              std::vector<double> const & max_)
    : min(min_)
    , max(max_)
  {}

  std::vector<double> min;
  std::vector<double> max;

};


#endif