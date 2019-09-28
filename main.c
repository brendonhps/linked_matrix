#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define FALSE 0
#define TRUE 1


void printMenu(){
            printf("\n\n-----------------MENU-----------------\n\n ");
            printf(" '1' Declarar uma Matriz\n ");
            printf(" '2' Inicializar uma matriz\n ");
            printf(" '3' Transpor uma Matriz\n ");
            printf(" '4' Somar duas Matrizes\n ");
            printf(" '5' Subtrair duas Matrizes\n ");
            printf(" '6' Multiplicar duas Matrizes\n ");
            printf(" '7' Imprimir a Diagonal Principal\n ");
            printf(" '8' Imprimir uma Matriz\n ");
            printf(" '9' Destruir uma Matriz\n ");
            printf(" 'i' Imprimir Lista Encadeada\n ");
            printf(" '0' para Sair do Programa\n ");
            
}

int main()
{

    int ch,   //Input Character
        rowD, //Dimension Rows
        colD, 
        systemStarted = FALSE,
        breakProgram = FALSE; //Dimension Cols

    char nameOfMatrix[20], 
         nameOfNewMatrix[20],
         nameOfSecMatrix[20];

    Matriz *newMatrix;
    struct Lista_Encadeada* node;

    // Root from Linked List
    struct Lista_Encadeada *root = NULL;

    printf("Ambiente de manipulacao de matrizes dinamicas de numeros reais, digite 'm' para exibir o menu novamente\n\n");

    printMenu();
    
    while ((ch = getchar()) && (breakProgram == FALSE))
    {
        switch (ch)
        {
        case('m'):
            printMenu();
            break;
        case ('1'):

            node = NULL;
            newMatrix = NULL;

            rowD = 0;
            colD = 0;

            printf("-----------------------------Declarando uma matriz-----------------------------\n\n");

            printf("Digite o nome da matriz (limite de 20 caracteres) \n\n");
            scanf("%s", nameOfMatrix);

            printf("Digite o numero de linhas\n\n");
            scanf("%d", &rowD);

            printf("Digite o numero de colunas\n\n");
            scanf("%d", &colD);

            newMatrix = createMatrix (nameOfMatrix, rowD, colD);

            // Verify if the list has started
            if (systemStarted) {
                node = createNode(newMatrix);
                root = addNodeOnList(root, node);
            }
            // Else, start the list with the root
            else {
                systemStarted = TRUE;
                root = createNode(newMatrix);
            }

            printMenu();
            break;


        case ('2'):

            rowD = 0;
            colD = 0;

            printf("-----------------------------Inicializando uma matriz-----------------------------\n\n");

            printf("Digite o nome da matriz (limite de 20 caracteres) \n");
            scanf("%s", nameOfMatrix);

            printf("Inicializando a matriz (%s)\n", nameOfMatrix);
            initMatrix(nameOfMatrix, root);

            printMenu();
            break;
        case ('3'):

            node = NULL;
            newMatrix = NULL;

            printf("-----------------------------Transpondo uma matriz-----------------------------\n\n");

            printf("Digite o nome da matriz que deseja transpor (limite de 20 caracteres) \n\n");
            scanf("%s", nameOfMatrix);

            printf("Digite o nome da nova matriz (limite de 20 caracteres) \n\n");

            scanf("%s", nameOfNewMatrix);
            
            newMatrix = createMatrixTransposed(nameOfNewMatrix,nameOfMatrix,root);

            node = createNode(newMatrix);
            root = addNodeOnList(root, node);

            printMenu();
            break;

        case ('4'): 

            node = NULL;
            newMatrix = NULL;
        
            printf("-----------------------------Soma de matrizes-----------------------------\n\n");

            printf("Digite o nome da primeira matriz que deseja somar \n\n");
            scanf("%s", nameOfMatrix);

            printf("OBS: A segunda matriz deve ter as mesmas dimensoes que a primeira matriz!");

            printf("Digite o nome da segunda matriz que deseja somar \n\n");
            scanf("%s", nameOfSecMatrix);

            printf("Digite o nome da nova matriz (limite de 20 caracteres) \n\n");
            scanf("%s", nameOfNewMatrix);

            newMatrix = sumMatrix(nameOfMatrix,nameOfSecMatrix,nameOfNewMatrix,root);

            node = createNode(newMatrix);
            root = addNodeOnList(root, node);

            break;
        case ('5'): 

            node = NULL;
            newMatrix = NULL;
        
            printf("-----------------------------Subtracao de matrizes-----------------------------\n\n");

            printf("Digite o nome da primeira matriz que deseja subtrair \n\n");
            scanf("%s", nameOfMatrix);

            printf("OBS: A segunda matriz deve ter as mesmas dimensoes que a primeira matriz!");

            printf("Digite o nome da segunda matriz que deseja subtrair \n\n");
            scanf("%s", nameOfSecMatrix);

            printf("Digite o nome da nova matriz (limite de 20 caracteres) \n\n");
            scanf("%s", nameOfNewMatrix);

            newMatrix = subMatrix(nameOfMatrix,nameOfSecMatrix,nameOfNewMatrix,root);

            node = createNode(newMatrix);
            root = addNodeOnList(root, node);
        
            break;
        case ('6'): 

            node = NULL;
            newMatrix = NULL;
        
            printf("-----------------------------Multiplicacao de matrizes-----------------------------\n\n");

            printf("Digite o nome da primeira matriz que deseja multiplicar \n\n");
            scanf("%s", nameOfMatrix);

            printf("OBS: A segunda matriz deve ter o numero de linhas igual ao numero de colunas da primeira matriz!");

            printf("Digite o nome da segunda matriz que deseja multiplicar\n\n");
            scanf("%s", nameOfSecMatrix);

            printf("Digite o nome da nova matriz (limite de 20 caracteres) \n\n");
            scanf("%s", nameOfNewMatrix);

            newMatrix = multMatrix(nameOfMatrix,nameOfSecMatrix,nameOfNewMatrix,root);

            node = createNode(newMatrix);
            root = addNodeOnList(root, node);

            break;
        case ('7'): 

            printf("-----------------------------Impressao da Diagonal principal -----------------------------\n\n");

            printf("Digite o nome da  matriz  \n\n");
            scanf("%s", nameOfMatrix);

            printDiagMatrix(nameOfMatrix, *root);
            printMenu();

            break;
        case ('8'): 
            printf("-----------------------------Imprimir uma matriz-----------------------------\n\n");

            printf("Digite o nome da matriz que deseja imprimir.\n\n");
            scanf("%s", nameOfMatrix);

            printMatrix(nameOfMatrix, *root);
            printMenu();

        break;
        case ('9'): 
            printf("-----------------------------Destruir uma Matriz -----------------------------\n\n");

            printf("Digite o nome da  matriz que deve ser destruida \n\n");
            scanf("%s", nameOfMatrix);

            node = root;
            node = searchMatrix(node, nameOfMatrix);
            root = removeNodeOnList(root, node);
            printMenu();
        break;

        case ('0'): 
            printf("-----------------------------Sair do programa -----------------------------\n\n");

            struct Lista_Encadeada* tmp;
            while(root != NULL) {
                tmp = root->prox;
                freeMemory(root);
                root = tmp;
            }

            free(newMatrix);

            printf("------Ate a proxima------\n\n");

            breakProgram = TRUE;
            
        break;
        
        case ('i'):
            printf("-----------------------------Imprimindo lista encadeada -----------------------------\n\n");
            printLinkedList(*root);
            printMenu();
        break;

        }

    }

return 0;
}