#ifndef _FACE_H_
#define _FACE_H_

#include <vector>

struct Face
{
  Face() = delete;
  Face(std::vector<int> verts_)
    : verts(verts_)
  {}

  std::vector<int> verts;
};

#endif