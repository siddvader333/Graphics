#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list> 

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>,std::shared_ptr<Object> > > & 
    leaf_pairs)
{

  //algorithm found in readme
  leaf_pairs = {}; 
  if (!box_box_intersect(rootA->box, rootB->box))
    return; 

  std::list<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>>> Q;
  Q.push_back(std::make_pair(rootA, rootB));

  while (!Q.empty()) {
    auto A = Q.front().first;
    auto B = Q.front().second;
    Q.pop_front();
    std::shared_ptr<AABBTree> ATree = std::dynamic_pointer_cast<AABBTree>(A);
    std::shared_ptr<AABBTree> BTree = std::dynamic_pointer_cast<AABBTree>(B);

    if (!ATree && !BTree) { // Neither A nor B are Trees
      leaf_pairs.push_back(std::make_pair(A, B));
    } 
    else if (!ATree) { //A not a tree but B is a tree

      if (BTree->left && box_box_intersect(A->box, BTree->left->box)){
        Q.push_back(std::make_pair(A, BTree->left));
      }

      if (BTree->right && box_box_intersect(A->box, BTree->right->box)){
        Q.push_back(std::make_pair(A, BTree->right));
      }
    } 
    else if (!BTree) { // B is not a tree but A is a tree
      if (ATree->left && box_box_intersect(B->box, ATree->left->box)){
        Q.push_back(std::make_pair(ATree->left, B));
      }
      if (ATree->right && box_box_intersect(B->box, ATree->right->box)){
        Q.push_back(std::make_pair(ATree->right, B));
      }
    } else {
      //Both A and B Are Trees
      if (ATree->left && BTree->left && box_box_intersect(ATree->left->box, BTree->left->box)){
        Q.push_back(std::make_pair(ATree->left, BTree->left));
      }
      if (ATree->left && BTree->right && box_box_intersect(ATree->left->box, BTree->right->box)){
        Q.push_back(std::make_pair(ATree->left, BTree->right));
      }
      if (ATree->right && BTree->left && box_box_intersect(ATree->right->box, BTree->left->box)){
        Q.push_back(std::make_pair(ATree->right, BTree->left));
      }
      if (ATree->right && BTree->right && box_box_intersect(ATree->right->box, BTree->right->box)){
        Q.push_back(std::make_pair(ATree->right, BTree->right));
      }

    }
  }
}