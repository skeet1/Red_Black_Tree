/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:15:00 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/15 14:56:24 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_black_tree.hpp"

int main()
{
    RBT<int, int> tree;

    for (int i = 1 ; i <= 15; i++)
    {
        tree.insert(i, 1);
    }
    
    tree.insert(30, 2);
    tree.insert(25, 2);
    // tree.insert(50, 7);
    // tree.insert(60, 7);
    // tree.insert(80, 7);
    // tree.insert(30, 7);
    // tree.insert(40, 7);
    // tree.insert(20, 7);
    // tree.insert(41, 7);
    // tree.insert(39, 7);
    // tree.insert(55, 7);
    // tree.insert(38, 7);
    // tree.insert(37, 7);
    // tree.insert(36, 7);
    // tree.insert(35, 7);
    // tree.insert(34, 7);

    tree.printTree();
    if (tree.check())
        std::cout << "all is good" << std::endl;

    // RBTree tree;

    // tree.insertValue(13);
    // tree.insertValue(23);
    // tree.insertValue(33);

    // tree.print();
    return 0;
}
