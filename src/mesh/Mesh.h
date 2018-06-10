#ifndef _MESH_H_
#define _MESH_H_

#include <vector>

#include "Edge.h"
#include "Face.h"
#include "Vertex.h"

struct Mesh
{
  std::vector<Vertex> verts;
  std::vector<Face> faces;
  std::vector<Edge> edges;
};

#endif