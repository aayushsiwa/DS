// m-way search tree
// extended version of bst
// each node has m-1 keys and m children
// keys in each node are ordered
// all leaves are at the same level
// search, insert, delete, traverse


// b tree
// extended version of bst
// b tree of order n satisfies the following criteria 
// each node has atmost m children
// each internal node has atleast ciel(m/2) children
// root has atleast 2 children if it is not a leaf node
// a non leaf node with k children contains k-1 keys
// all leaves appear in the same level(keeping the height balanced)
// Construction of b tree
// m=3
// 1,7,6,2,11,4,8
// 1,2,4,6,7,8,11
//                          [1|7]
//                          /   \
//                   [1|2]4       [7|11]
//                      / \       / \