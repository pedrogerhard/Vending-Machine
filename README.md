# Máquina de Vendas Gerhard

Simulador de máquina de vendas em C para terminal, com sistema de inserção de notas monetárias e seleção de produtos. Desenvolvido para Windows.

## Funcionalidades Principais

- **Interface Simples:**
  - Lista de produtos com preços e estoque
  - Saldo atualizado em tempo real
- **Sistema de Pagamento:**
  - Inserção de notas (R$2, R$5, R$10, R$20, R$50, R$100)
  - Débito automático no saldo
- **Controle de Estoque:**
  - Atualização automática do estoque após cada compra
  - Impede compras com estoque insuficiente
- **Navegação:**
  - Menu numérico para seleção
  - Opção de saída a qualquer momento

## Estrutura do Código

### Struct Produto
```c
typedef struct {
    char name[20];
    float preco; 
    int estoque;
} Produto;
