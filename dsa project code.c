#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// AVL Node Structure
typedef struct AVLTreeNode {
    char* word;
    int count;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
} AVLTreeNode;

// Create a new node
AVLTreeNode* createNode(const char* word) {
    AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
    newNode->word = strdup(word);  // Duplicate the word to save it
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Get node height
int getHeight(AVLTreeNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

// Get balance factor
int getBalance(AVLTreeNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation
AVLTreeNode* rightRotate(AVLTreeNode* y) {
    AVLTreeNode* x = y->left;
    AVLTreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));

    return x;
}

// Left rotation
AVLTreeNode* leftRotate(AVLTreeNode* x) {
    AVLTreeNode* y = x->right;
    AVLTreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + fmax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + fmax(getHeight(y->left), getHeight(y->right));

    return y;
}

// Function to convert a string to lowercase
void toLowerCase(char* word) {
    for (int i = 0; word[i]; i++) {
        word[i] = (char)tolower((int)word[i]);  // Cast to int and back to char
    }
}


// Insert a word into the AVL tree
AVLTreeNode* insert(AVLTreeNode* node, const char* word) {
    if (node == NULL)
        return createNode(word);

    // Create a copy of the word and convert it to lowercase
    char wordCopy[strlen(word) + 1];
    strcpy(wordCopy, word);
    toLowerCase(wordCopy);  // Convert to lowercase for comparison

    // Compare the lowercase version of the word
    if (strcmp(wordCopy, node->word) < 0)
        node->left = insert(node->left, wordCopy);
    else if (strcmp(wordCopy, node->word) > 0)
        node->right = insert(node->right, wordCopy);
    else {
        node->count++;
        return node;
    }

    // Update height
    node->height = 1 + fmax(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && strcmp(wordCopy, node->left->word) < 0)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && strcmp(wordCopy, node->right->word) > 0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && strcmp(wordCopy, node->left->word) > 0) {
        node->left = leftRotate(no

