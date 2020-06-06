#include"WaterDino.h"

WaterDino::WaterDino(const char* name, bool sex, const char* category)
   : Dinosaur(name, sex, category) { }

void WaterDino::read_from_file(ifstream& stream) { }

void WaterDino::print(const char* filename)
{
   ofstream ofile(filename);
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   cout << "Water Dinosaur: " << endl;
   Dinosaur::print(filename);

   ofile.close();
}