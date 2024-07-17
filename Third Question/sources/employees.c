#include <stdio.h>
#include "../headers/employees.h"

// Função para calculo da folha salarial da empresa
void calculateTotalToReceive(struct Employee *employee)
{
  switch (employee->contractType)
  {
  case CONTRACT_CONTRACTED:
    employee->totalToReceive = employee->optionalData.hourlyRate * employee->optionalData.hoursWorked + employee->optionalData.contractsSigned * COMMISSION;
    break;
  case CONTRACT_CLT:
    employee->totalToReceive = employee->optionalData.salary + employee->optionalData.contractsSigned * COMMISSION + (employee->optionalData.overtimeHours * employee->optionalData.overtimeRate) + OVERTIME * employee->optionalData.overtimeHours; // Adiciona horas extras
    break;
  default:
    employee->totalToReceive = 0.0f;
    break;
  }
}

//* Funcao de cadastro de funcionários, (Ponteiro do head da lista encadeada, Tipo do contrato, salário, contratos assinados, horas trabalhadas, valor por hora trabalhada);
void registerEmployee(struct Node **head, char name[], ContractType type, float salary, int contractsSigned, int hoursWorked, float hourlyRate, float overtimeHours)
{
  struct Employee employee;
  strcpy(employee.name, name);
  employee.contractType = type;

  if (employee.contractType == CONTRACT_CONTRACTED)
  {
    employee.optionalData.hourlyRate = hourlyRate;
    employee.optionalData.hoursWorked = hoursWorked;
    employee.optionalData.contractsSigned = contractsSigned;
  }
  else if (employee.contractType == CONTRACT_CLT)
  {
    employee.optionalData.salary = salary;
    employee.optionalData.contractsSigned = contractsSigned;
    employee.optionalData.overtimeHours = overtimeHours;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->employee = employee;
  newNode->next = *head;
  *head = newNode;
}

// Função para exibir os dados dos funcionários
void displayInformation(const struct Employee *employee)
{
  printf("\nName: %s\n", employee->name);
  switch (employee->contractType)
  {
  case CONTRACT_CONTRACTED:
    printf("Contract: Contracted\n");
    printf("Hourly rate: R$ %.2f\n", employee->optionalData.hourlyRate);
    printf("Hours worked: %d\n", employee->optionalData.hoursWorked);
    break;
  case CONTRACT_CLT:
    printf("Contract: CLT\n");
    printf("Salary: %d\n", employee->optionalData.salary);
    printf("Contracts signed: %d\n", employee->optionalData.contractsSigned);
    printf("Commission per contract: R$ %.2f\n", COMMISSION);
    printf("Overtime hours: %d\n", employee->optionalData.overtimeHours);
    break;
  default:
    printf("Contract: Not defined\n");
    break;
  }
  printf("Total to receive: R$ %.2f\n", employee->totalToReceive);
}

void addBonus(struct Employee *employee, float bonus)
{
  employee->totalToReceive = employee->totalToReceive + bonus;
}
