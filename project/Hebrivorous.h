#ifndef HEBRIVOROUS_H
#define HEBRIVOROUS_H
#include"Dinosaur.h"

class Hebrivorous :public Dinosaur {
private:

public:
   Hebrivorous(const char* name, bool sex, const char* category);

   Type type() const { return Type::HEBRIVOROUS; };
   Era get_era() const { return Era::UDA; };
   Feed get_feed() const { return Feed::GRASS; }
   void read_from_file(ifstream& stream);

   Dinosaur* clone() const { return new Hebrivorous(*this); };
   void print(const char* filename);
};
#endif // !HEBRIVOROUS_H