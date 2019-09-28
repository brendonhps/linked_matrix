#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Create a node (new Lista_Encadeada)
struct Lista_Encadeada* createNode (Matriz *mat) {
    struct Lista_Encadeada *p = NULL;
    
    printf("Creating a new node \n");
    p = (struct Lista_Encadeada*) malloc(sizeof(Matriz) + sizeof(struct Lista_Encadeada*));

    if ( p == NULL) {
        printf("Error creating a new node. \n");
        exit(0);
    }

    p->MD = *mat;
    p->prox = NULL;
    printf("Name of the matrix of the new node is (%s)\n", p->MD.nome_matriz);
    return p;
}

// Insert a node in a linked list
struct Lista_Encadeada* addNodeOnList(struct Lista_Encadeada *root, struct Lista_Encadeada * nodeToAdd) {

    printf("Adding new node on the list \n");
    
    struct Lista_Encadeada * cursor = root;

    printf("(%s)-->", cursor->MD.nome_matriz);

    while(cursor->prox != NULL) {
        printf("(%s)-->", cursor->prox->MD.nome_matriz);
        cursor = cursor->prox;
    }

    cursor->prox = nodeToAdd;

    printf("(%s)\n",cursor->prox->MD.nome_matriz);

    return root;
}


// Remove a node in a linked list
struct Lista_Encadeada* removeNodeOnList(struct Lista_Encadeada *root, struct Lista_Encadeada * nodeToRem) {

    printf("Removing a node on the list \n");
    
    struct Lista_Encadeada * cursor = root;

    while((cursor->prox != NULL) && (strcmp(cursor->prox->MD.nome_matriz, nodeToRem->MD.nome_matriz) != 0)) {
        cursor = cursor->prox;
    }
    if (cursor->prox == NULL) {
        printf("Matriz does not exist\n");
        exit(0);
    }
    else {
        struct Lista_Encadeada * tmp = cursor->prox;
        cursor->prox = tmp->prox;
        tmp->prox = NULL;
        freeMemory(tmp);
    }

    return root;
}

void printLinkedList(struct Lista_Encadeada root) {

    ListaLinear *aux = &root;

    printf("\n\n");

    while (aux->prox != NULL) {
       printf("(%s)-->", aux->MD.nome_matriz);
       aux = aux->prox;
    }
    printf("(%s)", aux->MD.nome_matriz);
}


// Free memory from a node
void freeMemory(struct Lista_Encadeada *node) {

    for (int i = 0; i < node->MD.totalL; ++i) {
        free(node->MD.M[i]);
    }
    free(node->MD.M);
    free(node);
}

// Create a New Matrix 
struct MB *createMatrix(char nameOfMatrix[20], int rowD, int colD)
{

    Matriz *p = NULL;

    p = (struct MB *)malloc(sizeof(struct MB));

    p->totalL = rowD;
    p->totalC = colD;

    for (int i = 0; i < 20; ++i)
    {
        p->nome_matriz[i] = nameOfMatrix[i];
    }

    printf("Matrix (%s) created with (%d) rows and (%d) cols\n", p->nome_matriz, p->totalL,p->totalC );

    return p;
}

// Search the matrix in the linked list
struct Lista_Encadeada* searchMatrix(struct Lista_Encadeada *head, char nameOfElement[20]) {

    while (head != NULL) {
        if(strcmp(nameOfElement,head->MD.nome_matriz) == 0) {
            break;
        }
        head = head->prox;
    }
    if (head == NULL) {
        return NULL;
    }
    else {
        return head;
    }

}
// Initializate the matrix
void initMatrix(char nameOfMatrix[20], struct Lista_Encadeada *root)
{

    struct Lista_Encadeada * cursor = root;

    
    cursor = searchMatrix(cursor, nameOfMatrix);

    if (cursor == NULL) {
        printf("Matrix does not exist");
        exit(0);
    }
    cursor->MD.M = (float **)malloc(sizeof(float *) * cursor->MD.totalL);
    
    for (int i = 0; i < cursor->MD.totalL; ++i)
    {
        
        cursor->MD.M[i] = (float *)malloc(sizeof(float) * cursor->MD.totalC);
        printf("Insert the values of the row (%d) of matrix\n", i);
        for (int j = 0; j < cursor->MD.totalC; ++j)
        {
     
            scanf("%f", &cursor->MD.M[i][j]);
        }
    }

    printf("Initialization conclude \n");

}
// Create matrix transposed
struct MB *createMatrixTransposed(char nameOfMatrix[20], char oldNameOfMatrix[20], struct Lista_Encadeada *root)
{
    struct Lista_Encadeada * cursor = root;

    cursor = searchMatrix(cursor, oldNameOfMatrix);

    if (cursor == NULL) {
        printf("Matrix does not exist");
        exit(0);
    }

    Matriz *newMatrix = createMatrix (nameOfMatrix, cursor->MD.totalC, cursor->MD.totalL);

    newMatrix->M = (float**) malloc ( sizeof(float *) * cursor->MD.totalC);
    for (int i = 0; i < cursor->MD.totalC ; ++i) {
        newMatrix->M[i] = (float *)malloc(sizeof(float) * cursor->MD.totalL);
        for (int j = 0; j < cursor->MD.totalL ; ++j) {
            newMatrix->M[i][j] = cursor->MD.M[j][i];
        }
    }

    return newMatrix;

}

struct MB *sumMatrix(char nameOfMatrix[20],char nameOfSecMatrix[20],char nameOfNewMatrix[20], struct Lista_Encadeada *root) {

