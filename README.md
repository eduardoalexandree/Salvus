# Salvus
Salvus Tenical Test

@Author Eduardo Alexandre

## Estrutura do Projeto

O projeto está dividido em vários arquivos principais:

- `main.c`: O ponto de entrada do programa onde a lógica principal é executada.
- `employees.c` e `employees.h`: Contêm a implementação das funções relacionadas aos funcionários e a definição das estruturas de dados.

## Funções e Parâmetros

### `void calculateTotalReceive(struct Employee *employee);`

Calcula o total a receber de um funcionário com base em seu tipo de contrato e outros parâmetros.

- `employee`: Ponteiro para a estrutura `Employee` que contém os dados do funcionário.

- Nesta função, será verificado o tipo de contrato do funcionário, passando por um `case`. Após a verificação, será calculado o valor do salário. Para funcionários terceirizados, o valor final será (`valor_por_hora` * `horas_trabalhadas`) + (`comissao` * `contratos_assinados`). Já para funcionários CLT, o valor será `salario` + (`comissao` * `contratos_assinados`).

### `void registerEmployee(struct Node **head, char name[], ContractType type, float salary, int signedContracts, int workedHours, float hourlyRate);`

Cadastra um novo funcionário na lista encadeada.

- `head`: Ponteiro para o ponteiro do head da lista encadeada.
- `name`: Nome do funcionário.
- `ContractType`: Tipo de contrato do funcionário (CLT ou Terceirizado).
- `salary`: Salário do funcionário (aplicável para CLT).
- `signedContracts`: Número de contratos assinados pelo funcionário.
- `workedHours`: Número de horas trabalhadas pelo funcionário (aplicável para Terceirizado).
- `hourlyRate`: Valor pago por hora trabalhada (aplicável para Terceirizado).

-  Nesta função, é criado um novo funcionário com os dados fornecidos. Primeiro, os dados são armazenados em uma estrutura `Funcionario` que é inicializada com os valores passados como parâmetros. Se o tipo de contrato for Terceirizado, os campos `hourlyRate`, `workedHours` e `signedContracts` são configurados. Caso o contrato seja CLT, o campo `salary` e `signedContracts` são configurados. Em seguida, um novo nó da lista encadeada é alocado e preenchido com os dados do funcionário. Este nó é então inserido no início da lista, atualizando o ponteiro `head` para apontar para o novo nó.


### `void displayInformation(const struct Employee *employee);`

Exibe as informações detalhadas de um funcionário.

- `employee`: Ponteiro para a estrutura `Employee` contendo os dados do funcionário.

- Essa função possibilidade exibir os dados de um funcionário presente da lista encadeada de funcionários criada na `main.c`.

### `float calculatePayment(struct Node *head);`

Calcula o total da folha de pagamento com base na lista de funcionários.

- `head`: Ponteiro para o início da lista encadeada de funcionários.

- Essa função percorre toda a lista de funcionários somando os valores dos salários e retornando o valor final.

### `void freeList(struct Node *head);`

Libera a memória alocada para a lista encadeada de funcionários.

- `head`: Ponteiro para o início da lista encadeada de funcionários.

- Essa função percorre toda a lista de funcionário apontando todos os nós para NULL, evitando assim vazamento de memória ou outros problemas causados
  pela alocaçào de memória.

## Estruturas de Dados

### `struct Employee`

Struct contendo as informações do funcionário:

- `name`: Nome do funcionário.
- `contractType`: Tipo de contrato (CLT ou Terceirizado).
- `optionalData`: Dados opcionais, incluindo salário, valor por hora, horas trabalhadas e contratos assinados.
- `totalToReceive`: Total a receber pelo funcionário.


### `struct Optional`

Struct contendo as informações opcionais para cada tipo de de contrato

- `hourlyRate`: Valor pago por hora trabalhada.
- `hoursWorked`: Número de horas trabalhadas pelo funcionário
- `contractsSigned`: Contratos assinados.
- `salary` : Salário do funcionário
  
### `struct Node`

Representa um nó na lista encadeada de funcionários:

- `employee`: Estrutura `Employee` contendo os dados do funcionário.
- `next`: Ponteiro para o próximo nó na lista.
  
## Modificações futuras

- `Verificação dos dados`: Criar rotinas dentros das funções para verificar a integridade dos dados que estão sendo passado na função, como por exemplo verificação de valores negativos, nomes em formatação correta e etc.

- `Modificação na Lista Encadeada`: No código foi utilizada uma lista encadeada para a inserção de funcionários. Inicialmente, cogitei utilizar um array de struct `employee` para ter maior controle das posições e, com isso, acessar mais facilmente um funcionário pela posição. Entretanto, isso exigiria definir um tamanho fixo para o array, o que poderia causar um uso inadequado de alocação de memória no código. Por isso, optei pela utilização de uma lista encadeada. A lista encadeada não permite acessar um usuário pela posição dele dentro da lista sem percorrê-la inicialmente, mas oferece maior flexibilidade na alocação dinâmica de memória, evitando desperdícios. Caso a empresa tenha realmente um valor fixo de funcionários na empresa, seria possível aplicar o array onde cada posição definiria o ID do usuário, facilitando assim a busca do mesmo.

## Como Executar

Para rodar o projeto, siga estes passos:

1. **Compile o código**:

   Dentro da pasta sources compile o código utilizando o comando:
   ```sh
   gcc -I../headers main.c ../sources/employees.c -o main
2. **Execute**:
  ```sh
     ./main

