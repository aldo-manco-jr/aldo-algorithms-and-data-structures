#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

typedef struct {
    int value;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} TreeNode;

TreeNode *insert(TreeNode *rootNode, int value);

void inOrder(TreeNode *tmpNode);

void preOrder(TreeNode *tmpNode);

void postOrder(TreeNode *tmpNode);

int heightTree(TreeNode *rootNode);

void singlyLevelOrder(TreeNode *rootNode, int level);

void levelOrder(TreeNode *rootNode);

TreeNode *minValueNode(TreeNode *rootNode);

TreeNode *delete(TreeNode *rootNode, int value);

int main() {
    TreeNode *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inOrder(root);
    puts("");
    preOrder(root);
    puts("");
    postOrder(root);
    puts("");
    levelOrder(root);
    puts("");
    return 0;
}

TreeNode *insert(TreeNode *rootNode, int value) {

    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    if (rootNode == NULL) {
        return newNode;
    }

    if (value < rootNode->value) {
        rootNode->leftChild = insert(rootNode->leftChild, value);
    } else if (value > rootNode->value) {
        rootNode->rightChild = insert(rootNode->rightChild, value);
    }
    return rootNode;
}

void inOrder(TreeNode *tmpNode) {
    if (tmpNode != NULL) {
        inOrder(tmpNode->leftChild);
        printf("%i, ", tmpNode->value);
        inOrder(tmpNode->rightChild);
    }
}

void preOrder(TreeNode *tmpNode) {
    if (tmpNode != NULL) {
        printf("%i, ", tmpNode->value);
        inOrder(tmpNode->leftChild);
        inOrder(tmpNode->rightChild);
    }
}

void postOrder(TreeNode *tmpNode) {
    if (tmpNode != NULL) {
        inOrder(tmpNode->leftChild);
        inOrder(tmpNode->rightChild);
        printf("%i, ", tmpNode->value);
    }
}

void singlyLevelOrder(TreeNode *rootNode, int level) {

    if (rootNode == NULL) {
        return;
    }

    if (level == 1) {
        printf("%i, ", rootNode->value);
    } else if (level > 1) {
        singlyLevelOrder(rootNode->leftChild, level - 1);
        singlyLevelOrder(rootNode->rightChild, level - 1);
    }
}

void levelOrder(TreeNode *rootNode) {

    for (int i = 1; i <= heightTree(rootNode); ++i) {
        singlyLevelOrder(rootNode, i);
    }
}

int heightTree(TreeNode *rootNode) {

    if (rootNode == NULL) {
        return 0;
    } else {
        int leftSubTreeHeight = heightTree(rootNode->leftChild);
        int rightSubTreeHeight = heightTree(rootNode->rightChild);

        return (leftSubTreeHeight > rightSubTreeHeight) ? leftSubTreeHeight + 1 : rightSubTreeHeight + 1;
    }
}

TreeNode *minValueNode(TreeNode *rootNode) {
    TreeNode *currentNode = rootNode;

    while (currentNode && currentNode->leftChild != NULL) {
        currentNode = currentNode->leftChild;
    }
    return currentNode;
}

TreeNode *delete(TreeNode *rootNode, int value) {
if (rootNode == NULL) {
return rootNode;
}

if (value < rootNode->value) {
rootNode = delete(rootNode->leftChild, value);
} else if (value > rootNode->value) {
rootNode = delete(rootNode->rightChild, value);
} else {
if (rootNode->leftChild == NULL) {
TreeNode *tmp = rootNode->rightChild;
free(rootNode);
return tmp;
} else if (rootNode->rightChild == NULL) {
TreeNode *tmp = rootNode->leftChild;
free(rootNode);
return tmp;
} else {
TreeNode *tmp = minValueNode(rootNode->rightChild);
rootNode->value = tmp->value;
rootNode->rightChild = delete(rootNode->rightChild, tmp->value);
}
return rootNode;
}
}