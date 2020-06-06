#ifndef CAGESLIST_H
#define CAGES_LIST_H
#include"Cage.h"

class CagesList {
private:
   Cage** cages;
   int size;
   int capacity;

   Dinosaur* get_dino(const char* name) const;
   Cage* get_cage(int size_of_cage) const;

   bool Resize();
   void Free();
public:
   CagesList();

   int get_size() const { return size; };
   int get_capacity() const { return capacity; };

   void add_cage(const Cage& cage);
   void remove_cage() { size--; };
   bool cage_exists(int size_of_cage) const { return get_cage(size_of_cage); };

   bool contains_dino(const char* name) const { return get_dino(name); };
   void add_dino(const Dinosaur* other) const;
   //bool remove_dino(int index) const;

   ~CagesList();

   void print_cages();
  
   void print(const char* filename ) const;
};

#endif // !CAGESLIST_H
