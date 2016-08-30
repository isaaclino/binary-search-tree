#/**
 * First Name:      Isaac
 * Last Name:       Lino
 *
 * Filename :       main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings. 
 *
 * All rights reserved by Isaac Lino
 * If you want to use this file, you have to give me credit for it!
 *
 */

include <iostream>
#include "tree.h"
#include "node.h"

using namespace std;

void printOrders( Tree *tree )
{
    cout << "\nPreorder = ";
    tree->preOrder( );
    cout << "\nInorder = ";
    tree->inOrder( );
    cout << "\nPostorder = ";
    tree->postOrder( );
}

int main( )
{
    
    Tree tree;
    
    cout << "Test 1: Testing simple insert" << endl;
    
    tree.insert( "hoppy" );
    tree.insert( "gadget" );
    tree.insert( "hoppy" );
    tree.insert( "gadget" );
    tree.insert( "reel" );
    tree.insert( "trap" );
    tree.insert( "madness" );
    tree.insert( "aeon" );
    tree.insert( "hoppy" );
    tree.insert( "gadget" );
    tree.insert( "hoppy" );
    tree.insert( "gadget" );
    tree.insert( "reel" );
    tree.insert( "trap" );
    tree.insert( "madness" );
    tree.insert( "aeon" );
    tree.insert( "alphabet" );
    tree.insert( "alphabet" );
    tree.insert( "basket" );
    tree.insert( "basket" );
    tree.insert( "hut" );
    tree.insert( "hit" );
    tree.insert( "House" );
    tree.insert( "A+" );
    tree.insert( "jungle" );
    tree.insert( "ink" );
    tree.insert( "jab" );
   
     
    printOrders( &tree );
    cout << "----------------------------------------------------------------"<< endl;
    cout << "Test 2: Search testing" << endl;
    if ( tree.search( "hoppy" ) )
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
    cout << "----------------------------------------------------------------"
    << endl;
    cout << "Test 3: Smallest value in the tree is..." << endl;
    cout << tree.smallest() << endl;
    cout << "----------------------------------------------------------------"
    << endl;
    cout << "Test 4: Largest value in the tree is..." << endl;
    cout << tree.largest() << endl;
    cout << "----------------------------------------------------------------"
    << endl;
    cout << "Test 5: Testing subtree heights" << endl;
    cout << "Height of subtree rooted at \"hoppy\" = " << tree.height( "hoppy" ) << endl;

    cout << "----------------------------------------------------------------"
    << endl;
    cout << "Test 6: Remove testing" << endl;
    cout << "Removing \"hoppy\"" << endl;
    tree.remove( "hoppy" );
    printOrders( &tree );
    cout << "----------------------------------------------------------------" << endl;


    
    return 1;
}
