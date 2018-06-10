#include "VolumeCalc.h"

#include "mesh/Face.h"
#include "mesh/Vertex.h"

namespace
{
  double partial(Vertex const & p, Vertex const & q, Vertex const & r)
  {
    double PxQyRz = p.coords[0] * q.coords[1] * r.coords[2];
    double PyQzRx = p.coords[1] * q.coords[2] * r.coords[0];
    double PzQxRy = p.coords[2] * q.coords[0] * r.coords[1];
    double PxQzRy = p.coords[0] * q.coords[2] * r.coords[1];
    double PyQxRz = p.coords[1] * q.coords[0] * r.coords[2];
    double PzQyRx = p.coords[2] * q.coords[1] * r.coords[0];
    return PxQyRz + PyQzRx + PzQxRy - PxQzRy - PyQxRz - PzQyRx;
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
    Vertex const & q = mesh.verts[face.verts[0]];
    Vertex const & r = mesh.verts[face.verts[0]];
    volume += partial(p,q,r);
  }

  volume /= 6.0;
}