#include "VolumeCalculator.h"

#include "mesh/Mesh.h"
#include "mesh/BoundingBox.h"
#include "calc/VolumeCalc.h"
#include "calc/Translate.h"
#include "formats/stl/StlAsciiParser.h"

#include "boost/filesystem.hpp"
#include <sstream>

void
VolumeCalculator::
calculate(std::string & response)
{
  std::string filename = args["filename"];

  std::stringstream out;
  out << "Volume Source - Calculate volume of STL surface." << std::endl;
  out << "Calculating volume for: " << filename << std::endl;

  std::string sep {boost::filesystem::path::preferred_separator};
  std::string full_path = doc_root + sep + filename;

  StlAsciiParser parser(full_path);
  parser.parse();

  Mesh mesh;
  parser.getMesh(mesh);
  BoundingBox bbox = parser.getBoundingBox();
  out << "Bounding Box Volume: " << bbox.volume() << std::endl;

  //Translate().calculate(mesh, )

  double volume;
  VolumeCalc().calculate(mesh,volume);
  
  out << "Volume: " << volume << std::endl;

  double const margin = 0.15;
  out << "Volume with margin: " << volume * (1 + margin) << std::endl;
  out << "\n" << std::endl;

  response.append(out.str());

 
}
