#include <iostream>
#include <string>
#include "Node.h"
#include "DirectoryNode.h"

using namespace std;

int main(){

    DirectoryNode* obj = new DirectoryNode("Folder Y");
    DirectoryNode* chld1 = new DirectoryNode("Folder X",obj);
    obj->addChild("Folder Y",chld1);
    obj->display();
    obj->list(2);
    cout<<"\nParent \n";
    Node * parent =  chld1->getParent();
    parent->display();

return 0;
} 