#ifndef EMPLOYEES_H_INCLUDED
#define EMPLOYEES_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#define COMMISSION 200.00f
#define OVERTIME 20.0f
typedef enum
{
  CONTRACT_CONTRACTED,
  CONTRACT_CLT,
} ContractType;

struct OptionalData
{
  float hourlyRate;
  int hoursWorked;
  int contractsSigned;
  int salary;
  float bonus;
  int overtimeHours;
  float overtimeRate;
};

struct Employee
{
  char name[50];
  ContractType contractType;
  struct OptionalData optionalData;
  float totalToReceive;
};

struct Node
{
  struct Employee employee;
  struct Node *next;
};

void calculateTotalToReceive(struct Employee *employee);
void registerEmployee(struct Node **head, char name[], ContractType type, float salary, int contractsSigned, int hoursWorked, float hourlyRate, float overtimeHours);
void displayInformation(const struct Employee *employee);
void addBonus(struct Employee *employee, float bonus);
#endif
