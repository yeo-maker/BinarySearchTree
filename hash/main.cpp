#include <iostream>
#include <cstdlib>
#include <string>


class Hashtable
{
private:
    class Hashnode
    {
    public:
      char data;
        int key;
	Hashnode* next;
      Hashnode(char _data,int _key);
      Hashnode();
    };
    void release(Hashnode* _x);
  int length;
  Hashnode *table;
public:
    Hashtable();
    Hashtable(int _length);
  void insert(char _data);
  int Hashfunction(char _data);
  void get_length();
  void get_table_key();
};

void Hashtable::release(Hashnode* _x)
{
    if (_x != NULL)
    {
	release(_x->next);
	delete _x;
    }	
};


Hashtable::Hashtable()
{
  length = 0;
  table = NULL;
};

Hashtable::Hashtable(int _length)
{
 if (_length < 0)
    {
	std::cerr << "The length of an array has to be a non-negtive integer."
		  << std::endl;
	std::exit(-1);
    };
    table = new Hashnode[_length];
    length = _length;
};

Hashtable::Hashnode::Hashnode(char _data,int _key)
{
    data = _data;
    next = NULL;
    key = _key;
    
};

Hashtable::Hashnode::Hashnode()
{
    key = 0;
    
};

int Hashtable::Hashfunction(char _data)
{
   assert(_data != NULL);
     unsigned int index = 0; 
     for (; *_data != '\0'; _data++)
         index = MULT * index + *pWord;
     return index % HASHNUMBER;
};

void Hashtable::insert(char _data)
{
    int key = Hashfunction(_data);
    Hashnode* y = NULL;
    if (key > length)
      {
	std::cout << "Cannot Insert" << std::endl;
      }
    else
      {
    if (table[key].key == 0)
    {
	table[key].data = _data;
    }
    else
      {
	Hashnode p = Hashtable::Hashnode(_data,key);
	while (table[key].next != y)
	  {
	    y = y->next;
	  };
	y->next = &p;
      }};	

};

void Hashtable::get_length()
{
    std::cout << length <<std::endl;
};

void Hashtable::get_table_key()
{
  for(int i = 0;i < length;i++){
    std::cout << table[i].key;}
};


int main()
{
  char str;
  
  Hashtable A(200);
  A.get_table_key();
  A.get_length();
  std::cout << A.Hashfunction('ab');
  A.insert(str);

  
};
