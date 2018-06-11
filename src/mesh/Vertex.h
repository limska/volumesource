#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "Vector.h"

struct Vertex : public Vector
{
  Vertex(double x, double y, double z) : Vector(x,y,z) {}
};

#endif