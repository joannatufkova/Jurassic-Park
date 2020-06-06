#ifndef FLYINGDINO_H
#define FLYINGDINO_H
#include"Dinosaur.h"

class FlyingDino :public Dinosaur {
private:

public:
   FlyingDino(const char* name, bool sex, const char* category);

   Type type() const { return Type::FLYINGDINO; };
   Era get_era() const { return Era::TRIAS; };
   Feed get_feed() const { return Feed::MEAT; };
   void read_from_file(ifstream& stream);


   Dinosaur* clone() const { return new FlyingDino(*this); };
   void print(const char* filename);
};
#endif 