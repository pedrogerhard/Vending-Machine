#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    float preco;
    int estoque;
} Produto;

void inserirSaldo(float *saldo)
{
    float notas[] = {2.0f, 5.0f, 10.0f, 20.0f, 50.0f, 100.0f};
    int quantidade_de_notas = sizeof(notas) / sizeof(float);

    for (int i = 0; i < quantidade_de_notas; i++)
    {
        printf("%d. RS%.2f\n", i + 1, notas[i]);
    }
    printf("Escolha uma nota para inserir (0 para sair): ");

    int escolha;
    scanf("%d", &escolha);

    if (escolha == 0)
    {
        return;
    }
    else if (escolha >= 1 && escolha <= quantidade_de_notas)
    {
        *saldo += notas[escolha - 1];
    }
    else
    {
        printf("Opcao invalida!\n");
    }
}

void exibirProdutos(Produto *maquina[], int tamanho, float saldo)
{
    system("cls");
    printf("=== Maquina de vendas Gerhard ===\n");
    printf("Saldo R$%2.f\n\n",saldo);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d. %s\t- R$%.2f (Em estoque: %d)\n",
            i + 1, maquina[i]->name, maquina[i]->preco, maquina[i]->estoque);
    }
    printf("\n0. Sair\n");
}

void vender(Produto* produto, float* saldo){
    produto->estoque--;
    *saldo -= produto->preco;
}

int main()
{
    Produto itens[] = {
        {"Refrigerante", 6.0, 10},
        {"Chocolate", 4.0, 20},
        {"Salgadinho", 5.0, 10},
        {"Bolacha", 4.5, 5},
        {"Biz  ", 5.0, 15}};
    const int PRODUTOS_QTD = sizeof(itens) / sizeof(Produto);

    Produto *maquina[PRODUTOS_QTD];
    for (int i = 0; i < PRODUTOS_QTD; i++)
    {
        maquina[i] = &itens[i];
    }

    float saldo = 0.0f;

    int opcao = -1;
    while (opcao != 0)
    {
        system("cls");
        inserirSaldo(&saldo);

        exibirProdutos(maquina, PRODUTOS_QTD, saldo);

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            break;
        } else if (opcao >= 1 && opcao <= PRODUTOS_QTD)
        {
            vender(maquina[opcao - 1], &saldo);
        }
    }

    printf("Programa encerrado!\n");

    return 0;
}