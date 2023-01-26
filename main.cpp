/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:15:00 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/26 18:03:42 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_black_tree.hpp"

int main()
{
    RBT<int, int> tree;

    // for (int i = 1 ; i <= 16; i+= 1)
    // {
    //     tree.insert(i, 1);
    // }
    
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



    // tree.remove(40);
    // tree.remove(60);
    // tree.remove(70);
    // tree.remove(90);
    // tree.remove(95);
    // tree.remove(100);
    // tree.remove(102);
    // tree.remove(20);
    // tree.remove(30);
    // tree.remove(10);
    // tree.remove(15);
    // tree.remove(105);
    // tree.remove(5);

    // tree.insert(10, 1);
    // tree.insert(20, 1);
    // tree.insert(25, 1);
    // tree.insert(30, 1);
    // tree.insert(40, 1);
    // tree.insert(50, 1);
    // tree.insert(35, 1);

    // for (int i = 1; i <= 4; i++)
    // {
    //     tree.remove(i);
    // }

    // tree.remove(40);
    // tree.remove(10);

    tree.printTree();
    // for (int i = 5; i > 4; i--)
    // {
    //     tree.remove(i);
    //     std::cout << "After remove ------------------------------------------------" << i << std::endl;
    //     tree.printTree();
    // }
    // system("leaks a.out");
    // tree.test();
    // if (tree.check())
        // std::cout << "all is good" << std::endl;

    // RBTree tree;

    // tree.insertValue(13);
    // tree.insertValue(23);
    // tree.insertValue(33);

    // tree.print();
    return 0;
}
