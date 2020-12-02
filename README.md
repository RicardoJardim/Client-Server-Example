# Client-Server Example using C

Este projeto consiste num software criado em consola, que exemplifica a comunicação entre cliente - servidor utilizando o SO Linux e sockets. O exemplo baseia-se numa simulação de uma loja, em que o clientes entram na loja e podem comprar produtos ou não. O software esta repartido em 2 partes, o Monitor (cliente) e Servidor (server). O objetivo deste exemplo é mostrar a utilização de trincos para proteger as zonas criticas do sistema, a utilização de semáfores para criar um lista de espera permitindo cada processo aceder à zona pretendida e por fim, a utilização de Sockets para comunicação entre consolas. 

## Monitor
Este tem o objetivo de mostrar a informação recebida pela servidor, utilizando sockets. Ao iniciar mostra um menu com várias opções (tempo de simulação, entre outros) permitindo iniciar a simulação e parar quando o utilizador quiser.

## Servidor
Este é software principal da simulação, este através dos dados fornecidos pelo monitor e parametros iniciais definidos por um ficheiro, inicia a simulação. Sendo que cada tread é um cliente, o servidor é capaz de isolar as zonas criticas do sistema utilizando os trincos. Através da utilização de semáfores, um cliente so pode chegar a caixa quando não estiver nenhum cliente à sua frente, criando assim uma lista de espera. Visto que existe clientes com prioridade, existe sempre uma caixa disponivel apenas para clientes com prioridades e outra para clientes normais, caso esta estejas com muitos clientes, abre uma nova caixa.

## Estatisticas
Ao finalizar a simulação, e mostrado no monitor um conjunto de estatisticas como:
- Tempo total de simulação
- Total numero de clientes
- Numero de clientes prioritários
- Numero de clientes normais
- Produtos comprados 
  - Produto x comprado y vezes
- Numero de desistências 
- Tempo medio de espera para clientes normais e prioritários
