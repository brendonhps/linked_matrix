#ifndef __UTILS__

#define __UTILS__

typedef struct MB {

    char nome_matriz[20]; // name of matrix
    float **M;  // ref matrix
    int totalL, totalC; // dimension of matrix
}Matriz; 


typedef struct Lista_Encadeada {
    Matriz MD;
    struct Lista_Encadeada *prox;
}ListaLinear;

// Create a node (new Lista_Encadeada)
struct Lista_Encadeada* createNode ();

// Insert a node in a linked list
struct Lista_Encadeada* addNodeOnList(struct Lista_Encadeada *root, struct Lista_Encadeada * nodeToAdd);

// Remove a node in a linked list
struct Lista_Encadeada* removeNodeOnList(struct Lista_Encadeada *root, struct Lista_Encadeada * nodeToRem);

// Print a linked list
void printLinkedList(struct Lista_Encadeada root);

// Free memory from a node
void freeMemory(struct Lista_Encadeada *node);

// Create a New Matrix with 0's
struct MB* createMatrix (char nameOfMatrix[20], int rowD, int colD);

struct Lista_Encadeada* searchMatrix(struct Lista_Encadeada *head, char nameOfElement[20]);

// Initiate a Matrix with the user input
void initMatrix (char nameOfMatrix[20], ListaLinear *root);

// Create a New Matrix transposed 
struct MB *createMatrixTransposed (char nameOfMatrix[20],char oldNameOfMatrix[20], struct Lista_Encadeada *root);

// Sum of Matrix 
struct MB *sumMatrix(char nameOfMatrix[20],char nameOfSecMatrix[20],char nameOfNewMatrix[20], struct Lista_Encadeada *root);

// Sub of Matrix 
struct MB *subMatrix(char nameOfMatrix[20],char nameOfSecMatrix[20],char nameOfNewMatrix[20], struct Lista_Encadeada *root);

// Mult of Matrix 
struct MB * multMatrix(char nameOfMatrix[20],char nameOfSecMatrix[20],char nameOfNewMatrix[20], struct Lista_Encadeada *root);

// Print main diagonal of the matrix
void printDiagMatrix(char nameOfMatrix[20],struct Lista_Encadeada root);

// Print matrix
void printMatrix( char nameOfMatrix [20],struct Lista_Encadeada root);

#endif