#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Patient
{
    char name[50];
    int age;
    int date;
    float heart_rate;
    float systolic_rate;
    float diastolic_rate;
} Patient;

typedef struct Node
{
    Patient info;
    struct Node *next;
} Node;

void enterPatientInfo(Patient *patient)
{
    getchar(); 
    printf("The Patient's Name: ");
    gets(patient->name);
    
    printf("The Patient's Age: ");
    scanf("%d", &patient->age);
    
    printf("Date: ");
    scanf("%d", &patient->date);
    
    printf("Heart Rate: ");
    scanf("%f", &patient->heart_rate);
    
	printf("Systolic Rate: ");
    scanf("%f", &patient->systolic_rate);
    
    printf("Diastolic Rate: ");
	scanf("%lf", &patient->diastolic_rate);
    printf("\n");
}

void showInfo(Patient patient)
{
    printf("The Patient's Name: %s \n", patient.name);
    
    printf("The Patient's Age: %d \n", patient.age);
    
	printf("Date: %d\n", patient.date);
    
	printf("Heart Rate: %.1f \n", patient.heart_rate);
    
	printf("Systolic Rate: %.1f \n", patient.systolic_rate);
    
	printf("Diastolic Rate: %.1f \n", patient.diastolic_rate);
    printf("\n");
}

void addHead(Node **head, Patient info)
{
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    newNode->info = info;
    newNode->next = *head;
    *head = newNode;
}

void enterList(Node **head)
{
    int i;
    Patient info;
    printf("Input data in a week\n");
    for (i = 0; i < 7; i++)
    {
        printf("Enter info for patient in day %d of the week\n", i + 1);
        enterPatientInfo(&info);
        addHead(head, info);
    }
}

void showList(Node *head)
{
    printf("List 7 days(Week)\n");
    Node *tmp = head;
    for (; tmp != NULL; tmp = tmp->next)
    {
        showInfo(tmp->info);
    }
}

void sort(Node **head)
{
    Node *p, *q;
    Patient info;
    for (p = *head; p->next != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->info.heart_rate < q->info.heart_rate)
            {
                info = p->info;
                p->info = q->info;
                q->info = info;
            }
        }
    }
}

void enterInfoArray(Patient info[])
{
    printf("Input data in a month\n");
    int i;
    for (i = 0; i < 30; i++)
    {
        printf("Enter info for patient in day %d of the month\n", i + 1);
        enterPatientInfo(&info[i]);
    }
}

void showInfoArray(Patient info[])
{
    int i;
    printf("The month for patient info\n");
    for (i = 0; i < 30; i++)
    {
        showInfo(info[i]);
    }
}

int main()
{
    Node *list = NULL;
    Patient array[30];
    
    //Choice option
    int option;
    while (1 > 0) 
    {
        printf("Option: \n");
      printf("==============================\n");
      printf(  "1. Input data in a month\n"
               "2. Show array of patient info\n"
               "3. Input data in a week\n"
               "4. Show list of patient info\n"
               "5. Sort list of patient info\n"
               "0. Quit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:	
            enterInfoArray(array);
            break;
            
        case 2:
            showInfoArray(array);
            break;
            
        case 3:
            list = NULL;
            enterList(&list);
            break;
            
        case 4:
            showList(list);
            break;
            
        case 5:
            sort(&list);
            printf("The list patient info sorted\n");
            break;
            
        case 0:
            printf("Goodbye\n");
            break;
            
        default:
            printf("You chose a wrong value\n");
            break;
        }
    }
    return 0;
}

