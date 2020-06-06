#include"FlyingDino.h"

FlyingDino::FlyingDino(const char* name, bool sex, const char* category)
   : Dinosaur(name, sex, category) {}


void FlyingDino::print(const char* filename)
{
   ofstream ofile(filename);
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   ofile << "Flying Dinosaur: " << endl;
   Dinosaur::print("jurassic_world.txt");

   ofile.close();
}