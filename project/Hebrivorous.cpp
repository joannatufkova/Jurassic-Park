#include"Hebrivorous.h"

Hebrivorous::Hebrivorous(const char* name, bool sex, const char* category)
   : Dinosaur(name, sex, category) { }

void Hebrivorous::print(const char* filename)
{
   ofstream ofile(filename);
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   ofile << "Hebrivorous: " << endl;
   Dinosaur::print("jurassic_world.txt");
   
   ofile.close();
}