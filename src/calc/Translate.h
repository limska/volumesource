#ifndef _TRANSLATE_H_
#define _TRANSLATE_H_

#include "mesh/Vector.h"
#include "mesh/Mesh.h"


class Translate
{
public:
  void calculate(Mesh & mesh, Vector const & vector) const;
};

#endif