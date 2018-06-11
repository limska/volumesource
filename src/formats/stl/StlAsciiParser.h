#ifndef _STL_ASCII_PARSER_H_
#define _STL_ASCII_PARSER_H_

#include <string>
#include <fstream>
#include <set>
#include <deque>
#include <cstddef>

#include "mesh/Mesh.h"
#include "mesh/Vertex.h"
#include "mesh/BoundingBox.h"

class StlAsciiParser
{
public:
  StlAsciiParser(std::string const & fileName);

  void parse();

  BoundingBox getBoundingBox() const;
  void getMesh(Mesh & mesh) const;


private:

  void readFile(std::ifstream & stream);

  void updateMinMax(std::vector<double> point);

  struct State
  {
    State(StlAsciiParser & host_) : host(host_) {}
    virtual std::string name() const = 0;
    virtual void handle(std::vector<std::string> const & words) = 0;

    void checkSize(std::vector<std::string> const & words,
                   unsigned int const size) const;
    void checkKeyWord(std::vector<std::string> const & words,
                      std::string const & expected, 
                      unsigned int const pos) const;
    StlAsciiParser & host;
  };

  struct Solid : public State
  {
    Solid(StlAsciiParser & host_) : State(host_) {}
    std::string name() const { return "solid"; };
    void handle(std::vector<std::string> const & words) override;
  } solid;

  struct FacetNormal : public State
  {
    FacetNormal(StlAsciiParser & host_) : State(host_) {}
    std::string name() const { return "facet normal"; };
    void handle(std::vector<std::string> const & words) override;
    double nx;
    double ny;
    double nz;
  } facet_normal;

  struct OuterLoop : public State
  {
    OuterLoop(StlAsciiParser & host_) : State(host_) {}
    std::string name() const { return "outer loop"; };
    void handle(std::vector<std::string> const & words) override;
  } outer_loop;

  struct ReadVertex : public State
  {
    ReadVertex(StlAsciiParser & host_);
    std::string name() const { return "vertex"; };
    void handle(std::vector<std::string> const & words) override;
    std::vector<std::size_t> vertexIds;
  private:
    int count;
  } vertex;

  struct EndLoop : public State
  {
    EndLoop(StlAsciiParser & host_) : State(host_) {}
    std::string name() const { return "endloop"; };
    void handle(std::vector<std::string> const & words) override;
  } endloop;

  struct EndFacet : public State
  {
    EndFacet(StlAsciiParser & host_) : State(host_) {}
    std::string name() const { return "endfacet"; };
    void handle(std::vector<std::string> const & words) override;
  } endfacet;

  struct EndSolid : public State
  {
    EndSolid(StlAsciiParser & host_) : State(host_) {}
    std::string name() const { return "endsolid"; };
    void handle(std::vector<std::string> const & words) override;
  } endsolid;

  std::string fileName_;
  std::string name_;

  std::vector<double> min_;
  std::vector<double> max_;

  State * curr_state;

  std::size_t insertVertex(Vertex const & v);
  std::deque<Vertex> vertices;

  std::size_t insertFace(Face const & f);
  std::deque<Face> faces;
};


#endif // _STL_ASCII_PARSER_H_
