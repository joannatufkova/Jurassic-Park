#ifndef JURASSIC_WORLD_H
#define JURASSIC_WORLD_H
#include"Cage.h"
#include"CagesList.h"
#include"Dinosaur.h"
#include"Carnivorous.h"
#include"Hebrivorous.h"
#include"WaterDino.h"
#include"FlyingDino.h"

class Jurassic_World {
private:
   CagesList list;
   
   int feed=0;
   bool staff;

   void read_common_data(Dinosaur* c) const;
   WaterDino* create_water_dino() const;
   FlyingDino* create_flying_dino() const;
   Hebrivorous* create_hebrivorous() const;
   Carnivorous* create_carnivorous() const;

public:
   Jurassic_World();

   Dinosaur* create_dinasour(char type) const;
   int has_not_enough_feed() { return feed++; };
   bool has_enough_staff() { return staff; };

   void new_dinosaur() const;
   void build_cage();
   void remove_dinosaur() const;  
   bool sclad();

   friend ifstream& operator>>(ifstream& in, Jurassic_World& obj);
   int get_request();
};
#endif // !JURASSIC_PARK_H
