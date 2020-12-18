#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct { int data; } BinTreeData;

typedef struct {
  int key;
  BinTreeData value;
} Leaf;

typedef struct {
  struct BinTreeNode *p_left;
  struct BinTreeNode *p_right;
  Leaf data;
} BinTreeNode;

typedef struct {
  BinTreeNode *p_root;
} BinTree;

void bt_init(BinTree *);
void bt_destroy(BinTree *);

void bt_insert(BinTree *, Leaf *);
Leaf *bt_search(BinTree *);

void bt_in_order_print(BinTree *);
void bt_pre_order_print(BinTree *);
void bt_post_order_print(BinTree *);

#endif
