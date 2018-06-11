#ifndef _FACE_H_
#define _FACE_H_

#include <vector>
#include <cstddef>

struct Face
{
  Face() = delete;
  Face(std::vector<std::size_t> const & verts_)
    : verts(verts_)
  {}

  std::vector<std::size_t> verts;
};

#endif