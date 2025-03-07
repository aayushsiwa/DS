// binary expression tree
// a*b/c+e/f*g+k-x*y
//                          -
//                        /  \
//         (a*b/c+e/f*g+k)    (x*y)
//            /  \            /  \
// (a*b/c+e/f*g)  (k)       (x)  (y)
//    /  \        /  \
// (a*b/c) (e/f*g) (k)
//   /  \     /  \
// (a*b)(c)(e/f) (g)
//   / \     / \
// (a) (b) (e) (f)
// inorder: a*b/c+e/f*g+k-x*y
// preorder: -+/*ab/c*efgk*xy
// postorder: ab*c/efg*+k+xy*-

// simply remove the node using bst node deletion algo 
// calculate the balance factor of each node again after deletion
// A is the nearest ancestor of deleted node
// if deleted node are from left subtree of A then it will be called L-delete and if from right then R-delete