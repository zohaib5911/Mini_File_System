#include <iostream>
#include <string>
#include "Node.h"
#include "DirectoryNode.h"

using namespace std;

int main(){

    DirectoryNode* obj = new DirectoryNode("Folder Y");
    DirectoryNode* chld1 = new DirectoryNode("Folder X",obj);
    obj->addChild("Folder X",chld1);
    obj->display();
    cout<<"\nParent \n";
    Node * parent =  chld1->getParent();
    parent->display();
    cout<<"\nList\n";
    obj->list();
    cout<<"\nSearch by name : \n";
    Node * srch = obj->findByName("Folder X");
    srch->display();
    cout<<"\nIs valid + remove : \n"; 
    if (obj->isValidChild("Folder X")){
        cout<<"Is Valid \n";
    }
    if(obj->removeChild("Folder X")){
        cout<<"Deleted\n";
    }
    
return 0;
} 