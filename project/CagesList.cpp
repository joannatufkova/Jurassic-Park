#include"CagesList.h"

const int DEFAULT_CAPACITY = 4;

bool CagesList::Resize() {
   int new_capacity = capacity * 2;
   Cage** temp = new Cage * [new_capacity];
   while (!temp) {
      new_capacity -= (new_capacity - capacity) / 2;
      temp = new Cage * [new_capacity];
      if (!temp && new_capacity == capacity + 1) return false;
   }
   capacity = new_capacity;

   for (int i = 0; i < size; i++)
      temp[i] = cages[i];
   delete[] cages;
   cages = temp;
   return true;
}
void CagesList::Free() {
   for (int i = 0; i < size; i++)
      delete cages[i];

   delete[] cages;
   cages = nullptr;
}

Cage* CagesList::get_cage(int size_of_cage) const
{
   for (int i = 0; i < size; i++) {
      if ((size_of_cage == cages[i]->is_small_cage()) || (size_of_cage == cages[i]->is_middle_cage())
         || (size_of_cage == cages[i]->is_big_cage()))
         return cages[i];
   }
   return nullptr;
}
Dinosaur* CagesList::get_dino(const char* name) const
{
   Dinosaur* result = nullptr;
   for (int i = 0; i < size; i++) {
      result = cages[i]->get_dino(name);
      if (result) {
         return result;
         break;
      }
   }
   return nullptr;
}

CagesList::CagesList(): cages(nullptr), size(0), capacity(DEFAULT_CAPACITY) 
{
   new Cage* [capacity];
}

void CagesList::add_cage(const Cage& cage) {
   if (size >= capacity) {
      if (!Resize()) cerr << "Not enough memory to add a new cage!\n";
      return;
   }
   cout << cages[size]->get_size_of_cage() << " created successfully!" << endl;
   ++size; 
}
void CagesList::add_dino(const Dinosaur* other) const {
   for (int i = 0; i < size; i++) {
      cages[i]->insert_dino(other);
      return;
   }
}
CagesList::~CagesList() {
   Free();
}

void CagesList::print(const char* filename) const {
   ofstream ofile(filename);
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   cout << "Our jurassic park has " << size << "  cage(s)." << endl;
   for (int i = 0; i < size; i++) {
      cages[i]->print(filename);
   }
   ofile.close();
}

void CagesList::print_cages() {
   for (int i = 0; i < size; i++) {
      cout << cages[i] << endl;
   }
}