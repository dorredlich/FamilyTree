#pragma once
#include<string>
#include <iostream>

using namespace std;

namespace family{

    class Node{
        public:
        Node* mother;
        Node* father;
        string name;
        int depth;
        string parent_type;
        Node();
        Node(string);
    };
    
    class Tree{
        private:
            Node *root;
        public:
            Tree();
        //    ~Tree();
            Tree(string);
            Tree& addFather(string, string);
            Tree& addMother(string , string);
            string relation(string );
            string find(string );
            void remove(string );
            void display();
            void print2DUtil(Node *root, int space);

    };
}

