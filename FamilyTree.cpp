#include <iostream>
#include <stdexcept>
#include "FamilyTree.hpp"
#define COUNT 10

namespace family{

    Node::Node(){
        this->name = "";
        this->father = nullptr;
        this->mother = nullptr;
        this->depth = 0;
        this->parent_type = "me";
    }

    Node::Node(string name){
        this->name = name;
        this->father = NULL;
        this->mother = NULL;
        depth = 0;
        parent_type = "";
    }
    Tree::Tree(): root(NULL){}
   
    Tree::Tree(string childName){
       this->root = new Node(childName);
       root->father = nullptr;
       root->mother = nullptr;
       root->parent_type = "me";
       root->depth = 0;
    }

  Node* getNode(Node* node, string s){
        if(node->name == s)return node;
        if(node->father != nullptr){
            Node* ans = getNode(node->father, s);
            if(ans != nullptr)return ans;
        }
        if(node->mother != nullptr){
            Node* ans = getNode(node->mother, s);
            if(ans != nullptr)return ans;
        }
        return nullptr;
    }

    Tree& Tree::addFather(string child, string fatherName){
         Node* current = getNode(this->root, child);
         if(current != NULL){
             if(current->father == NULL){
                 current->father = new Node(fatherName);
                 current->father->parent_type = "father";
                 current->father->depth = current->depth+1;
             }
             else{throw invalid_argument("'" + child + "' He has a father");}
         }
        else{throw invalid_argument("Didn't find '" + child  + "'");}
      return *this;
    }

    Tree& Tree::addMother(string child, string motherName){
         Node* current = getNode(this->root, child);
         if(current != NULL){
             if(current->mother == NULL){
                 current->mother = new Node(motherName);
                 current->mother->parent_type = "mother";
                 current->mother->depth = current->depth+1;
             }
             else{ throw invalid_argument("'" + child + "' He has a mother");}
         }
        else{throw invalid_argument("Didn't find '" + child  + "'");}
      
      return *this;
    }

    string getRelation(int depth){
        if(depth <= 1)
            return "";
        if(depth == 2)return "grand";
        string ans = "";
        for(int i = 2; i < depth; i++)
            ans = ans + "great-";
        ans = ans + "grand";
        return ans;
    }

    string Tree::relation(string name){
        Node *current = getNode(this->root,name);
        if(current != NULL) {
            string ans = getRelation(current->depth);
            ans = ans + current->parent_type;
            return ans;
        }
        else{
            return "unrelated";    
        }
    }
    
    void findRecu(Node* node, string relationType, string &ans){
        if(node == NULL)return;
        if(node->mother != NULL && relationType == "grandmother" && node->mother->mother != NULL){
            ans = node->mother->mother->name;
            return;
        }else if(node->father != NULL && relationType == "grandmother" && node->father->mother != NULL){
            ans = node->father->mother->name;
            return;
        }else if(node->mother != NULL && relationType == "grandfather" && node->mother->father != NULL){
            ans = node->mother->father->name;
            return;
        }else if(node->father != NULL && relationType == "grandfather" && node->father->father != NULL){
            ans = node->father->father->name;
            return;
        }
        if((relationType != "grandmother" && relationType != "grandfather") && (relationType.length() < 6 || relationType.substr(0,6) != "great-"))
            throw runtime_error("Did't find this relation");
        if((relationType != "grandmother" && relationType != "grandfather"))
            findRecu(node->father,relationType.substr(6),ans);
        if((relationType != "grandmother" && relationType != "grandfather") && (ans == ""))
            findRecu(node->mother,relationType.substr(6),ans);
    }

    string Tree::find(string relationType){
        if(relationType == "me")return this->root->name;
        if(relationType == "mother" && this->root->mother != NULL)return this->root->mother->name;
        if(relationType == "father" && this->root->father != NULL)return this->root->father->name;
        string s1 = "";
        string& s2 = s1;
        findRecu(this->root,relationType,s2);
        if(s2 == "") throw runtime_error("Can't find the relation");
        return s2;
        
    }

    void deleteNode(Node** node){
        if(*node != NULL){
            deleteNode(&((*(node))->mother));
            deleteNode(&((*(node))->father));
            *node = nullptr;
            delete *node;
        }
    }

    void Tree::remove(string name){
        Node* current = getNode(this->root,name);
        if(current->name == this->root->name) __throw_invalid_argument("Can't delete the root");
        Node** cu = &current;
        if(*cu == NULL) throw runtime_error("Didn't find the person to remove");
        deleteNode(cu);
        *cu = NULL; 
        delete *cu;
    }
    

//https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    void Tree::print2DUtil(Node *root, int space) {  
        // Base case  
        if (root == NULL)  
            return;  
  
        // Increase distance between levels  
        space += COUNT;  
        // Process right child first  
        print2DUtil(root->father, space);  
        // Print current node after space  
        // count  
        cout << endl;  
        for (int i = COUNT; i < space; i++)  
            cout<<" ";  
        cout<< root->name << endl;  
  
        // Process left child  
        print2DUtil(root->mother, space);  
}  

    void Tree::display(){
        print2DUtil(this->root ,0);
    }

}