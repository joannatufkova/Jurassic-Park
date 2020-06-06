#ifndef CAGE_H
#define CAGE_H
#include"Dinosaur.h"

class Cage {
private:
   Dinosaur** dinosaurs;
   int size;
   int capacity;

   Climat climat;
   int size_of_cage;
   
   bool Resize();
   bool Copy_From(const Cage& other);
   void Free();
public:
   Cage(Climat new_climat, int new_size_of_cage);
   Cage(const Cage& other);
   Cage& operator=(const Cage& other);
   ~Cage();

   bool is_small_cage() { return size_of_cage == 1; };
   bool is_middle_cage() { return size_of_cage == 3; };
   bool is_big_cage() { return size_of_cage == 10; };
   int get_size_of_cage() const { return size_of_cage; };
   
   int get_size() const { return size; };
   int get_capacity() const { return capacity; };

   bool can_live_together(const Dinosaur& dino); 
   Climat get_climat() const { return Climat::Invalid_Climat; };

   bool insert_dino(const Dinosaur* other);
   bool remove_dino(int index);
    
   Dinosaur* get_dino(const char* name) const;
   bool contain_dino(const char* name) const { return get_dino(name); };

   virtual Cage* clone() const { return new Cage(*this); };
   void print(const char* filename) const;
};
#endif // !CAGE_H
