#ifndef _FACE_H_
#define _FACE_H_

#include <vector>

struct Face
{
  Face() = delete;
  Face(std::vector<unsigned int> const & verts_)
    : verts(verts_)
  {}

  std::vector<unsigned int> verts;
};

#endif