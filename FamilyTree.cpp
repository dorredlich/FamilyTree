#include <iostream>
#include <stdexcept>
#include "FamilyTree.hpp"

namespace family{

    Node::Node(string childName){
        this->childName = childName;
        this->father = NULL;
        this->mother = NULL;
    }
    Tree::Tree(): root(NULL){}
   

    Tree::Tree(string childName){
       this->root = new Node(childName);
    }

    Tree::~Tree(){
        if(root != NULL)
            delete root;
    }

    

    Tree& Tree::addFather(string child, string fatherName){
        return *this;
    }

    Tree& Tree::addMother(string child, string motherName){
        return *this;
    }

    string Tree::relation(string name){
        return name;
    }

    string Tree::find(string name){
        return name;
    }

     Node Tree::remove(string name){
        return Node(name);
    }

    void Tree::display(){
        printf("Tree");
    }

}