#include <iostream>
#include <cstdlib>


template <class T>
class BinaryTree
{
private:
    class Node
    {
    public:
	T data;
	Node* lc;
	Node* rc;
	Node* parent;
	Node(T _data);
    };
    Node* root;
    void inorder_treewalk(Node* _x) const;
    void release(Node* _x);
    Node* successor(Node* _x) const;
    Node* predecessor(Node* _x) const;
    Node* min(Node* _x) const;
    Node* max(Node* _x) const;
public:
    BinaryTree() {root = NULL;};
    BinaryTree(T _data);
    ~BinaryTree();
    void insert(T _data);
    void inorder_treewalk() const;
    void test_successor(T _data);
    void test_max();
    void test_min();
    void test_predecessor(T _data);
    void tree_search(T _data) const;
    Node* tree_searchnode(T _data) ;
};

template<class T>
void BinaryTree<T>::release(Node* _x)
{
    if (_x != NULL)
    {
	release(_x->lc);
	release(_x->rc);
	delete _x;
    }	
};

template<class T>
BinaryTree<T>::~BinaryTree()
{
    release(root);
};

template<class T>
BinaryTree<T>::Node::Node(T _data)
{
    data = _data;
    parent = lc = rc = NULL;
};

template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::successor(Node* _x) const
{
    Node* x = _x;
    if (x->rc != NULL)
	return min(x->rc);
    Node* y = x->parent;
    while (y != NULL && x == y->rc)
    {
	x = y;
	y = y->parent;
    }
    return y;
};

template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::predecessor(Node* _x) const
{
    Node* x = _x;
    if (x->lc != NULL)
	return max(x->lc);
    Node* y = x->parent;
    while (y != NULL && x == y->lc)
    {
	x = y;
	y = y->parent;
    }
    return y;
};

template<class T>
void BinaryTree<T>::test_successor(T _data)
{
  Node* x = tree_searchnode(_data);
  if (x == NULL)
    {
      std::cerr << _data << " was not found in this tree!" << std::endl;
    }
  else
    {
  std::cout << "successor: " << successor(x)->data << std::endl;
    };
};

template<class T>
void BinaryTree<T>::test_predecessor(T _data)
{
  Node* x = tree_searchnode(_data) ;
  if (x == NULL)
    {
      std::cerr << _data << " was not found in this tree!" << std::endl;
    }
  else
    {
      std::cout << "predecessor: " << predecessor(x)->data << std::endl;
    };
};

template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::min(Node* _x) const
{
    while (_x->lc != NULL)
	_x = _x->lc;
    return _x;
};

template<class T>
void BinaryTree<T>::test_min()
{ if (root != NULL)
    {
  std::cout << "min_value: " << min(root)->data << std::endl;
    }
 else
      {std::cerr << "IT IS AN EMPTY TREE!" << std::endl;}
};

template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::max(Node* _x) const
{
    while (_x->rc != NULL)
	_x = _x->rc;
    return _x;
};

template<class T>
void BinaryTree<T>::test_max()
{ if (root != NULL)
    {
  std::cout << "max_value: " << max(root)->data << std::endl;
    }
 else
      {std::cerr << "IT IS AN EMPTY TREE!" << std::endl;}
};

template<class T>
void BinaryTree<T>::inorder_treewalk() const
{
  if(root == NULL)
    {std::cerr << "IT IS AN EMPTY TREE!" << std::endl;}
else
  {inorder_treewalk(root);
    std::cout << std::endl;}
};

template<class T>
void BinaryTree<T>::inorder_treewalk(Node* _x) const
{
    if (_x != NULL)
    {
	inorder_treewalk(_x->lc);
	std::cout << _x->data << "\t";
	inorder_treewalk(_x->rc);
    }
    
};

template<class T>
void BinaryTree<T>::tree_search(T _data) const
{
  const Node* x = root;
  if(x == NULL)
    {std::cerr << "IT IS AN EMPTY TREE!" << std::endl;}
  else
    {
  while (x->data != _data)
    {
      if (_data < x->data)
	{
	  x = x->lc;
	}
      else
	{
	  x = x->rc;
	};
      if( x == NULL)
	{std::cout << "IT WAS NOT FOUND IN THIS TREE!" << std::endl;
	  break;
	};

    };
  if (x != NULL)
    {
      std::cout << "node_address:" << x << std::endl;
    }
    }
};


template<class T>
void BinaryTree<T>::insert(T _data)
{
    Node* y = NULL;
    Node* x = root;
    Node* p = new Node(_data);
    while (x != NULL)
    {
	y = x;
	if (p->data < x->data)
	    x = x->lc;
	else
	    x = x->rc;
    }
    p->parent = y;
    if (y == NULL)
	root = p;
    else if (p->data < y->data)
	y->lc = p;
    else
	y->rc = p;
};

template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::tree_searchnode(T _data) 
{
  Node* x = root;
  if(x != NULL)
    {
  while (x->data != _data)
    {
      if (_data < x->data)
	{
	  x = x->lc;
	}
      else
	{
	  x = x->rc;
	};
      if( x == NULL)
	{
	  break;
	};

    };
  return x;
    }
  else
    return x;
};

template<class T>
BinaryTree<T>::BinaryTree(T _data)
{
    Node* p = new Node(_data);
    if (root == NULL)
	root = p;
};

