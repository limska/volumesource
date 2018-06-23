#include "VolumeCalculator.h"

#include "mesh/Mesh.h"
#include "mesh/BoundingBox.h"
#include "calc/VolumeCalc.h"
#include "calc/Translate.h"
#include "formats/stl/StlAsciiParser.h"

#include "boost/filesystem.hpp"
#include "boost/timer/timer.hpp"
#include <sstream>

namespace
{
  std::string const FILENAME {"filename"};
};


void
VolumeCalculator::
calculate(std::string & response)
{
  std::map<std::string, std::string>::const_iterator it
  {
    args.find(FILENAME)
  };

  std::stringstream out;
  if (it == args.end())
  {
    out << "ERROR - Missing file name." << std::endl;
    response.append(out.str());
    return;
  }
  std::string filename = args[FILENAME];

  out << "Volume Source - Calculate volume of STL surface." << std::endl;
  out << "Calculating volume for: " << filename << std::endl;

  std::string sep {boost::filesystem::path::preferred_separator};
  std::string full_path = doc_root + sep + filename;

  boost::timer::cpu_timer timer;
  StlAsciiParser parser(full_path);
  parser.parse();

  Mesh mesh;
  parser.getMesh(mesh);
  BoundingBox bbox = parser.getBoundingBox();
  out << "Bounding Box Volume: " << bbox.volume() << "\n" << std::endl;

  out << "Number of faces = " << mesh.faces.size() << std::endl;
  out << "Number of verticies = " << mesh.verts.size() << "\n" << std::endl;
  out << "Time to calculate = " << timer.format() << std::endl;

  //Translate().calculate(mesh, )

  double volume;
  VolumeCalc().calculate(mesh,volume);
  
  out << "Volume: " << volume << std::endl;

  double const margin = 0.15;
  out << "Volume with margin: " << volume * (1 + margin) << std::endl;
  out << "\n" << std::endl;

  response.append(out.str());

 
}
