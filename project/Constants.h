#ifndef CONSTANTS_H
#define CONSTANTS_H 

enum class Type {
   CARNIVOROUS = 0,
   HEBRIVOROUS,
   WATERDINO,
   FLYINGDINO,
   Invalid_Type = -1
};

enum class Era {
   TRIAS = 0,
   CREDA,
   UDA,
   Invalid_Era = -1
};

enum class Feed {
   GRASS = 0,
   MEAT,
   FISH,
   Invalid_Feed = -1
};

enum class Climat {
   LAND = 0,
   AIR,
   WATER,
   Invalid_Climat = -1
};

#endif // !CONSTANTS_H