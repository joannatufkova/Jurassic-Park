#include "Dinosaur.h"

bool has_digits(const char* str, int len)
{
   for (int i = 0; i < len; i++)
   {
      if (str[i] >= '0' && str[i] <= '9')
         return true;
   }
   return false;
}

void Dinosaur::set_category(const char* category) {
   int len = strlen(category);
   if (has_digits(category, len))
   {
      this->category[0] = '\0';
      return;
   }
   this->category = new char[len + 1];
   strcpy(this->category, category);
}
void Dinosaur::set_name(const char* name)
{
   int len = strlen(name);
   if (has_digits(name, len))
   {
      this->name[0] = '\0';
      return;
   }
   this->name = new char[len + 1];
   strcpy(this->name, name);
}

void Dinosaur::Copy_From(const Dinosaur& other)
{
   char* new_name = new char[strlen(other.name) + 1];
   if (new_name) {
      name = new_name;
      strcpy(name, other.name);
   }
   else {
      cout << "Not enough memory to copy dinosaur!\n";
   }

   char* new_category = new char[strlen(other.category) + 1];
   if (new_category) {
      category = new_category;
      strcpy(category, other.category);
   }
   else {
      cout << "Not enough memory to copy category!\n";
   }
   sex = other.sex;
   //this->unique_num = other.unique_num;
}
void Dinosaur::Free() {
   delete[] name;
   name = nullptr;

   delete[] category;
   category = nullptr;
}

/*Dinosaur::Dinosaur(ifstream& in) {
   int len;
   in.read((char*)&len, sizeof(len));
   name = new char[len];
   in.read(name, len);

   int c_len;
   in.read((char*)&c_len, sizeof(c_len));
   category = new char[c_len];
   in.read(category, c_len);

   in.read((char*)&sex, sizeof(sex));
   in.read((char*)&era, sizeof(era));
   in.read((char*)&feed, sizeof(feed));
}*/
Dinosaur::Dinosaur(const char* c_name, bool c_sex, const char* c_category)
   : name(new char[strlen(c_name) + 1]),
   sex(c_sex),
   category(new char[strlen(c_category)] + 1)
{
   strcpy(name, c_name);
   strcpy(category, c_category);

   //unique_num = get_next();
}
Dinosaur::Dinosaur(const Dinosaur& other)
{
   Copy_From(other);
}
Dinosaur& Dinosaur::operator=(const Dinosaur& other)
{
   if (this != &other) {
      Free();
      Copy_From(other);
   }
   return *this;
}
Dinosaur::~Dinosaur()
{
   Free();
}

void Dinosaur::print(const char* filename)
{
   ofstream ofile(filename);
   if (!ofile) {
      cerr << "The file couldn't be opened.\n";
   }
   ofile << "Name of dinosaur: " << get_name() << endl;
   ofile << "Sex: "; if (sex == true)  cout << "Male\n";
   else ofile << "Female\n";
   ofile << "Category: " << get_category() << endl;

   ofile.close();
}


