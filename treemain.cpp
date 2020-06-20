#include <iostream>
#include "inttree.h"

using namespace std;

int main()
{  
   BinarySearchTree t;
   t.insert(10); t.insert(0); t.insert(0); 
   t.insert(19); t.insert(-10); t.insert(-5);
   t.insert(14); t.insert(0); t.insert(30);
   t.insert(2); t.insert(19); t.insert(30);
   t.print();
   t.erase(30); t.erase(-10); t.erase(0); t.erase(10);
   t.print();
   cout << "The count of 30 is " << t.count(30) << ".\n";
   cout << "The count of 0 is " << t.count(0) << ".\n";
   cout << "The smallest integer is " << t.smallest() << ".\n";
   return 0;
}
