/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:15:00 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/27 13:02:35 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_black_tree.hpp"

typedef struct s
{
    std::string name;
    size_t      age;
}           st;

int main()
{
    RBT<int, int> tree;

    // for (int i = 1 ; i <= 10000000; i+= 1)
    // {
    //     tree.insert(i, 1);
    // }
    
    // for (int i = 1 ; i <= 9999990; i+= 1)
    // {
    //     tree.remove(i);
    // }

    // // tree.remove(1);
    // tree.printTree();
    
    tree.insert(40, 2);
    tree.insert(60, 2);
    tree.insert(20, 2);
    tree.insert(80, 2);
    tree.insert(30, 2);
    tree.insert(10, 2);
    tree.insert(70, 2);
    tree.insert(90, 2);
    tree.insert(100, 2);
    tree.insert(5, 2);
    tree.insert(15, 2);
    tree.insert(105, 2);
    tree.insert(102, 2);
    tree.insert(95, 2);



    tree.remove(40);
    tree.remove(60);
    tree.remove(70);
    tree.remove(80);
    tree.remove(90);
    tree.remove(95);
    tree.remove(100);
    tree.remove(102);
    tree.remove(20);
    tree.remove(30);
    tree.remove(10);
    tree.remove(15);
    tree.remove(105);
    tree.remove(5);

    tree.printTree();
}
