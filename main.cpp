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
    DirectoryNode* chld2 = new DirectoryNode("Child 2",obj);
    obj->addChild("Child 2",chld2);
    
    // obj->display();
    // cout<<"\nParent \n";
    // Node * parent =  chld1->getParent();
    // parent->display();
    // cout<<"\nList\n";
    // obj->list();
    // cout<<"\nSearch by name : \n";
    // Node * srch = obj->findByName("Folder X");
    // srch->display();
    // cout<<"\nIs valid + remove : \n"; 
    // if (obj->isValidChild("Folder X")){
    //     cout<<"Is Valid \n";
    // }
    // if(obj->removeChild("Folder X")){
    //     cout<<"Deleted\n";
    // }
    // cout<<"\nGeT Child\n";
    // Node* x = obj->getChild("fl");
    // x->display();

    // cout<<"\nCreating file\n";
    File* file_1 = new File("Names File",chld1);
    chld1->addChild("Names File",file_1);
    file_1->addContent("M ZOHAIB SAJJAD");
    // cout<<f1->isDirectory()<<endl;
    // Node* p1 = f1->getParent();
    // p1->display();
    // cout<<"\nFile \n";
    // f1->display();
    //  cout<<"\nIs valid + remove : \n"; 
    // if (obj->isValidChild("Name")){
    //     cout<<"Is Valid \n";
    // }
    // if(obj->removeChild("Name")){
    //     cout<<"Deleted\n";
    // }
    // cout<<"-";

    // cout<<"Get full Path: "<<chld1->getFulPath();

    // obj->duplicate("Folder X");
    // Node * s1 = obj->findByName("Folder X_Copy");
    // // obj->list();
    // s1->display();
    // Node * fp = s1->getChild("Name");
    // fp->display();

    cout<<"\nBefore : \n";

    cout<<"Child 1 : \n";
    chld1->display();
    cout<<"\nChild 2:  \n";
    chld2->rename("Renamed Folder");
    chld2->display();

    cout<<"\nAfter : \n";

    chld1->move(file_1,chld2);
    cout<<"Child 1 : \n";
    chld1->display();
    cout<<"\nChild 2:  \n";
    chld2->display();

return 0;
} 