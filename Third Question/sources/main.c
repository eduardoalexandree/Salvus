#include <stdio.h>
#include "../headers/employees.h"

// Função que calcula o total da folha de pagamento.
float calculatePayroll(struct Node *head)
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

// Funcão responsável por limpar a memória alocada pelos nodes da lista encadea
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

  //* Funcao de cadastro de funcionários, (Ponteiro do head da lista encadeada, Tipo do contrato, salário, contratos assinados, horas trabalhadas, valor por hora trabalhada, horas extras);
  registerEmployee(&employeeList, "Joao", CONTRACT_CONTRACTED, 0, 0, 100, 50, 0);
  calculateTotalToReceive(&employeeList->employee);

  registerEmployee(&employeeList, "Marcela", CONTRACT_CLT, 3000, 10, 40, 100, 1);
  calculateTotalToReceive(&employeeList->employee);
  addBonus(&employeeList->employee, 200);

  registerEmployee(&employeeList, "Joaquimo", CONTRACT_CONTRACTED, 0, 12, 180, 30, 0);
  calculateTotalToReceive(&employeeList->employee);

  // Exibição de informações dos funcionários.
  struct Node *current = employeeList;
  while (current != NULL)
  {
    displayInformation(&current->employee);
    current = current->next;
  }
  // Cálculo e exibição do total da folha de pagamento.
  float totalPayroll = calculatePayroll(employeeList);
  printf("\nThe total payroll is: R$ %.2f\n", totalPayroll);

  // Já que alocamos memória para a lista precisamos liberar a memória alocada
  freeList(employeeList);
  return 0;
}
