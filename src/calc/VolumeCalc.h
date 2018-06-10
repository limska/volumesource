#ifndef _VOLUME_CALC_H_
#define _VOLUME_CALC_H_

#include "mesh/Mesh.h"

class VolumeCalc
{
public:
  void calculate(Mesh const & mesh, double & volume) const;
};


#endif