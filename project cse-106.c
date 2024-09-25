#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[30];
    int fund, meal;
    struct Node *next;
}*head=NULL;
int cost[30], top=-1, totalc=0,totalm=0;
float rate;

void insertAtEnd(char value[])
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->fund=0;
    newNode->meal=0;
    strcpy(newNode->data, value);
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    system("cls");
    printf("\n\t\t\t\t\t    One member added!!!\n\n");
}
void deleteAtBeginning()
{
    if(head==NULL)
    {
        system("cls");
        printf("\n\t\t\t\t\t    No one have to revome..!\n\n");

    }
    else
    {
        struct Node *temp = head;
        head=temp->next;
        system("cls");
        printf("\n\t\t\t\t\t    One member remmove from Beginning!!!\n\n");
    }

}
void deleteInInterior()
{
    char del[30];
    printf("\n\t\t\t\t\t    Enter the name of the member:");
    getchar();
    gets(del);
    if(head==NULL)
    {
        system("cls");
        printf("\n\t\t\t\t\t    No one to remove..!\n\n");

    }
    else
    {
        struct Node *temp = head, *temp2;
        while(strcmp(temp->data,del))
        {
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=temp->next;
    }
    system("cls");
    printf("\n\t\t\t\t\t    One member removed !!!\n\n");
}
void deleteAtEnd()
{
    struct Node *temp = head, *temp2;
    while(temp->next != NULL)
    {
        temp2=temp;
        temp = temp->next;
    }
    temp2->next=NULL;
    system("cls");
    printf("\n\t\t\t\t\t    One member remove from End!!!\n\n");

}
void display()
{
    system("cls");
    if(head == NULL)
    {
        printf("\n\t\t\t\t\t    No member exist..!!\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\n\n\t\t\t\t\t    Member list - \n");
        int i=1;
        while(temp->next != NULL)
        {
            printf("%d. ", i);
            puts(temp->data);
            temp = temp->next;
            i++;
        }
        printf("%d. ", i);
        puts(temp->data);
    }
    printf("\n\n");
}

void showf()
{
    system("cls");
    if(head == NULL)
    {
        printf("\n\t\t\t\t\t    List is Empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\n\n\t\t\t\t\t    Member list - \n");
        int i=1;
        while(temp->next != NULL)
        {
            printf("\t\t\t\t\t    %d. ", i);
            puts(temp->data);
            printf("\t\t\t\t\t    --->%d\n",temp->fund);
            temp = temp->next;
            i++;
        }
        printf("\t\t\t\t\t    %d. ", i);
        puts(temp->data);
        printf("\t\t\t\t\t    --->%d\n",temp->fund);
    }
}

void addfund(int x, int a)
{
    struct Node *temp=head;
    int i=1;
    while(i!=x)
    {
        temp=temp->next;
        i++;
    }
    temp->fund+=a;
    system("cls");
    printf("\n\t\t\t\t\t    Fund added..!!\n");
}
void addcost()
{
    top++;
    printf("\n\t\t\t\t\t    Enter the cost:");
    scanf("%d",&cost[top]);
    totalc+=cost[top];
    system("cls");
    printf("\n\t\t\t\t\t    Cost added..!!\n");
}

void addmeal(int x, int m)
{
    struct Node *temp=head;
    int i=1;
    while(i!=x)
    {
        temp=temp->next;
        i++;
    }
    temp->meal=m;
    totalm+=m;
    system("cls");
    printf("\n\t\t\t\t\t    Meal added..!!\n");
}

void showm()
{
    system("cls");
    if(head == NULL)
    {
        printf("\n\t\t\t\t\t    List is Empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\n\n\t\t\t\t\t    Member list- \n");
        int i=1;
        while(temp->next != NULL)
        {
            printf("\t\t\t\t\t    %d. ", i);
            puts(temp->data);
            printf("\t\t\t\t\t    --->%d\n",temp->meal);
            temp = temp->next;
            i++;
        }
        printf("\t\t\t\t\t    %d. ", i);
        puts(temp->data);
        printf("\t\t\t\t\t    --->%d\n",temp->meal);
    }
}

void showc()
{
    system("cls");
    rate=(float)totalc/totalm;
    if(head == NULL)
    {
        printf("\n\t\t\t\t\t    List is Empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\n\n\t\t\t\t\t    Cost per person - \n");
        int i=1;
        float cost;
        while(temp->next != NULL)
        {
            printf("\t\t\t\t\t    %d. ", i);
            puts(temp->data);
            cost=rate*(temp->meal);
            printf("\t\t\t\t\t    --->%f\n",cost);
            temp = temp->next;
            i++;
        }
        printf("\t\t\t\t\t    %d. ", i);
        puts(temp->data);
        cost=rate*(temp->meal);
        printf("\t\t\t\t\t    --->%f\n",cost);
    }
}

void finalfund()
{
    system("cls");
    rate=(float)totalc/totalm;
    if(head == NULL)
    {
        printf("\n\t\t\t\t\t    List is Empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\n\n\t\t\t\t\t    Final cost per person - \n");
        int i=1;
        float cost;
        while(temp->next != NULL)
        {
            printf("\t\t\t\t\t    %d. ", i);
            puts(temp->data);
            cost=rate*(temp->meal);
            printf("\t\t\t\t\t    --->%f\n",((temp->fund)-cost));
            temp = temp->next;
            i++;
        }
        printf("\t\t\t\t\t    %d. ", i);
        puts(temp->data);
        cost=rate*(temp->meal);
        printf("\t\t\t\t\t    --->%f\n",((temp->fund)-cost));
    }
}

int main()
{
    int choice, choice1,choice2,choice3, loc1, loc2;
    int c1, x1;
    int amount, meal;
    char value[30];
    while(1)
    {
        mainMenu:
        printf("\t\t\t\t\t-------------------------\n");
        printf("\t\t\t\t\t    1.Members Details\n");
        printf("\t\t\t\t\t    2.Fund Details\n");
        printf("\t\t\t\t\t    3.Meal Deatails\n");
        printf("\t\t\t\t\t    4.Show Cost\n");
        printf("\t\t\t\t\t    5.Final fund\n");
        printf("\t\t\t\t\t    6.Exit\n");
        printf("\t\t\t\t\t-------------------------\n\n");
        printf("\t\t\t\t\t    Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:

            while(1)
            {
                printf("\t\t\t\t\t    1.Add Member\n");
                printf("\t\t\t\t\t    2.Remove Member\n");
                printf("\t\t\t\t\t    3.See Members List\n\n");
                printf("\t\t\t\t\t    Enter your choice:");
                scanf("%d",&choice1);
                switch(choice1)
                {
                case 1:
                    printf("\t\t\t\t\t    Enter member name: ");
                    getchar();
                    gets(value);
                    insertAtEnd(value);
                    break;
                case 2:
                    while(1)
                    {
                        printf("\t\t\t\t\t    Which one you want to remove:\n");
                        printf("\t\t\t\t\t    1.Frist member\n");
                        printf("\t\t\t\t\t    2.Last member\n");
                        printf("\t\t\t\t\t    3.From middle\n");
                        printf("\t\t\t\t\t    Enter your choice:");
                        scanf("%d",&choice3);
                        switch(choice3)
                        {
                        case 1:
                            deleteAtBeginning();
                            break;
                        case 2:
                            deleteAtEnd();
                            break;
                        case 3:
                            deleteInInterior();
                            break;
                        default:
                            system("cls");
                            printf("\n\t\t\t\t\t    Wrong Input!! Try again!!!\n\n");
                            break;
                        }
                        goto end2;
                    }
                    end2:
                    break;
                case 3:
                    display();
                    break;
                default:
                    system("cls");
                    printf("\n\t\t\t\t\t    Wrong Input!! Try again!!!\n\n");
                    goto mainMenu;
                }
                goto subMenuEnd;
            }
        subMenuEnd:
        break;

        case 2:
            while(1)
            {
                printf("\t\t\t\t\t    1.Add fund\n");
                printf("\t\t\t\t\t    2.Add cost\n");
                printf("\t\t\t\t\t    3.Show fund\n");
                printf("\t\t\t\t\t    4.Show total cost\n");
                scanf("%d",&choice2);
                switch(choice2)
                {
                case 1:
                    display();
                    printf("\n\t\t\t\t\t    Whose fund do you want to add??\n");
                    printf("\n\t\t\t\t\t    Enter number: ");
                    int x;
                    scanf("%d", &x);
                    printf("\n\t\t\t\t\t    Enter the amount:");
                    scanf("%d",&amount);
                    addfund(x, amount);
                    break;
                case 2:
                    addcost();
                    break;
                case 3:
                    showf();
                    break;
                case 4:
                    system("cls");
                    printf("\n\t\t\t\t\t    Total cost is: %d\n",totalc);
                    break;
                default:
                    system("cls");
                    printf("\n\t\t\t\t\t    Wrong Input!! Try again!!!\n\n");
                    goto mainMenu;
                }
                goto subMenuDel;
            }
            subMenuDel:
            break;
        case 3:

            while(1)
            {
                printf("\t\t\t\t\t    1.Add meal\n");
                printf("\t\t\t\t\t    2.Show meal\n");
                printf("\t\t\t\t\t    3.Show total meal\n");
                printf("\t\t\t\t\t    4.Current meal rate\n");
                printf("\t\t\t\t\t    Enter your choice:");
                scanf("%d",&c1);
                switch(c1)
                {
                case 1:
                    display();
                    printf("\n\t\t\t\t\t    Whose meal do you want add:");
                    scanf("%d", &x1);
                    printf("\n\t\t\t\t\t    Enter the meal amount:");
                    scanf("%d",&meal);
                    addmeal(x1, meal);
                    break;
                case 2:
                    showm();
                    break;
                case 3:
                    system("cls");
                    printf("\t\t\t\t\t    Total meal is: %d\n", totalm);
                    break;
                case 4:
                    rate=(float)totalc/totalm;
                    system("cls");
                    printf("\t\t\t\t\t    Current meal rate is: %f\n", rate);
                    break;
                default:
                    system("cls");
                    printf("\n\t\t\t\t\t    Wrong Input!! Try again!!!\n\n");
                    goto mainMenu;
                }
                goto del2;
            }
            del2:
            break;
        case 4:
            showc();
            break;
        case 5:
            finalfund();
            break;
        case 6:
            exit(0);
        default:
            system("cls");
            printf("\n\t\t\t\t\t    Wrong input!!! Try again!!\n\n");
        }
    }
    return 0;
}
