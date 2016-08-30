/**
 * Course: CS 14 Summer 2016
 *
 * First Name:      Isaac
 * Last Name:       Lino
 * Username:        ilino
 * email address:   ilino001@ucr.edu
 *
 *
 * Assignment:      assn3
 * Filename :       tree.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#ifndef __TREE_H
#define __TREE_H

#include <iostream>
#include <string>

using namespace std;

class Tree {
    
    class Node
    {
        friend class Tree;
        
    public:
        
        string value;
        Node* left;
        Node* right;
        
    
        Node(const string& v) : value(v), left(NULL), right(NULL) {}
        
        

   
        bool leaf()
        {
            return left == NULL && right == NULL;
        }
    
        int size()
        {
            
            int size = 1;
            if(leaf())
            {
                return 1;
            }
            if(left!=NULL){
                size += left->size();
            }
            if(right!=NULL){
                size += right->size();
            }
            return size;
        }
    }; // class Node
    
    
    Node* root;
    int count;
    
    
    
public:
    
    void insert( const string & );
    void remove ( const string & );
    int height( const string & );
    string smallest();
    string largest();
    
    
    
    bool leaf()
    {
        const Node* t;
        return t->left == NULL && t->right == NULL;
    }
    int size()
    {
        if (leaf())
        {
            return 1;
        }
        if(root==NULL)
        {
            return 0;
        }
        Node* temp = root;
        return temp->size();
        
    }
    bool empty()
    {
        return size() == 0;
    }
    void print_node(const Node* n)
    {
        cout << n->value << endl;
        
    }
    
    
    /* CONSTRUCTOR */
    Tree()
    {
        root=NULL;
    }
    // Tree() : count(0), root(NULL) {}
    
    
    /* DESTRUCTOR */
    ~Tree()
    {
        destructor(root);
    }
    void destructor(Node *t)
    {
        if(!t)
        {
            return;
        }
        destructor(t->left);
        destructor(t->right);
        
        delete t;
    }
  
    /* INSERT */
    static Node* insert(const string v, Node* t)
    {
        if(t == NULL)
        {
            t = new Node(v);
        }
        else if (v < t->value)
        {
            t->left = insert(v, t->left);
        }
        else if (v > t->value)
        {
            t->right = insert(v, t->right);
        }
        else
        {
            t->value = v;
        }
        return t;
    }
    
    /* REMOVE */
    static Node* remove(const string v, Node* t)
    {
        if(t)
        {
            if(v < t->value)
            {
                t->left = remove(v, t->left);
            }
            else if(t->value < v)
            {
                t->right = remove(v, t->right);
            }
            
            else if(t->left != NULL && t->right != NULL)
            {
                t->value = smallest(t->right)->value;
                t->right = remove(t->value, t->right);
            }
            else
            {
                Node* oldNode = t;
                t = (t->left != NULL) ? t->left
                : t->right;
                delete oldNode;
            }
        }
        return t;
    }
    
     /* SMALLEST */
    static Node* smallest(Node* t)
    {
        if(t == NULL)
        {
            return NULL;
        }
        if(t->left == NULL)
        {
            return t;
        }
        return smallest(t->left);
        
    }
    
     /* LARGEST */
    static Node* largest(Node* t)
    {
        if(t == NULL)
        {
            return NULL;
        }
        
        
        if(t->right == NULL)
        {
            return t;
        }
        return largest(t->right);
    }
    
    
    /* HEIGHT */
    /*
    static Node* height(const string v, Node* t)
    {
        if (t->left == NULL && t->right == NULL)
        {
            return NULL;
        }
        
        if(t->left!=NULL)
        {
            return 1 + height(v, t->left);
            //return 1 + t->left->height();
        }
        return 1 + height(v, t->right);
        //return 1 + right->height();
    
    
        return t;
    }
    */
    
   
  

    
    bool search(const string v)
    {
        
        bool found;
        Node* temp = root;
        if(root==NULL)
        {
            return false;
        }
        else if(root->value==v)
        {
            return true;
        }
        else if(v<= root->value)
        {
            root = root->left;
            found = search(v);
        }
        else
        {
            root = root->right;
            found = search(v);
        }
        root = temp;
        return found;
    }
    
    
    
    void inOrderHelper(Node* temp)const
    {
        if(temp->left!=NULL)
        {
            inOrderHelper(temp->left);
        }
        cout << temp->value << ' ';
        if(temp->right!=NULL)
        {
            inOrderHelper(temp->right);
        }
    }
    void inOrder()const
    {

        Node*temp = root;
        inOrderHelper(temp);
    }
    
    
    
    void preOrderHelper(Node* temp)const
    {
        cout << temp->value << ' ';
        if(temp->left!=NULL)
        {
            preOrderHelper(temp->left);
        }
        if(temp->right!=NULL)
        {
            preOrderHelper(temp->right);
        }
    }
    void preOrder()const
    {

        Node*temp = root;
        preOrderHelper(temp);
    }
    
    
    void postOrderHelper(Node* temp)const
    {
        if(temp->left!=NULL)
        {
            postOrderHelper(temp->left);
        }
        if(temp->right!=NULL)
        {
            postOrderHelper(temp->right);
        }
        cout << temp->value << ' ';
    }
    void postOrder()const
    {

        Node*temp = root;
        postOrderHelper(temp);
    }
    
    
    
}; // Tree

string
Tree::largest()
{
    return root->value;
}

string
Tree::smallest()
{
    return root->value;
}

void
Tree::insert(const string & v)
{
    root = insert(v, root);
}

void
Tree::remove(const string & v)
{
    root = remove(v, root);
}

int
Tree::height(const string & v)
{
  
    Node* t = new Node(v);
    
    if ((t->left == NULL) && (t->right == NULL))
    {
        return -1;
        
    }
    else
    {
      
        // compute the depth of each subtree
        int left = height(v);
        
        
        int right = height(v);
        
        // use the larger one
        if (left > right)
        {
            return (left+1);
        }
        else
        {
            return (right+1);
        }
    }
}

#endif