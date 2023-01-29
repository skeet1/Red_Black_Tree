/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:43:06 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/29 15:19:54 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <map>
#include <vector>
#include "pair.hpp"

template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class RBT {
        struct Node {
            ft::pair<Key, T> p;
            Node*   _parent;
            Node*   _left;
            Node*   _right;
            Node*   _uncle;
            size_t  _black_height;
            size_t  _height;
            char    _color;

            Node(Key key, T value)
            {
                p = ft::make_pair(key, value);
                _parent = NULL;
                _left = NULL;
                _right = NULL;
                _uncle = NULL;
                _color = 'R';
                _black_height = 1;
            }

            Node()
            {
            }
        };
    public:
            typedef Allocator                                                   allocator_type;
            typedef typename allocator_type::template rebind<Node>::other       allocator_node;
    private:
        Node*                   root;
        allocator_type          alloc;
        allocator_node          alloc_node;
    
    protected:
        
        void    insert_node(Key key, T value)
        {
            if (search(root, key))
                return ;
            Node*   newNode = alloc_node.allocate(1);
            alloc_node.construct(newNode, Node(key, value));
            root = insert_node(root, newNode);
            check_violation(newNode);
        }

        Node*   search(Node* root, Key key)
        {
            while (root)
            {
                if (Compare()(key, root->p.first))
                {
                    root = root->_left;
                }
                else if (Compare()(root->p.first, key))
                {
                    root = root->_right;
                }
                else
                    break;
            }
            return root;
        }

        void    swap_node(Node*& n1, Node*& n2)
        {
            Key tmp_key;
            T   tmp_value;

            tmp_key = n1->p.first;
            tmp_value = n1->p.second;

            n1->p.first = n2->p.first;
            n1->p.second = n2->p.second;

            n2->p.first = tmp_key;
            n2->p.second = tmp_value;
        }

        Node*   insert_node(Node* node, Node* newNode)
        {
            if (node == NULL)
                return newNode;
            if (Compare()(newNode->p.first, node->p.first))
            {
                node->_left = insert_node(node->_left, newNode);
                node->_left->_parent = node;
            }
            else if (Compare()(node->p.first, newNode->p.first))
            {
                node->_right = insert_node(node->_right, newNode);
                node->_right->_parent = node;
            }
            return node;
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
                        }
                        left_rotation(root, grandpa);
                        swap_colors(grandpa, parent);
                        node = parent;
                    }
                }
            }
            root->_color = 'B';
        }

        Node*   find_successor(Node* node)
        {
            while (node->_left)
            {
                node = node->_left;
            }
            return node;
        }

        Node*   find_predecessor(Node* node)
        {
            while (node->_right)
            {
                node = node->_right;
            }
            return node;
        }

        void    case_black_leaf(Node*& node)
        {
            Node* parent = node->_parent;
            if (node == parent->_left)
            {
                Node* brother = parent->_right;
                swap_colors(parent, brother);
                
            }
        }
        
        Node*   search(Key val)
        {
            return search(root, val);
        }

        char    get_sibling_color(Node* node)
        {
            Node* parent = node->_parent;

            if (parent && node == parent->_left)
            {
                Node* sibling = parent->_right;
                if (sibling)
                    return sibling->_color;
            }
            else if (parent && node == parent->_right)
            {
                Node* sibling = parent->_left;
                if (sibling)
                    return sibling->_color;
            }
            return 'N';
        }

        Node*   get_sibling(Node* node)
        {
            Node* parent = node->_parent;
            if (parent && node == parent->_left)
                return parent->_right;
            else if (parent && node == parent->_right)
                return parent->_left;
            return nullptr;
        }

        void    remove_node(Node*& node)
        {
            if (node == NULL)
                return ;
            if (!node->_left && !node->_right)
            {
                Node* parent = node->_parent;
                Node* save_node = node;
                
                if (save_node == parent->_left)
                    parent->_left = NULL;
                else if (save_node == parent->_right)
                    parent->_right = NULL;
                alloc_node.destroy(save_node);
                alloc_node.deallocate(save_node, 1);
                save_node = nullptr;
            }
            else if (!node->_right)
            {
                move_data(node, node->_left);
                check_cases(node->_left);
                remove_node(node->_left);
            }
            else if (!node->_left)
            {
                move_data(node, node->_right);
                check_cases(node->_right);
                remove_node(node->_right);
            }
            else
            {
                Node* succ = find_successor(node->_right);
                move_data(node, succ);
                check_cases(succ);
                remove_node(succ);
            }
        }

        // explain of cases functions

        // case one ==> it's the simple case the color of node is red so there's no violation
        void    case_one(Node*& node)
        {
            (void)node;
            // nothing to do here
        }

        // case two ==> when we are in root nothing to do
        void    case_two(Node*& node)
        {
            (void)node;
            return ;
        }

        // case three ==> sibling black and their childs also black
        void    case_three(Node*& node)
        {
            Node*  parent = node->_parent;
            Node*  sibling = get_sibling(node);

            sibling->_color = 'R';
            if (parent->_color == 'R')
                parent->_color = 'B';
            else
            {
                check_cases(parent);
            }
        }

        // case four ==> when sibling color is red
        void    case_four(Node*& node)
        {
            Node*& parent = node->_parent;
            if (parent && node == parent->_left)
            {
                Node*& sibling = parent->_right;
                swap_colors(sibling, parent);
                left_rotation(root, parent);
                check_cases(node);
            }
            else if (parent && node == parent->_right)
            {
                Node*& sibling = parent->_left;
                swap_colors(sibling, parent);
                right_rotation(root, parent);
                check_cases(node);
            }
        }

        // case five ==> sibling is black and far nephew is black and near nephew is red
        void    case_five(Node*& node)
        {
            Node*   parent = node->_parent;
            Node*   sibling = get_sibling(node);
            Node*   near_nephew = get_near_nephew(node);

            swap_colors(sibling, near_nephew);
            if (sibling == parent->_left)
                left_rotation(root, sibling);
            else
                right_rotation(root, sibling);
            case_six(node);
        }

        // case six ==> sibling is black and far nephew is red
        void    case_six(Node*& node)
        {
            Node*   parent = node->_parent;
            Node*   sibling = get_sibling(node);
            Node*   far_nephew = get_far_nephew(node);
            
            swap_colors(parent, sibling);
            if (sibling == parent->_left)
                right_rotation(root, parent);
            else
                left_rotation(root, parent);
            change_color(far_nephew);
        }

        Node*   get_far_nephew(Node* node)
        {
            Node* parent = node->_parent;
            Node* sibling = get_sibling(node);
            if (node == parent->_left)
            {
                if (sibling && sibling->_right)
                    return sibling->_right;
            }
            else if (node == parent->_right)
                if (sibling && sibling->_left)
                    return sibling->_left;
            return nullptr;
        }
        bool    far_nephew_is_black(Node* node)
        {
            Node* far_nephew = get_far_nephew(node);
            if (far_nephew && far_nephew->_color == 'B')
                return true;
            return false;
        }

        void    change_color(Node*& node)
        {
            if (node && node->_color == 'R')
                node->_color = 'B';
            else if (node && node->_color == 'B')
                node->_color = 'R';
        }

        Node*  get_near_nephew(Node* node)
        {
            Node* parent = node->_parent;
            Node* sibling = get_sibling(node);

            if (node == parent->_left)
            {
                if (sibling && sibling->_left)
                    return sibling->_left;
            }
            else if (node == parent->_right)
            {
                if (sibling && sibling->_right)
                    return sibling->_right;
            }
            return nullptr;
        }

        bool    near_newphew_is_red(Node*& node)
        {
            Node* near_nephew = get_near_nephew(node);
            if (near_nephew && near_nephew->_color == 'R')
                return true;
            return false;
        }

        void    check_cases(Node*& node)
        {
            // std::cout << node->p.first << ", color is : " << node->_color << std::endl;
            if (node->_color == 'R')
            {
                case_one(node);
            }
            else if (node == root)
            {
                case_two(node);
                return ;
            }
            else if (get_sibling_color(node) == 'B' && black_child(get_sibling(node)))
            {
                case_three(node);
            }
            else if (get_sibling_color(node) == 'R')
            {
                case_four(node);
            }
            else if (get_sibling_color(node) == 'B' && far_nephew_is_black(node) && near_newphew_is_red(node))
            {
                case_five(node);
            }
            else if (get_sibling_color(node) == 'B' && !far_nephew_is_black(node))
            {
                case_six(node);
            }
        }

        void    remove(Node*& node, Key key)
        {
            if (!node)
                return ;
            if (Compare()(key, node->p.first))
                remove(node->_left, key);
            else if (Compare()(node->p.first, key))
                remove(node->_right, key);
            else
            {
                if (node->_left == NULL && node->_right == NULL)
                {
                    if (node == root)
                    {
                        alloc_node.destroy(node);
                        alloc_node.deallocate(node, 1);
                        node = nullptr;
                    }
                    else
                    {
                        check_cases(node);
                        remove_node(node);
                    }
                }
                else
                {
                    remove_assist(node);
                }
            }
        }

        void    remove_assist(Node*& node)
        {
            if (node->_left == NULL)
            {
                move_data(node, node->_right);
                check_cases(node->_right);
                remove_node(node->_right);
            }
            else if (node->_right == NULL)
            {
                move_data(node, node->_left);
                check_cases(node->_left);
                remove_node(node->_left);
            }
            else
            {
                Node* succ = find_successor(node->_right);
                move_data(node, succ);
                check_cases(succ);
                remove_node(succ);
            }
        }

        void    move_data(Node*&n1, Node* n2)
        {
            n1->p.first = n2->p.first;
            n1->p.second = n2->p.second;
        }

        bool    black_child(Node* node)
        {
            if (node->_left && node->_left->_color == 'R')
                return false;
            if (node->_right && node->_right->_color == 'R')
                return false;
            return true;
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
            std::cout << "(" << root->p.first << ":" << root->p.second << ")";
            if (root->_parent)
                std::cout << " P is : " << root->_parent->p.first;
            else
                std::cout << " i am the root";
            std::cout << std::endl << std::endl;
            printTree(root->_left, depth+1);
            std::cout << "\033[0m";
        }

        void    clear(Node*& node)
        {
            if (node == NULL)
                return ;
            clear(node->_left);
            clear(node->_right);
            alloc_node.destroy(node);
            alloc_node.deallocate(node, 1);
            node = nullptr;
        }
        
    public:
    
        RBT()
        {
            root = NULL;
        }

        void    insert(Key key, T value)
        {
            insert_node(key, value);
        }

        void    remove(Key key)
        {
            remove(root, key);
        }

        bool    find(Key key)
        {
            if (search(key))
                return true;
            return false;
        }

        void    clear()
        {
            clear(root);
        }

        void    printTree()
        {
            printTree(root, 0);
        }
};

#endif 
