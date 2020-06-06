#ifndef DINOSAUR_H
#define DINOSAUR_H
#define _CRT_SECURE_NO_WARNINGS
#include"Constants.h"
#include<cstring>
#include<fstream>
#include<iostream>
using namespace std;

class Dinosaur {
private:
   char* name;
   char* category;
   bool sex;

   void Copy_From(const Dinosaur& other);
   void Free();

public:
   Dinosaur(const char* c_name = "<Unnamed>", bool c_sex = false, const char* c_category = "<Unnamed>");
   Dinosaur(const Dinosaur& other);
   Dinosaur& operator=(const Dinosaur& other);
   virtual ~Dinosaur();
   
   void set_sex(bool) { if (sex == 0 || sex == 1) return; };
   bool get_sex() const { return sex; };

   const char* get_name() const { return name; };
   void set_name(const char*);

   const char* get_category() const { return category; };
   void set_category(const char*);

   virtual Era  get_era() const = 0;
   virtual Feed get_feed() const = 0;
   virtual Type type() const = 0;

   virtual Dinosaur* clone() const = 0;

   virtual void print(const char* filename);
    //virtual void read_from_file(ifstream& stream)=0; 
};
#endif 