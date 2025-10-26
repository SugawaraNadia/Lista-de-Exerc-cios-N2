#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
} Data;

typedef struct {
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    Data aniversario;
} Contato;

struct elemento {
    Contato info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

// Funções da agenda
Elemento* cria_agenda();
Elemento* insere_contato(Elemento* lista);
void lista_contatos(Elemento* lista);
Elemento* busca_contato(Elemento* lista, char* nome);
Elemento* remove_contato(Elemento* lista, char* nome);
void atualiza_contato(Elemento* lista, char* nome);
void libera_agenda(Elemento* lista);

int main() {
    Elemento* agenda = cria_agenda();
    int opcao;
    char nomeBusca[41];

    do {
        printf("\n===== MENU AGENDA TELEFÔNICA =====\n");
        printf("1 - Inserir Contato\n");
        printf("2 - Listar Contatos\n");
        printf("3 - Buscar Contato\n");
        printf("4 - Editar Contato\n");
        printf("5 - Remover Contato\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                agenda = insere_contato(agenda);
                break;
            case 2:
                lista_contatos(agenda);
                break;
            case 3:
                printf("Digite o nome do contato: ");
                fgets(nomeBusca, 41, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0;
                {
                    Elemento* encontrado = busca_contato(agenda, nomeBusca);
                    if (encontrado != NULL) {
                        Contato c = encontrado->info;
                        printf("\nContato encontrado:\n");
                        printf("Nome: %s\nTelefone: %s\nCelular: %s\nEmail: %s\nAniversário: %02d/%02d\n",
                               c.nome, c.telefone, c.celular, c.email, c.aniversario.dia, c.aniversario.mes);
                    } else {
                        printf("Contato não encontrado.\n");
                    }
                }
                break;
            case 4:
                printf("Digite o nome do contato que deseja editar: ");
                fgets(nomeBusca, 41, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0;
                atualiza_contato(agenda, nomeBusca);
                break;
            case 5:
                printf("Digite o nome do contato que deseja remover: ");
                fgets(nomeBusca, 41, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0;
                agenda = remove_contato(agenda, nomeBusca);
                break;
            case 6:
                libera_agenda(agenda);
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

// Função para criar uma nova agenda (lista vazia)
Elemento* cria_agenda() {
    return NULL;
}

// Inserir um novo contato no final da lista
Elemento* insere_contato(Elemento* lista) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        return lista;
    }

    printf("Nome: ");
    fgets(novo->info.nome, 41, stdin);
    novo->info.nome[strcspn(novo->info.nome, "\n")] = 0;

    printf("Telefone: ");
    fgets(novo->info.telefone, 16, stdin);
    novo->info.telefone[strcspn(novo->info.telefone, "\n")] = 0;

    printf("Celular: ");
    fgets(novo->info.celular, 16, stdin);
    novo->info.celular[strcspn(novo->info.celular, "\n")] = 0;

    printf("Email: ");
    fgets(novo->info.email, 41, stdin);
    novo->info.email[strcspn(novo->info.email, "\n")] = 0;

    printf("Dia de aniversário: ");
    scanf("%d", &novo->info.aniversario.dia);
    printf("Mês de aniversário: ");
    scanf("%d", &novo->info.aniversario.mes);
    getchar(); // limpar buffer

    novo->prox = NULL;

    if (lista == NULL)
        return novo;

    Elemento* p = lista;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = novo;
    printf("Contato adicionado com sucesso!\n");
    return lista;
}

// Exibir todos os contatos
void lista_contatos(Elemento* lista) {
    if (lista == NULL) {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE CONTATOS ---\n");
    Elemento* p = lista;
    while (p != NULL) {
        printf("Nome: %s\nTelefone: %s\nCelular: %s\nEmail: %s\nAniversário: %02d/%02d\n\n",
               p->info.nome, p->info.telefone, p->info.celular,
               p->info.email, p->info.aniversario.dia, p->info.aniversario.mes);
        p = p->prox;
    }
}

// Buscar contato por nome
Elemento* busca_contato(Elemento* lista, char* nome) {
    Elemento* p = lista;
    while (p != NULL) {
        if (strcmp(p->info.nome, nome) == 0)
            return p;
        p = p->prox;
    }
    return NULL;
}

// Remover contato da lista
Elemento* remove_contato(Elemento* lista, char* nome) {
    Elemento *ant = NULL, *atual = lista;

    while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato não encontrado.\n");
        return lista;
    }

    if (ant == NULL)
        lista = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);
    printf("Contato removido com sucesso!\n");
    return lista;
}

// Atualizar informações de um contato
void atualiza_contato(Elemento* lista, char* nome) {
    Elemento* p = busca_contato(lista, nome);
    if (p == NULL) {
        printf("Contato não encontrado.\n");
        return;
    }

    printf("Editar contato '%s':\n", p->info.nome);

    printf("Novo telefone: ");
    fgets(p->info.telefone, 16, stdin);
    p->info.telefone[strcspn(p->info.telefone, "\n")] = 0;

    printf("Novo celular: ");
    fgets(p->info.celular, 16, stdin);
    p->info.celular[strcspn(p->info.celular, "\n")] = 0;

    printf("Novo email: ");
    fgets(p->info.email, 41, stdin);
    p->info.email[strcspn(p->info.email, "\n")] = 0;

    printf("Novo dia de aniversário: ");
    scanf("%d", &p->info.aniversario.dia);
    printf("Novo mês de aniversário: ");
    scanf("%d", &p->info.aniversario.mes);
    getchar();

    printf("Contato atualizado com sucesso!\n");
}

// Liberar memória da lista
void libera_agenda(Elemento* lista) {
    Elemento* p = lista;
    while (p != NULL) {
        Elemento* temp = p->prox;
        free(p);
        p = temp;
    }
}
