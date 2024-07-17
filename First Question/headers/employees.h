#ifndef EMPLOYEES_H_INCLUDED
#define EMPLOYEES_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#define COMMISSION 200.00f

// Tipos de contrato
typedef enum
{
  CONTRACT_TERCEIRIZADO,
  CONTRACT_CLT,
} ContractType;

// informações opcionais por tipo de contrato
struct OptionalData
{
  float hourlyRate;
  int hoursWorked;
  int contractsSigned;
  int salary;
};

// struct para funcionarios
struct Employee
{
  char name[50];
  ContractType contractType;
  struct OptionalData optionalData;
  float totalToReceive;
};

// struct para criação da lista encadeada de funcionários
struct Node
{
  struct Employee employee;
  struct Node *next;
};

void calculateTotalReceive(struct Employee *employee);
void registerEmployee(struct Node **head, char name[], ContractType type, float salary, int contractsSigned, int hoursWorked, float hourlyRate);
void displayInformation(const struct Employee *employee);

#endif
