#include <iostream>

using namespace std;

class node
{
private:
  int rollno;
  char name[25];

public:
  void getItems();
  void displayItems();
};

void node::displayItems()
{
  cout<<name<<rollno;
}

void node::getItems()
{
  cin>>name>>rollno;
}

int main()
{
  node a;
  a.getItems();
  a.displayItems();
  return 0;
}