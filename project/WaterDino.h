#ifndef WATERDINO_H
#define WATERDINO_H
#include"Dinosaur.h"

class WaterDino :public Dinosaur {
private:

public:
   Type type() const  { return Type::WATERDINO; }
   Era get_era() const  { return Era::CREDA; };
   Feed get_feed() const  { return Feed::FISH; };
   void read_from_file(ifstream& stream);

   WaterDino(const char* name, bool sex, const char* category);

   Dinosaur* clone() const { return new WaterDino(*this); };
   void print(const char* filename);
};
#endif 
