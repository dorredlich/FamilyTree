#pragma once
#include<string>
#include <iostream>

using namespace std;

namespace family{

    class Node{
        Node* mother;
        Node* father;
        string childName;
        public:
            Node(string);
    };
    
    class Tree{
        private:
            Node *root;
        public:
        
            Tree();
            ~Tree();
            Tree(string);
            Tree& addFather(string, string);
            Tree& addMother(string , string);
            string relation(string );
            string find(string );
            Node remove(string );
            void display();

    };
}

