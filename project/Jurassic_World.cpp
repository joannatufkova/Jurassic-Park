#include "Jurassic_World.h"

const short MAX_LENGHT = 128;

void Jurassic_World::read_common_data(Dinosaur* c) const
{
   bool sex;
   char name[100];
   cout << "Name of Dinosaur: "; cin >> name;
   c->set_name(name);
   cout << "What sex is it?\n";
   cout<< "Enter 1 for MALE or 0 for FEMALE: "; cin >> sex;
      c->set_sex(sex);
   char category[20];
   cout << "What kind of category? "; cin >> category;
   c->set_category(category);
}
Dinosaur* Jurassic_World::create_dinasour(char type) const 
{
   switch (type) {
   case 'c': return create_carnivorous(); break;
   case 'h': return create_hebrivorous(); break;
   case 'w': return create_water_dino(); break;
   case 'f': return create_flying_dino(); break;
   default: cout << "We haven't that type in our jurassic world.\n"; break;
   }
   return NULL;
}
WaterDino* Jurassic_World::create_water_dino() const {
   WaterDino* water_dino = new WaterDino(" ", false, " ");
   read_common_data(water_dino);
   return water_dino;
}
FlyingDino* Jurassic_World::create_flying_dino() const{
   FlyingDino* flying_dino = new FlyingDino(" ", false, " ");
   read_common_data(flying_dino);
   return flying_dino;
}
Carnivorous* Jurassic_World::create_carnivorous() const{
   Carnivorous* carnivorous = new Carnivorous(" ", false, " ");
   read_common_data(carnivorous);
   return carnivorous;
}
Hebrivorous* Jurassic_World::create_hebrivorous() const{
   Hebrivorous* hebrivorous = new Hebrivorous(" ", false, " ");
   read_common_data(hebrivorous);
   return hebrivorous;
}

Jurassic_World::Jurassic_World() : feed(false) ,staff(false) {}

void Jurassic_World::new_dinosaur() const {
   cout << "****NEW DINOSAUR****\n";
   char type;
   cout << "What type of dinosaur?  Enter: ";
   cout << "c - CARNIVOROUS, " << ' ' << "h - HEBRIVOROUS," << ' ' << "w - WATERDINO," << ' ' << "f- FLYINGDINO: ";
   cin >> type;
   Dinosaur* new_dino = create_dinasour(type);
   if (new_dino) {
         list.add_dino(new_dino);
      cout << "You added dinosaur in our park successfully!\n";
   }
   cout<<endl;
}
void Jurassic_World::build_cage() {
   int option;
   cout << "What type of cage do you want to build? : ";
   cout << "1 - Small for 1 dinosaur\n";
   cout << "3 - Middle for 3 dinosaurs\n";
   cout << "10 - Big for 10 dinosaurs\n";
   cin >> option;

   if (list.cage_exists(option)) {
      cout << "Cage with " << option << " dinosaurs created successfully.\n";
   }
   else
      cout << "Cage could not be built.\n";
}
void Jurassic_World::remove_dinosaur() const {
   cout << "****REMOVE DINOSAUR****\n";
   char name[MAX_LENGHT];
   cout << "Enter name of the dinosaur: "; cin >> name;
   if (list.contains_dino(name)) {
      for (int i = 0; i < list.get_size(); i++) {
         //list.remove_dino(list.contains_dino(name));
            cout << "Dinosaur with name: " << name << " removed successfully!\n";
         return;
      }
   }
   else
      cout << "Dinosaur with name: " << name << " not found.\n";
}

bool Jurassic_World::sclad() {
   if (has_enough_staff()) {
      cout << "Our system has enough staff to sclad with food and take care of our dinosaurs.\n";
      return true;
   }
   else {
      for (int i = 0; i < list.get_size(); i++) {
         return has_not_enough_feed();
      }
   }
   return true;
}

int Jurassic_World::get_request() {
   cout << "******WELCOME TO OUR JURASSIC WORLD SYSTEM******\n";
   
   ofstream ofile("jurassic_world.txt");
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   list.print("jurassic_world.txt");
   cout << endl;
   
   cout << "1 - Add a new dinosaur. \n";
   cout << "2 - Build a new cage. \n";
   cout << "3 - Remove curret dinosaur. \n";
   cout << "4 - Feed the sclad. \n";
   cout << " 5 - Exit. \n";

   int request;
   do {
      cout << "Enter your request (1-5): ";
      cin >> request;
      cout << endl;
   if (request == 1) {
      new_dinosaur();
   }
   else if (request == 3) {
      remove_dinosaur();
   }
   else if (request == 2) {
      build_cage();
   }
   else if (request == 4) {
      sclad();
   }
   else if (request == 5) {
      cout << "Exit of the system.\n";
      break;
   }
   else {
      cout << "Try again with correct option!\n";
   }
   } while (request >= 1 && request < 5);
  
   return request;
}
ifstream& operator>>(ifstream& in, const Jurassic_World& obj) {
   char type;
   while (in >> type) {
      if (type == 'c' || type == 'h' || type == 'w' || type == 'f') {
         obj.create_dinasour(type);
      }
   }
   return in;
 }


