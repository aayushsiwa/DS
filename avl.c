// AVL Tree or Height Balanced Tree
// l->Adelson, Vellcii, Landis

// AVL Tree - A binary search tree with Bl and Br as the left and right subtrees of the root B will be called AVL tree iff 
//      Bl and Br are AVL trees
//      Balance Factor = h(Bl) - h(Br) = {-1, 0, 1}

//                  50
//                /  \  
//               30   60
//                \   / \
//                40 55 70
//                /      \
//              41       80

// Coversion of a BST(Non-AVL) to AVL Tree
//      LL or Right Rotation- Single Rotation -- It is used when a node is inserted left of left subtree.
//          Example:
//                (+2)50
//                /  
//           (+1)30         =>  (0)30
//              /               /  \
//          (0)20          (0)20   50(0)
//      RR or Left Rotation- Single Rotation -- It is used when a node is inserted right of right subtree.
//          Example:
//                     50(-2)
//                     \
//                      60(-1)   =>  (0)50
//                        \           /  \
//                        70(0)  (0)20   70(0)
//     LR or Left-Right Rotation- Double Rotation -- It is used when a node is inserted right of left subtree.
//         Example: 
//                (+2)50            50
//                 /                /
//           (-1)30       RR=>  (0)35       LL=>  (0)35
//                 \             /                  /  \
//              (0)35           30(0)            30(0) 50(0)
//     RL or Right-Left Rotation- Double Rotation -- It is used when a node is inserted left of right subtree.
//         Example: 
//                (-2)50                50
//                     \                 \
//                 (+1)60       LL=>  (0)55       LL=>      (0)55
//                   /                    \                  /  \
//              (0)55                     60()            50(0) 60(0)


// Construct AVL tree by inserting the following elements in the order given: 14,17,11,7,53,4,13,12
//      14
//     /  \
//   11    17
//  / \    / \
// 7  13  53  4
//       /
//      12

// Construct an AVL Tree by inserting the following elements in the order given: 64,1,14,26,13,110,98,85
//      64
//     /  \
//    14   98
//   / \   / \
//  1  26 85 110
//     /
//    13

//  Construct an AVL Tree by inserting the following elements in the order given: 3,2,1,4,5,6,7,16,15,14
//      4
//     / \
//    2   6
//   / \  / \
//  1  3 5   15
//            \
//            16
//             \
//             14
