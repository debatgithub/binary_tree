#include <iostream>
#include "tree_node.h"
#include "binary_tree.h"
int main (void );
#define TREE_MAX 9
int tree_vals[TREE_MAX] = { 123, 67, 11, 324, 5, 220, 193, 121, 340 };
int main (void ) 
{

    binary_tree<int> * p_bt = new binary_tree<int>();
    tree_node<int> *p_node;
    tree_node<int> *q_node;
    BT_ERROR bt_e;

    if (p_bt == NULL) {
        std::cout << "Binary tree constructor failed" << std::endl;
        return 1;
    }
    std::cout << "Binary tree constructor passed" << std::endl;
 
    for (int i = 0; i < TREE_MAX; i++) {
        p_node = new tree_node<int>(tree_vals[i]);
        if (p_node != NULL)
            p_bt->insert_node(p_node);
        else
            std::cout << "Tree node creation failed" << std::endl;
    }
    std::cout << "Binary tree  insert_node() passed" << std::endl;
    std::cout << "Tree now -" << std::endl;
    p_bt->print_tree_in_order(p_bt->get_root());
    std::cout << std::endl;

    p_node = new tree_node<int>(121);
    q_node = p_bt->search_node(p_node, &bt_e);
    if (bt_e == BT_SUCCESS) 
         std::cout << "Binary tree search_node() passed" << std::endl; 
    else
         std::cout << "Binary tree search_node() failed" << std::endl;

    p_node = new tree_node<int>(123);
    bt_e = p_bt->delete_node(p_node);
    if (bt_e == BT_SUCCESS) 
         std::cout << "Binary tree delete_node() passed" << std::endl; 
    else
         std::cout << "Binary tree delete_node() failed" << std::endl;
 
    std::cout << "Tree now" << std::endl;
    p_bt->print_tree_in_order(p_bt->get_root());
    std::cout << std::endl;

  
    delete p_bt;
    return 0;

   
}


        
