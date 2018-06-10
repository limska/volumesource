#include "StlAsciiParser.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>



namespace
{
  std::string const  SOLID {"solid"};
  unsigned int const SOLID_POS {0};
  unsigned int const SOLID_SIZE {1};
  
  std::string const  FACET {"facet"};
  unsigned int const FACET_POS {0};
  std::string const  NORMAL {"normal"};
  unsigned int const NORMAL_POS {1};
  unsigned int const FACET_NORMAL_SIZE {5};
  
  std::string const  OUTER {"outer"};
  unsigned int const OUTER_POS {0};
  std::string const  LOOP {"loop"};
  unsigned int const LOOP_POS {1};
  unsigned int const OUTER_LOOP_SIZE {2};
  
  std::string const  VERTEX {"vertex"};
  unsigned int const VERTEX_POS {0};
  unsigned int const VERTEX_SIZE {4};
  
  std::string const  ENDLOOP {"endloop"};
  unsigned int const ENDLOOP_SIZE {1};
  unsigned int const ENDLOOP_POS {0};
  
  std::string const  ENDFACET {"endfacet"};
  unsigned int const ENDFACET_SIZE {1};
  unsigned int const ENDFACET_POS {0};

  std::string const  ENDSOLID {"endsolid"};
  unsigned int const ENDSOLID_SIZE {1};
  unsigned int const ENDSOLID_POS {0};

  void parseLine(std::string const & line, std::vector<std::string> & words)
  {
    std::string const del {" "};
    std::string trimmed {line};
    trimmed.erase(0, line.find_first_not_of(del));

    words.clear();
    std::string::size_type cur_loc = 0;
    std::string::size_type del_loc = trimmed.find_first_of(del, cur_loc);
    if (del_loc > trimmed.size())
    {
      words.push_back(trimmed);
      return;
    }
  
    while (del_loc <= trimmed.size())
    {
      words.push_back(trimmed.substr(cur_loc,del_loc - cur_loc));
      cur_loc = del_loc + 1;
      del_loc = trimmed.find_first_of(del, cur_loc);
    }
  
    words.push_back(trimmed.substr(cur_loc));
  }

  void print(std::vector<std::string> const & words)
  {
    for (auto const word : words)
    {
      std::cout << word << " ";
    }
    std::cout << std::endl;
  }

}


StlAsciiParser::
StlAsciiParser(std::string const & fileName) 
  : solid(*this)
  , facet_normal(*this)
  , outer_loop(*this)
  , vertex(*this)
  , endloop(*this)
  , endfacet(*this)
  , endsolid(*this)
  , fileName_(fileName)
  , min_({std::numeric_limits<double>::max(),std::numeric_limits<double>::max(),std::numeric_limits<double>::max()})
  , max_({std::numeric_limits<double>::min(),std::numeric_limits<double>::min(),std::numeric_limits<double>::min()})
  , curr_state(nullptr) 
{}


void
StlAsciiParser::
parse()
{
  std::cout << "Parsing " << fileName_ << "." << std::endl;


  std::ifstream stream;
  stream.open(fileName_.c_str(), std::ios::in );
  if (!stream.is_open())
  {
    std::cout << "Error while openning " << fileName_ << "." << std::endl;
    throw;
  }

  try
  {
    readFile(stream);
  }
  catch(...)
  {
    std::cout << "Error while parsing " << fileName_ << ": " << std::endl;
    stream.close();
    throw;
  }

  stream.close();
}


void
StlAsciiParser::
getMesh(Mesh & mesh) const
{
  
}


void
StlAsciiParser::
readFile(std::ifstream & stream)
{
  curr_state = &solid;

  while (stream.good() && curr_state != &endsolid)
  {
    std::string line;
    std::getline(stream, line);

    std::vector<std::string> words;
    parseLine(line,words);

    //std::cout << "State " << curr_state->name() << ", size " << words.size() << std::endl;
    curr_state->handle(words);
    //std::cout << "New state " << curr_state->name() << std::endl;
  }
}


BoundingBox
StlAsciiParser:: 
getBoundingBox() const
{
  return BoundingBox(min_,max_);
}


void
StlAsciiParser:: 
updateMinMax(std::vector<double> point)
{
  for (unsigned int i=0; i<3; ++i)
  {
    double const value = point[i];
    if (value < min_[i])
    {
      min_[i] = value;
    }
    if (value > max_[i])
    {
      max_[i] = value;
    }
  }  
}

void
StlAsciiParser:: 
State::
checkSize(std::vector<std::string> const & words, 
          unsigned int const size) const
{
  if (words.size() < size)
  {
    std::cout << "Invalid STL file " << host.fileName_ << ": "
              << " arguments missing in" << name() << std::endl;
    print(words);
    std::cout << "  Expecting " << size << " found " << words.size() << std::endl;
    throw;
  }
}

void
StlAsciiParser:: 
State::
checkKeyWord(std::vector<std::string> const & words, 
             std::string const & expected,
             unsigned int const pos) const
{
  if (words[pos].compare(expected) != 0)
  {
    print(words);
    std::cout << "Invalid STL file " << host.fileName_ 
              << " while reading " << name()
              << " at possition " << pos
              << ": " 
              << " expecting " << expected << " found " << words[pos]
              << std::endl;
    print(words);
    throw;
  }
}

void
StlAsciiParser:: 
Solid::
handle(std::vector<std::string> const & words)
{
  checkSize(words,SOLID_SIZE);
  checkKeyWord(words,SOLID,SOLID_POS);

  std::vector<std::string>::const_iterator it = words.begin();
  ++it;
  for (;it < words.end(); ++it)
  {
    host.name_ += *it;
  }

  std::cout << "name: " << host.name_ << std::endl;

  host.curr_state = &host.facet_normal;
}

void
StlAsciiParser:: 
FacetNormal::
handle(std::vector<std::string> const & words)
{
  if (words[0].compare(ENDSOLID) == 0)
  {
    host.curr_state = &host.endsolid;
    return;
  }

  checkSize(words,FACET_NORMAL_SIZE);
  checkKeyWord(words,FACET,FACET_POS);
  checkKeyWord(words,NORMAL,NORMAL_POS);

  host.curr_state = &host.outer_loop;
}

void
StlAsciiParser:: 
OuterLoop::
handle(std::vector<std::string> const & words)
{
  checkSize(words,OUTER_LOOP_SIZE);
  checkKeyWord(words,OUTER,OUTER_POS);
  checkKeyWord(words,LOOP,LOOP_POS);

  host.curr_state = &host.vertex;
}

void
StlAsciiParser:: 
Vertex::
handle(std::vector<std::string> const & words)
{
  checkSize(words,VERTEX_SIZE);
  checkKeyWord(words,VERTEX,VERTEX_POS);

  ++count;
  if (count == 3)
  {
    count = 0;
    host.curr_state = &host.endloop;
  }
}

void
StlAsciiParser:: 
EndLoop::
handle(std::vector<std::string> const & words)
{
  checkSize(words,ENDLOOP_SIZE);
  checkKeyWord(words,ENDLOOP,ENDLOOP_POS);

  host.curr_state = &host.endfacet;
}

void
StlAsciiParser:: 
EndFacet::
handle(std::vector<std::string> const & words)
{
  checkSize(words,ENDFACET_SIZE);
  checkKeyWord(words,ENDFACET,ENDFACET_POS);

  host.curr_state = &host.facet_normal;
}

void
StlAsciiParser:: 
EndSolid::
handle(std::vector<std::string> const & words)
{
  checkSize(words,ENDSOLID_SIZE);
  checkKeyWord(words,ENDSOLID,ENDSOLID_POS);
}

