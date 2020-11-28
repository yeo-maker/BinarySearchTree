#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
/*
template <class D>
class DATA
{
public:
  DATA(){}
  DATA(D ind,D val)
    : index (ind), value(val) {};
  void set_value(D val);
  void set_index(int ind);
  D get_value();
  D get_index();
private:
  D value;
  int index;
};

template<class D>
void DATA<D>::set_value(D val)
{value = val;}

template<class D>
void DATA<D>::set_index(int ind)
{index = ind;}

template<class D>
typename DATA<D>::get_index()
{return index;}

template<class D>
typename DATA<D>::get_value()
{return value;}
*/
int main(int argc, char* argv[])
{
  
  BinaryTree<int> A;
  BinaryTree<int> B;
  int testarray[10] = {1,2,4,4,5,6,7,8,9,10};
  int random;
  for (int i=0 ; i<10 ; i++)
    {
      random = rand()%10;
      A.insert(testarray[random]);
    };
    A.inorder_treewalk();
    A.test_max();
    A.test_min();
    A.tree_search(2);
    A.test_successor(6);
    A.test_predecessor(3);
    B.inorder_treewalk();
    B.test_max();
    B.test_min();
    B.tree_search(2);
    B.test_successor(3);
    B.test_predecessor(4);
  
  /*
  BinaryTree<DATA<int>> A;
  BinaryTree<DATA<int>> B;
  int testarray[10] = {1,2,4,4,5,6,7,8,9,10};
  int random;
  std::vector<DATA<int>> C(10);
  DATA<int>data[10];
  for (int i=0 ; i<10 ; i++)
    {
      random = rand()%10;
      data[i].set_value(testarray[random]);;
      data[i].set_index(i);
      C.push_back(data[i]);
      A.insert(C[i]);
    };
  
    A.inorder_treewalk();
    A.test_max();
    A.test_min();
    A.tree_search(2);
    A.test_successor(6);
    A.test_predecessor(3);
    B.inorder_treewalk();
    B.test_max();
    B.test_min();
    B.tree_search(2);
    B.test_successor(3);
    B.test_predecessor(4);
  */
    return 0;
};
