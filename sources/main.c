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
  int numEmployees = 0;

  // Cadastro de funcionários.
  registerEmployee(&employeeList, "Eduardo Alexandre", CONTRACT_CLT, 5000.0, 2, 0, 0);
  calculateTotalToReceive(&employeeList->employee);

  registerEmployee(&employeeList, "Andresa", CONTRACT_CONTRACTED, 0, 5, 40, 100);
  calculateTotalToReceive(&employeeList->employee);

  registerEmployee(&employeeList, "Joao", CONTRACT_CLT, 2500, 4, 0, 0);
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
