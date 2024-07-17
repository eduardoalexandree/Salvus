#include <stdio.h>
#include "../headers/employees.h"

// Função que calcula o total da folha de pagamento.
float calculatePayment(struct Node *head)
{
  struct Node *current = head;
  float total = 0.0;
  while (current != NULL)
  {
    total += current->employee.totalToReceive;
    current = current->next;
  }
  return total;
}

// Funcão responsável por limpar a memória alocada pelos nodes da lista encadea.
void freeList(struct Node *head)
{
  struct Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main()
{
  struct Node *employeeList = NULL; // Lista encadeada contendo os funcionários da empresa

  //* Funcao de cadastro de funcionários: (Endereço do head da lista encadeada, Nome, Tipo do contrato, Salário, Contratos assinados, Horas trabalhadas, Valor por hora trabalhada);
  registerEmployee(&employeeList, "Joao", CONTRACT_TERCEIRIZADO, 0, 0, 100, 50);
  calculateTotalReceive(&employeeList->employee);

  registerEmployee(&employeeList, "Marcela", CONTRACT_CLT, 3000, 10, 40, 100);
  calculateTotalReceive(&employeeList->employee);

  registerEmployee(&employeeList, "Joaquim", CONTRACT_TERCEIRIZADO, 0, 12, 180, 30);
  calculateTotalReceive(&employeeList->employee);

  // Exibição de informações dos funcionários.
  struct Node *current = employeeList;
  while (current != NULL)
  {
    displayInformation(&current->employee);
    current = current->next;
  }

  // Cálculo e exibição do total da folha de pagamento.
  float totalPayroll = calculatePayment(employeeList);
  printf("\nThe total payroll is: R$ %.2f\n", totalPayroll);

  // liberar memória da lista encadeada para evitar vazamento
  freeList(employeeList);
  return 0;
}
