#include <iostream>
#include <string>
#include "DirectoryNode.h"
using namespace std;

int main(){

    DirectoryNode* obj = new DirectoryNode("Folder Y");
    DirectoryNode* chld1 = new DirectoryNode("Folder X",obj);
    obj->addChild("Folder Y",chld1);
    obj->display();
    

return 0;
} 