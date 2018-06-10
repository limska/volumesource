#include "VolumeCalc.h"

#include "mesh/Face.h"
#include "mesh/Vertex.h"

#include <iostream>
#include <cmath>

namespace
{
  double partial(Vertex const & p, Vertex const & q, Vertex const & r)
  {
    double PxQyRz = p.coords[0] * q.coords[1] * r.coords[2];
    // std::cout << "PxQyRz = " << PxQyRz << std::endl;
    double PyQzRx = p.coords[1] * q.coords[2] * r.coords[0];
    // std::cout << "PyQzRx = " << PyQzRx << std::endl;
    double PzQxRy = p.coords[2] * q.coords[0] * r.coords[1];
    // std::cout << "PzQxRy = " << PzQxRy << std::endl;
    double PxQzRy = p.coords[0] * q.coords[2] * r.coords[1];
    // std::cout << "PxQzRy = " << PxQzRy << std::endl;
    double PyQxRz = p.coords[1] * q.coords[0] * r.coords[2];
    // std::cout << "PyQxRz = " << PyQxRz << std::endl;
    double PzQyRx = p.coords[2] * q.coords[1] * r.coords[0];
    // std::cout << "PzQyRx = " << PzQyRx << std::endl;
    return PxQyRz - PxQzRy + PzQxRy - PyQxRz + PyQzRx - PzQyRx;
  }
}


void
VolumeCalc::
calculate(Mesh const & mesh, double & volume) const
{
  volume = 0.0;

  for (Face const & face : mesh.faces)
  {
    Vertex const & p = mesh.verts[face.verts[0]];
    Vertex const & q = mesh.verts[face.verts[1]];
    Vertex const & r = mesh.verts[face.verts[2]];
    volume += partial(p,q,r);
  }

  volume = std::fabs(volume) / 6.0;
}