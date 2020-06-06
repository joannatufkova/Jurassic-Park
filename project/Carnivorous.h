#ifndef CARNIVOROUS_H
#define CARNIVOROUS_H
#include"Dinosaur.h"

class Carnivorous : public Dinosaur {
private:

public:
   Carnivorous(const char* name, bool sex, const char* category);

   Type type() const { return Type::CARNIVOROUS; };
   Era get_era() const { return Era::TRIAS; };
   Feed get_feed() const { return Feed::MEAT; }
   void read_from_file(ifstream& stream);

   Dinosaur* clone() const { return new Carnivorous(*this); };
    void print(const char* filename);
};
#endif // !CARNIVOROUS_H