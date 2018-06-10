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

  double volume() const
  {
    return (max[0]-min[0])*(max[1]-min[1])*(max[2]-min[2]);
  }

  std::vector<double> min;
  std::vector<double> max;

};


#endif