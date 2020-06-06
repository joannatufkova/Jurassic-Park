#include "Carnivorous.h"

Carnivorous::Carnivorous(const char* name, bool sex, const char* category)
   : Dinosaur(name, sex, category) {};

void Carnivorous::print(const char* filename)
{
   ofstream ofile("jurassic_world.txt");
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   ofile << "Carnivorous " << endl;
   Dinosaur::print("jurassic_world.txt");

   ofile.close();
}

