#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef enum TypeTag {
    ADD, /**< The type tag for addition operation */
    SUB, /**< The type tag for subtraction operation */
    MUL, /**< The type tag for multiplication operation */
    DIV /**< The type tag for division operation */
} TypeTag;

typedef struct Node {
    TypeTag type; /**< The type of the node */
    int value; /**< The value of the node */
} Node;

/**
 * @brief The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1. The function calculates the nth number in the sequence.
 * @param n The nth number in the Fibonacci sequence to calculate.
 * @return The calculated nth number in the Fibonacci sequence.
 */

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0, b = 1, c;
    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/**
 * @brief Creates a node of integer type.
 * @param type The type of the node.
 * @param leftValue The left value of the node.
 * @param rightValue The right value of the node.
 * @return A pointer to the created node.
 */
Node* typeNodeInt(TypeTag type, int leftValue, int rightValue) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;

    switch (type)
    {
    case ADD:
        node->value = leftValue + rightValue;
        break;
    case SUB:
        node->value = rightValue - leftValue;
        break;
    case MUL:
        node->value = leftValue * rightValue;
        break;
    case DIV:
        node->value = leftValue / rightValue;
        break;
    default:
        break;
    }
    return node;
}
/**
 * @brief two integers and returns a node with the result.
 * @param leftValue  The value of the left operand.
 * @param rightValue The value of the right operand.
 * @return A node with the result of the addition.
 */
Node* addNodeInt(int leftValue, int rightValue) {
    return typeNodeInt(ADD, leftValue, rightValue);
}

/**
 * @brief two integers and returns a node with the result.
 * @param leftValue  The value of the left operand.
 * @param rightValue The value of the right operand.
 * @return A node with the result of the subtraction.
 */
Node* subNodeInt(int leftValue, int rightValue) {
    return typeNodeInt(SUB, leftValue, rightValue);
}

/**
 * @brief two integers and returns a node with the result.
 * @param leftValue  The value of the left operand.
 * @param rightValue The value of the right operand.
 * @return A node with the result of the multiplication.
 */
Node* mulNodeInt(int leftValue, int rightValue) {
    return typeNodeInt(MUL, leftValue, rightValue);
}

/**
 * @brief two integers and returns a node with the result.
 * @param leftValue  The value of the left operand.
 * @param rightValue The value of the right operand.
 * @return A node with the result of the division.
 */
Node* divNodeInt(int leftValue, int rightValue) {
    return typeNodeInt(DIV, leftValue, rightValue);
}

/**
 * @brief a function pointer to a binary function that operates on two integer arguments and returns a node with the result.
 * @param type The type of the binary function to create.
 * @return A function pointer to a binary function that operates on two integer
 *         arguments and returns a node with the result.
 */
Node* (*makeFuncInt(TypeTag type))(int, int) {
    switch (type)
    {
    case ADD:
        return addNodeInt;
        break;
    case SUB:
        return subNodeInt;
        break;
    case MUL:
        return mulNodeInt;
        break;
    case DIV:
        return divNodeInt;
        break;
    default:
        break;
    }
    return NULL;
}

/**
 * @brief Adds two nodes and returns a node with the result.
 * @param leftNode  The left operand as a node.
 * @param rightNode The right operand as a node.
 * @return A node with the result of the addition.
 */
Node* addNodeNode(Node* leftNode, Node* rightNode) {
    return typeNodeInt(ADD, leftNode->value, rightNode->value);
}

/**
 * @brief Creates a new Node with type SUB and value equal to the subtraction of leftNode and rightNode values.
 *        If leftNode is NULL, returns a Node with value equal to the Fibonacci number of rightNode value.
 *        If rightNode is NULL, returns leftNode.
 * @param leftNode Pointer to the left Node.
 * @param rightNode Pointer to the right Node.
 * @return Pointer to a new Node with type SUB and value equal to the subtraction
 * of leftNode and rightNode values, or a new Node with value equal to the Fibonacci number of leftNode
 * value if leftNode is NULL.
 */
Node* subNodeNode(Node* leftNode, Node* rightNode) {
    if (leftNode == NULL) {
        return rightNode;
    }
    if (rightNode == NULL) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->value = fibonacci(-1 * leftNode->value);
        return node;
    }
    return typeNodeInt(SUB, leftNode->value, rightNode->value);
}
/**
 * @brief Creates a new Node with type MUL and value equal to the multiplication of leftNode and rightNode values.
 * @param leftNode Pointer to the left Node.
 * @param rightNode Pointer to the right Node.
 * @return Pointer to a new Node with type MUL and value equal to the multiplication
 * of leftNode and rightNode values.
 */
Node* mulNodeNode(Node* leftNode, Node* rightNode) {
    return typeNodeInt(MUL, leftNode->value, rightNode->value);
}

/**
 * @brief Creates a new Node with type DIV and value equal to the division of leftNode and rightNode values.
 * @param leftNode Pointer to the left Node.
 * @param rightNode Pointer to the right Node.
 * @return Pointer to a new Node with type DIV and value equal to the division
 * of leftNode and rightNode values.
 */
Node* divNodeNode(Node* leftNode, Node* rightNode) {
    return typeNodeInt(DIV, leftNode->value, rightNode->value);
}

/**
 * @brief Returns a function pointer to the corresponding Node function based on the given type.
 * @param type TypeTag representing the type of Node function to return.
 * @return Function pointer to the corresponding Node function based on the given type.
 */
Node* (*makeFuncNode(TypeTag type))(Node*, Node*) {
    switch (type)
    {
    case ADD:
        return addNodeNode;
        break;
    case SUB:
        return subNodeNode;
        break;
    case MUL:
        return mulNodeNode;
        break;
    case DIV:
        return divNodeNode;
        break;
    default:
        break;
    }
    return NULL;
}

/**
 * @brief Prints the value of the given Node to the console.
 * @param node Pointer to the Node to print the value of.
 */
void calc(Node* node) {
    printf("%i\n", node->value);
}



int main() {
    Node* add = (*makeFuncInt(ADD))(10, 6);
    Node* mul = (*makeFuncInt(MUL))(5, 4);
    Node* sub = (*makeFuncNode(SUB))(mul, add);
    Node* fibo = (*makeFuncNode(SUB))(sub, NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);
    return 0;
}