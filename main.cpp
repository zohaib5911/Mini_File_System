#include <iostream>
#include <string>
#include "Node.h"
#include "file.h"
#include "DirectoryNode.h"

using namespace std;

int main(){
    DirectoryNode* obj = new DirectoryNode("Folder Y");
    DirectoryNode* chld1 = new DirectoryNode("Folder X",obj);
    obj->addChild("Folder X",chld1);
    DirectoryNode* chld2 = new DirectoryNode("fl",obj);
    obj->addChild("fl",chld2);
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
    cout<<"\nGeT Child\n";
    Node* x = obj->getChild("fl");
    x->display();

    cout<<"\nCreating file\n";
    File* f1 = new File("Names",obj);
    obj->addChild("Name",f1);
    f1->addContent("M ZOHAIB SAJJAD");
    cout<<f1->isDirectory()<<endl;
    Node* p1 = f1->getParent();
    p1->display();
    cout<<"\nFile \n";
    f1->display();
return 0;
} 