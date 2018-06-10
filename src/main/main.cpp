#include <iostream>

#include "Options.h"
#include "mesh/Mesh.h"
#include "mesh/BoundingBox.h"
#include "calc/VolumeCalc.h"
#include "formats/stl/StlAsciiParser.h"

int
main(int argc, char** argv)
{
  Options opts(argc,argv);

	std::cout << "Volume Source - Calculate volume of STL surface." << std::endl;
  std::cout << "Calculating volume for: " << opts.getFileName() << std::endl;

  StlAsciiParser parser(opts.getFileName());
  parser.parse();

  Mesh mesh;
  parser.getMesh(mesh);
  BoundingBox bbox = parser.getBoundingBox();
  std::cout << "Bounding Box Volume: " << bbox.volume() << std::endl;

  double volume;
  VolumeCalc().calculate(mesh,volume);
  
  std::cout << "Volume: " << volume << std::endl;
  std::cout << "\n" << std::endl;
	return 0;
}
