/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:43:06 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/17 10:39:04 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>

template<class Key, class T>
class RBT {
        struct Node {
            Key     _key;
            T       _value;
            Node*   _parent;
            Node*   _left;
            Node*   _right;
            Node*   _uncle;
            size_t  _black_height;
            size_t  _height;
            char    _color;

            Node(Key key, T value)
            {
                _key = key;
                _value = value;
                _parent = NULL;
                _left = NULL;
                _right = NULL;
                _uncle = NULL;
                _color = 'R';
                _black_height = 1;
            }
        };
    private:
        
        Node*   root;
    public:
        // void    rotate_left(Node *node);
        // void    rotate_right(Node *node);
        // void    delete_node(Key key);
        // char    get_color(Node *node);
        // void    set_color(Node *node);
        RBT()
        {
            root = NULL;
        }

        void    insert(Key key, T value)
        {
            insert_node(key, value);
        }
        
        void    insert_node(Key key, T value)
        {
            if (search(root, key))
                return ;
            Node*   newNode = new Node(key, value);
            root = insert_node(root, newNode);
            check_violation(newNode);
        }

        Node*   search(int val)
        {
            return search(root, val);
        }

        Node*   search(Node* root, Key key)
        {
            // recursive way 
            
            // if (root == NULL)
            //     return NULL;
            // if (root->_key == key)
            //     return root;
            // else if (root->_key > key)
            //     return search(root->_left, key);
            // else
            //     return search(root->_right, key);

            // iterative way
            while (root)
            {
                if (root->_key > key)
                {
                    root = root->_left;
                }
                else if (root->_key < key)
                {
                    root = root->_right;
                }
                else
                    break;
            }
            return root;
        }

        Node*   insert_node(Node* root, Node* newNode)
        {
            if (root == NULL)
                return newNode;
            if (root->_key > newNode->_key)
            {
                root->_left = insert_node(root->_left, newNode);
                root->_left->_parent = root;
            }
            else if (root->_key < newNode->_key)
            {
                root->_right = insert_node(root->_right, newNode);
                root->_right->_parent = root;
            }
            if (root->_left)
                root->_black_height = root->_left->_black_height + (root->_left->_color == 'B');
            else if (root->_right)
                root->_black_height = root->_right->_black_height + (root->_right->_color == 'B');
            return root;
        }

        void    right_rotation(Node*& root, Node* node)
        {
            Node* node_left = node->_left;

            node->_left = node_left->_right;

            if (node->_left != NULL)
                node->_left->_parent = node;
                
            node_left->_parent = node->_parent;

            if (node->_parent == NULL)
                root = node_left;

            else if (node == node->_parent->_right)
                node->_parent->_right = node_left;

            else
                node->_parent->_left = node_left;

            node_left->_right = node;
            node->_parent = node_left;
        }

        void left_rotation(Node*& root, Node* node)
        {
            Node *node_right = node->_right;

            node->_right = node_right->_left;

            if (node->_right != NULL)
                node->_right->_parent = node;

            node_right->_parent = node->_parent;

            if (node->_parent == NULL)
                root = node_right;

            else if (node == node->_parent->_left)
                node->_parent->_left = node_right;

            else
                node->_parent->_right = node_right;

            node_right->_left = node;
            node->_parent = node_right;
        }

        void    swap_colors(Node*& n1, Node*& n2)
        {
            char    tmp;

            tmp = n1->_color;
            n1->_color = n2->_color;
            n2->_color = tmp;
        }

        void    check_violation(Node *node)
        {
            Node* parent = nullptr;
            Node* grandpa = nullptr;
            Node* uncle = nullptr;
            
            while (node != root && node->_color == 'R' && node->_parent->_color == 'R')
            {
                parent = node->_parent;
                grandpa = node->_parent->_parent;
                if (parent == grandpa->_left)
                {
                    uncle = grandpa->_right;
                    if (uncle && uncle->_color == 'R')
                    {
                        uncle->_color = 'B';
                        parent->_color = 'B';
                        grandpa->_color = 'R';
                        node = grandpa;
                    }
                    else
                    {
                        if (node == parent->_left)
                        {
                            right_rotation(root, grandpa);
                            swap_colors(grandpa, parent);
                        }
                        else
                        {
                            left_rotation(root, parent);
                            right_rotation(root, grandpa);
                            swap_colors(grandpa, node);
                        }
                        node = parent;
                    }
                }
                else if (parent == grandpa->_right)
                {
                    uncle = grandpa->_left;
                    if (uncle && uncle->_color == 'R')
                    {
                        uncle->_color = 'B';
                        parent->_color = 'B';
                        grandpa->_color = 'R';
                        node = grandpa;
                    }
                    else
                    {
                        if (node == parent->_left)
                        {
                            right_rotation(root, parent);
                            parent = grandpa->_right;
                            node = parent->_right;
                            // std::cout << "print_infos : " << std::endl;
                            // std::cout << "grandpa is : " << grandpa->_key << std::endl;
                            // std::cout << "parent is  : " << parent->_key << std::endl;
                            // std::cout << "node is    : " << node->_key << std::endl;
                        }
                        left_rotation(root, grandpa);
                        swap_colors(grandpa, parent);
                        node = parent;
                    }
                }
            }
            root->_color = 'B';
        }

        // void    remove(Key key)
        // {
        //     remove_node(search(root, key));
        // }

        // void    remove_node(Node* node)
        // {
            
        // }

        void    printTree()
        {
            printTree(root, 0);
        }

        void    printTree(Node* root, int depth)
        {
            if (root == NULL)
                return ;
            printTree(root->_right, depth+1);
            for (int i = 0; i < depth; i++)
                std::cout << "               ";
            if (root->_color == 'R')
                std::cout << "\033[31m";
            else
                std::cout << "\033[30m";
            std::cout << "(" << root->_key << ":" << root->_value << ")";
            if (root->_parent)
                std::cout << " P is : " << root->_parent->_key;
            else
                std::cout << " i am the root";
            std::cout << " H: " << root->_black_height << std::endl;
            std::cout << std::endl << std::endl;
            printTree(root->_left, depth+1);
            std::cout << "\033[0m";
        }

        bool    check()
        {
            return check(root);
        }

        bool    check(Node* root)
        {
            if (!root)
                return true;
            if (root->_right && root->_left)
                return ((root->_right->_black_height + root->_right->_color == 'B') == (root->_left->_black_height + root->_left->_color == 'B'));
            return (check(root->_right) && check(root->_left));
        }

        private:
            RBT*    _tree;
};

#endif 