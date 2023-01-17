# Red_Black_Tree

Red-back tree is self-balancing binary search tree. Red-black trees are uses at current moment in some computer languages for making key-value structures, like objects or associative arrays.

Properties of red black tree:

1) Node should be red or black and might have two child
2) Root of tree should be black
3) All leaves without value is black
4) Both child of red node is black
5) Every way from parent to child should contain equal number of black nodes
6) The new inserting node it's color must be red

so after any operation in our tree inserting/deleting we have to check if these properties it's a still respected, if it's not we have to handle this violation, and for that we have two things (recoloring and rotation), let's understand more about how violation can happend and how we can handle it.

As you see in the rule number 6 our new node's color is red, what's happen if our new node it will be child of another red node, here we break the rule number 4, so how we can handle that.
Actually we have 8 cases, don't woryy we will decrease the number of cases just keep calm and stay focus with me.

First of all we have take a look to these pictuers to understand what i mean when i say (LR, LL, G, U ...)

![alpha meaning](https://github.com/skeet1/Red_Black_Tree/blob/main/img/alpha_meaning.png?raw=true)

![L R meaning](https://github.com/skeet1/Red_Black_Tree/blob/main/img/LR_meaning.png?raw=true)

So let's start with first four cases.

![first four cases of violation after inserting](https://github.com/skeet1/Red_Black_Tree/blob/main/img/first_four_cases.png?raw=true)