    struct Lista_Encadeada * cursorM1 = root;
    struct Lista_Encadeada * cursorM2 = root;

    cursorM1 = searchMatrix(cursorM1, nameOfMatrix);
    cursorM2 = searchMatrix(cursorM2, nameOfSecMatrix);

    if ((cursorM1 == NULL) ||(cursorM2 == NULL)) {
        printf("Some Matrix does not exist");
        exit(0);
    }

    if ((cursorM1->MD.totalL != cursorM2->MD.totalL) || (cursorM1->MD.totalC != cursorM2->MD.totalC)) {
        printf("Number of Rows and Cols aren't equal\n");
        exit(0);
    }

    Matriz *newMatrix = createMatrix (nameOfNewMatrix, cursorM1->MD.totalL, cursorM1->MD.totalC);

    newMatrix->M = (float**) malloc ( sizeof(float *) * cursorM1->MD.totalL);
    for (int i = 0; i < cursorM1->MD.totalL ; ++i) {
        newMatrix->M[i] = (float *)malloc(sizeof(float) * cursorM1->MD.totalC);
        for (int j = 0; j < cursorM1->MD.totalC ; ++j) {
            newMatrix->M[i][j] = cursorM1->MD.M[i][j] + cursorM2->MD.M[i][j];
        }
    }

    return newMatrix;
}

struct MB *subMatrix(char nameOfMatrix[20],char nameOfSecMatrix[20],char nameOfNewMatrix[20], struct Lista_Encadeada *root) {

    struct Lista_Encadeada * cursorM1 = root;
    struct Lista_Encadeada * cursorM2 = root;

    cursorM1 = searchMatrix(cursorM1, nameOfMatrix);
    cursorM2 = searchMatrix(cursorM2, nameOfSecMatrix);

    if ((cursorM1 == NULL) ||(cursorM2 == NULL)) {
        printf("Some Matrix does not exist");
        exit(0);
    }

        if ((cursorM1->MD.totalL != cursorM2->MD.totalL) || (cursorM1->MD.totalC != cursorM2->MD.totalC)) {
        printf("Number of Rows and Cols aren't equal\n");
        exit(0);
    }

    Matriz *newMatrix = createMatrix (nameOfNewMatrix, cursorM1->MD.totalL, cursorM1->MD.totalC);

    newMatrix->M = (float**) malloc ( sizeof(float *) * cursorM1->MD.totalL);
    for (int i = 0; i < cursorM1->MD.totalL ; ++i) {
        newMatrix->M[i] = (float *)malloc(sizeof(float) * cursorM1->MD.totalC);
        for (int j = 0; j < cursorM1->MD.totalC ; ++j) {
            newMatrix->M[i][j] = cursorM1->MD.M[i][j] - cursorM2->MD.M[i][j];
        }
    }

    return newMatrix;
}

struct MB *multMatrix(char nameOfMatrix[20],char nameOfSecMatrix[20],char nameOfNewMatrix[20], struct Lista_Encadeada *root) {

    struct Lista_Encadeada * cursorM1 = root;
    struct Lista_Encadeada * cursorM2 = root;

    cursorM1 = searchMatrix(cursorM1, nameOfMatrix);
    cursorM2 = searchMatrix(cursorM2, nameOfSecMatrix);

    if ((cursorM1 == NULL) ||(cursorM2 == NULL)) {
        printf("Some Matrix does not exist");
        exit(0);
    }

    if (cursorM1->MD.totalC != cursorM2->MD.totalL) {
        printf("Number of A.Cols and B.Rows aren't equal\n");
        exit(0);
    }

    Matriz *newMatrix = createMatrix (nameOfNewMatrix, cursorM1->MD.totalL, cursorM1->MD.totalC);

    newMatrix->M = (float**) malloc ( sizeof(float *) * cursorM1->MD.totalL);
    for (int i = 0; i < cursorM1->MD.totalL; i++) {
        newMatrix->M[i] = (float *)malloc(sizeof(float) * cursorM1->MD.totalC);
        for (int j = 0 ; j < cursorM2->MD.totalC; j++) {
            newMatrix->M[i][j] = 0;
            for (int k = 0; k < cursorM1->MD.totalL; k++) {
                newMatrix->M[i][j] += cursorM1->MD.M[i][k]* cursorM2->MD.M[k][j];
            }
        }
    }

    return newMatrix;
}

void printDiagMatrix(char nameOfMatrix[20],struct Lista_Encadeada root) {

    ListaLinear *aux = &root;

    printf("A diagonal principal eh :\n [Linha] [Coluna] = Valor\n");

    while (aux != NULL) {
        if(strcmp(nameOfMatrix,aux->MD.nome_matriz) == 0) {
            break;
        }
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("This matrix does not exist\n");
        exit(0);
    }

    for (int i = 0; i < aux->MD.totalC ; ++i) {
        printf("[%d] [%d]  = %f\t \n", i,i, aux->MD.M[i][i]);  
        
    }

}

void printMatrix( char nameOfMatrix [20],struct Lista_Encadeada root) {

    ListaLinear *aux = &root;

    printf("\n\n");

    while (aux != NULL) {
        if(strcmp(nameOfMatrix,aux->MD.nome_matriz) == 0) {
            break;
        }
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("This matrix does not exist\n");
        exit(0);
    }

    for (int i = 0; i < aux->MD.totalC ; ++i) {
        for (int j = 0; j < aux->MD.totalL ; ++j) {
            printf("%f\t ", aux->MD.M[i][j]);  
        }
        printf("\n");
    }
}
