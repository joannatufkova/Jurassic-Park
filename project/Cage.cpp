#include"Cage.h"

const unsigned DEFAULT_CAPACITY = 8;

bool Cage::Resize() {
   int new_capacity = capacity * 2;
   Dinosaur** temp = new Dinosaur * [new_capacity];
   while (!temp) {
      new_capacity -= (new_capacity - capacity) / 2;
      temp = new Dinosaur * [new_capacity];
      if (!temp && new_capacity == capacity + 1)
         return false;
   }
   capacity = new_capacity;
   for (int i = 0; i < size; i++)
      temp[i] = dinosaurs[i];
   delete[] dinosaurs;
   dinosaurs = temp;
   return true;
}

bool Cage::Copy_From(const Cage& other) {
   climat = other.climat;
   size_of_cage = other.size_of_cage;

   size = other.size;
   capacity = other.capacity;
   dinosaurs = new Dinosaur * [capacity];

   if (!dinosaurs) return false;
   for (int i = 0; i < size; i++)
      dinosaurs[i] = other.dinosaurs[i];
   return true;
}
void Cage::Free() {
   for (int i = 0; i < size; i++)
      delete dinosaurs[i];
   delete[] dinosaurs;
   dinosaurs = nullptr;
}

Cage::Cage(Climat new_climat, int new_size_of_cage)
   : climat(Climat::Invalid_Climat), size_of_cage(new_size_of_cage),capacity(DEFAULT_CAPACITY), size(0)
{
   if (size_of_cage <= 0) cout << "Invalid\n";
   dinosaurs = new Dinosaur * [capacity];
}
Cage::Cage(const Cage& other) {
   Copy_From(other);
}
Cage& Cage::operator=(const Cage& other) {
   if (this != &other) {
      Free();
      Copy_From(other);
   }
   return *this;
}
Cage::~Cage() {
   Free();
}

bool Cage::can_live_together(const Dinosaur& dino)
{
   if (dino.type() == Type::FLYINGDINO || dino.type() == Type::CARNIVOROUS || dino.type() == Type::HEBRIVOROUS) {
      if (dino.get_era() == Era::TRIAS || dino.get_era() == Era::CREDA || dino.get_era() == Era::UDA)
         cout << "Dinosaurs could live in common cage.\n";
         return true;
   }
   return false;
}

bool Cage::insert_dino(const Dinosaur* other) {
   if (size >= capacity) {
      if (!Resize()) cerr << "Not enough memory to add a new dinosaur.\n";
      return false;
   }
   dinosaurs[size] = other->clone();
   ++size;
   return true;
}
bool Cage::remove_dino(int index)
{
   delete dinosaurs[index];
   dinosaurs[index] = dinosaurs[size - 1];
   --size;
   return true;
}

Dinosaur* Cage::get_dino(const char* name) const {
   for (int i = 0; i < size; i++) {
      if (strcmp(dinosaurs[i]->get_name(), name))
         return dinosaurs[i];
   }
   return nullptr;
}
void Cage:: print(const char* filename) const
{
   ofstream ofile(filename);
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   ofile << "Our jurassic park has " << size << " dinosaur(s):"<<endl;
   for (int i = 0; i < size; i++) {
      dinosaurs[i]->print(filename);
   }
   ofile << endl;
   ofile.close();
}


