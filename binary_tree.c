#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binary_tree.h"

static BinTreeNode *pi_insert(BinTreeNode *, Leaf *);
static Leaf *pi_search(BinTreeNode *, int *);
static void pi_destroy(BinTreeNode *);

static BinTreeNode *pi_ll_rotation(BinTreeNode *);
static BinTreeNode *pi_rr_rotation(BinTreeNode *);
static BinTreeNode *pi_lr_rotation(BinTreeNode *);
static BinTreeNode *pi_rl_rotation(BinTreeNode *);

static void pi_print_in_order(BinTreeNode *);
static void pi_print_pre_order(BinTreeNode *);
static void pi_print_post_order(BinTreeNode *);

static char pi_height(BinTreeNode *);
static char pi_diff(BinTreeNode *);
