
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    double value;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, double value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

double pop(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Erro: Pilha vazia (expressão malformada)\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    double value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) pop(stack);
    free(stack);
}

double evaluateRPN(char* expression) {
    Stack* stack = createStack();
    char* token = strtok(expression, " ");

    while (token != NULL) {
        if (strlen(token) == 1 && strchr("+-*/%^", token[0])) {
            double val2 = pop(stack);
            double val1 = pop(stack);
            double result = 0.0;

            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        fprintf(stderr, "Erro: Divisão por zero\n");
                        freeStack(stack);
                        exit(EXIT_FAILURE);
                    }
                    result = val1 / val2;
                    break;
                case '%':
                    if (val2 == 0) {
                        fprintf(stderr, "Erro: Módulo por zero\n");
                        freeStack(stack);
                        exit(EXIT_FAILURE);
                    }
                    result = fmod(val1, val2);
                    break;
                case '^': result = pow(val1, val2); break;
            }
            push(stack, result);
        } else {
            char* endptr;
            double value = strtod(token, &endptr);
            if (*endptr != '\0') {
                fprintf(stderr, "Erro: Token inválido: '%s'\n", token);
                freeStack(stack);
                exit(EXIT_FAILURE);
            }
            push(stack, value);
        }
        token = strtok(NULL, " ");
    }

    if (stack->top == NULL || stack->top->next != NULL) {
        fprintf(stderr, "Erro: Expressão malformada (operandos/operadores em excesso)\n");
        freeStack(stack);
        exit(EXIT_FAILURE);
    }

    double finalResult = pop(stack);
    freeStack(stack);
    return finalResult;
}

int main() {
    char expression[256];
    printf("Digite a expressão em notação pós-fixa (RPN):\n> ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    double result = evaluateRPN(expression);
    printf("Resultado: %.2f\n", result);
    return 0;
}
