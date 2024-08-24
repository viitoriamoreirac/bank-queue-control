# Controle de fila bancária

Este programa foi construído por [Vitória Cabral](github.com/viitoriamoreirac) e [Emesson Michael](github.com/EmessonG) como forma de obtenção de nota na matéria de **Estrutura de Dados**, lecionada pela professora **Cledja Rolim** e simula um *sistema de atendimento bancário* que controla a fila de clientes e também traz informações sobre quantidade de clientes e tempo de atendimento.

#### Os requisitos para avaliação são:

1. Uso da linguagem C;
2. Uso de listas encadeadas e filas;
3. Mini tutorial explicando funcionamento;
4. Justificativa das estruturas utilizadas;
5. Modularidade de código, documentação, adequação e eficiência;

## Como rodar o projeto? 
#### Certifique-se de que o script run.sh tenha permissões de execução. Se não tiver, defina com o comando:
  ```bash
  chmod +x run.sh
  ```
#### Execute o script para compilar e rodar o programa:
  ```bash
  ./run.sh
  ```

## Funcionamento do programa

### Menu Principal
Quando o programa é iniciado, o menu principal é exibido com as seguintes opções:

1. Adicionar cliente na fila
2. Atender Cliente
3. Exibir clientes que estão na fila
4. Encerrar atendimento

#### 1 - Adicionar cliente na Fila
Esta opção chama a função adicionar_cliente() que permite que o usuário adicione um novo cliente à fila. O programa solicitará o nome do cliente e se ele é prioritário (opções 0 ou 1), após isso, é feita a chamada da função escolher_transacoes() que define o tempo necessário para o atendimento com base nas transações escolhidas. Além disso, será calculado o tempo na fila, a partir da soma do tempo total de todos os clientes que já estiverem na fila.

#### 2 - Atender Cliente
Esta opção chama a função atender_cliente() que remove o primeiro cliente da fila e exibe uma mensagem indicando qual cliente está sendo atendido. A função também chama atualizar_relatorio() para registrar o atendimento no relatório, incluindo o incremento no fluxo de clientes e o tempo total de atendimento.

#### 3 - Exibir Clientes Atendidos
Esta opção chama a função exibir_fila() que exibe todos os clientes que estão atualmente na fila. Mostra os detalhes de cada cliente, como nome, tempo na fila e se é prioritário.

#### 4 - Encerrar Atendimento
Esta opção chama a função atender_cliente() em um loop que atende todos os clientes restantes na fila até que ela fique vazia. Após todos os clientes serem atendidos, a função exibir_relatorio() é chamada para mostrar um resumo do atendimento, incluindo o número total de clientes atendidos, tempo total de atendimento, média de tempo de atendimento e quantidade de clientes prioritários.

## Estrutura do projeto

```bash
/bank-queue-control
├── /bin
│   └── executar         # Executável gerado após a compilação
├── /include             # Contém os headers para cada função nos arquivos de src
│   ├── cliente.h
│   ├── fila.h
│   ├── menu.h
│   ├── relatorio.h
│   └── transacoes.h
├── /src              
│   ├── cliente.c
│   ├── fila.c
│   ├── main.c
│   ├── menu.c
│   ├── relatorio.c
│   └── transacoes.c
├── LICENSE              
├── run.sh               # Script para automatizar a compilação e execução do programa
├── gitignore
└── README.md
```

### Estruturas utilizadas

1. Cliente: estrutura para armazenar nome, situação de prioridade e informações sobre o tempo de atendimento de cada cliente que passa pela fila, permitindo fácil gerenciamento e manipulação desses dados.

   ```c
   typedef struct cliente {
    char nome[50];
    int tempo_na_fila;
    int tempo_de_atendimento;
    int tempo_total;
    int prioritario;
    } Cliente;
   
2. Node: estrutura que armazena  um ponteiro para um cliente `Cliente* cliente` e um ponteiro para o próximo nó `struct node* next` facilitando a implementação da fila como lista encadeada.
   
   ```c
   
   typedef struct node {
    Cliente* cliente;
    struct node* next;
   } Node;
   
3. Fila: estrutura que representa e gerencia a fila, com dois ponteiros: `front` para o início da fila e `rear` para o fim da fila, facilitando a adição e remoção dos clientes.
   
   ```c
   typedef struct fila {
    Node* front;
    Node* rear;
   } Fila;
