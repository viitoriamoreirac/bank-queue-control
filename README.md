# Controle de fila bancária

O programa simula um sistema de atendimento bancário. Aqui está um guia detalhado sobre como cada parte do programa funciona:

Menu Principal
Quando o programa é iniciado, o menu principal é exibido com as seguintes opções:

1 - Adicionar cliente na fila
2 - Atender Cliente
3 - Exibir clientes que estão na fila
4 - Encerrar atendimento

### Adicionar Cliente na Fila

Função: adicionar_cliente()
Descrição: Permite que o usuário adicione um novo cliente à fila. O programa solicitará o nome do cliente e se ele é prioritário (opções 0 ou 1).
Nome do Cliente: O nome é solicitado através do terminal e é armazenado no cliente.
Prioridade: O usuário deve inserir 0 para clientes não prioritários ou 1 para clientes prioritários. Clientes prioritários serão adicionados no início da fila e outros terão a prioridade normal.
Tempo de Atendimento: Determinado pela função escolher_transacoes(), que define o tempo necessário para o atendimento com base nas transações escolhidas.
Tempo na Fila: Calculado com base no tempo total de atendimento dos clientes anteriores ou definido como 0 para clientes prioritários.
Atender Cliente

### Função: atender_cliente()
Descrição: Remove o primeiro cliente da fila e exibe uma mensagem indicando qual cliente está sendo atendido. A função também chama atualizar_relatorio() para registrar o atendimento no relatório, incluindo o incremento no fluxo de clientes e o tempo total de atendimento.
Exibir Clientes Atendidos

### Função: exibir_fila()
Descrição: Exibe todos os clientes que estão atualmente na fila. Mostra os detalhes de cada cliente, como nome, tempo na fila e se é prioritário.
Encerrar Atendimento

### Função: Combina atender_cliente() em um loop
Descrição: Atende todos os clientes restantes na fila até que ela fique vazia. Após todos os clientes serem atendidos, a função exibir_relatorio() é chamada para mostrar um resumo do atendimento, incluindo o número total de clientes atendidos, tempo total de atendimento, e quantidade de clientes prioritários.


- organizar readme
  - explicar uso de estruturas
  - explicar funcionamento do programa
  - adicionar seção `como rodar? `
