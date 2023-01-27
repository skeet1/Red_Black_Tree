# Red_Black_Tree

Red-back tree is self-balancing binary search tree. Red-black trees are uses at current moment in some computer languages for making key-value structures, like objects or associative arrays.

Properties of red black tree:

1) Node should be red or black and might have two child
2) Root of tree should be black
3) All leaves without value is black
4) Both child of red node is black
5) Every way from parent to child should contain equal number of black nodes
6) The new inserting node it's color must be red

so after any operation in our tree insertion/deletion we have to check if these properties it's a still respected, if it's not we have to handle the violation, and for that we have two things (recoloring and rotation).

### Recoloring 
Recoloring i think it's clear, it's just flip color of the node, (RED to BLACK)/(BLACK to RED).

### Rotation

in rotation, we have to types, right rotation and left rotation, this pictures will explain what happens in rotation.

- Right Rotation

![right_rotation](https://github.com/skeet1/Red_Black_Tree/blob/main/img/right_rotate.png?raw=true)

![right_rotation](https://github.com/skeet1/Red_Black_Tree/blob/main/img/right_r.gif?raw=true)

- Left Rotation

![left_rotation](https://github.com/skeet1/Red_Black_Tree/blob/main/img/left_rotati.png?raw=true)

![left_rotation](https://github.com/skeet1/Red_Black_Tree/blob/main/img/left_r.gif?raw=true)

## INSERTION

Now let's understand more about how violation in inserting can happend and how we can handle it.

As you see in the rule number 6 our new node's color is red, what's happen if our new node it will be child of another red node, here we break the rule number 4, so how we can handle that.
Actually we have 8 cases, don't woryy we will decrease the number of cases just keep calm and stay focus with me.

First of all we have take a look to these pictuers to understand what i mean when i say (LR, LL, G, U ...)

![alpha meaning](https://github.com/skeet1/Red_Black_Tree/blob/main/img/alpha_meaning.png?raw=true)

![L R meaning](https://github.com/skeet1/Red_Black_Tree/blob/main/img/LR_meaning.png?raw=true)

So let's start with first four cases.

![first four cases of violation after inserting](https://github.com/skeet1/Red_Black_Tree/blob/main/img/first_four_cases.png?raw=true)

the common thing in all these cases is the uncle's color is red, and simple when found uncle's color is red we change the color of parent and uncle to black and grandparent's color to red, it's a very simple isn't.

![recoloring steps](https://github.com/skeet1/Red_Black_Tree/blob/main/img/recoloring_in_first_four_cases.svg?raw=true)

When the uncle's color is black then the process will be a little bit complicated, and for each case there's a diffrenct process.

GeeksForGeeks explain that better than me https://www.geeksforgeeks.org/insertion-in-red-black-tree/

to understand more the insertion part watch this video : https://youtu.be/JDmWPWFKliE

## DELETION

deletion in red black tree it's more complicated than insertion.

first of all let's think logiclly, which rule will be break if we execute the binary search tree deletion process, if we delete a black node, here the rule number 5 is broken, and then you will see something called double-black.

Check this article in GeeksForGeeks https://www.geeksforgeeks.org/deletion-in-red-black-tree/

after that, watch this video : https://youtu.be/JDmWPWFKliE

