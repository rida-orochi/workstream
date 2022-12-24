#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int studentenrolled, creditperhour;
typedef struct student
{
    int ID;
    char name[25];
    int nbcourse;
    char tuition;
    char course[7][25];
    char courseName[7][25];
    int nbcredit[7];
    char grade[7][2];

    struct student *next;
    struct student *prev;
} node;

node *create_fill_node(int newid, char newname[25], int newnbcourse,char newtuition, char newcourse[7][25],char newcourseName[7][25], int nbcourse[7],char newgrade[7][2]);
node *add_node(node *head, node *newNode);
node *delete_node(node *head, int ID_d);
void traverse(node *head);
int search(int IDtoSearch, node *head, node **toSearch);
void menu();
node *AddStudent(node *head);
int SumOfNumberOfCredits(int nbcredit[7], int nbcourse);
int numberOfPoint(char grade[7][2], int nbcourse, int nbcredit[7]);
double computeGPA(int sumnbcredits, char studentGrade[7][2], int nbcourse,int credit[7]);
void searchStudent(node *head);
node *Updatestudent(node *head);
node *read(node *head);

node *delete (node *head);
void updateFile(node *head);

int main()
{
    node *head = NULL, *newNode, *toSearch;
    head = read(head);
    int choice;
    int k;

    do
    {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            // add stude
            head = AddStudent(head);

            break;
        case 2:
            // update student

            head = Updatestudent(head);
            // update file
            break;
        case 3:
            // delete student

            head = delete (head);
            break;
        case 4:
            // Search for a student
            searchStudent(head);
            break;
        case 5:
            updateFile(head);
            printf("\n\t Take care !");

            break;
        case 6:
            // delete student
            traverse(head);
            break;
        default:
            printf("\n\t Invalid choice! Try again.");

            break;
        }
    } while (choice != 5);

    return 0;
}
node *create_fill_node(int newid, char newname[25], int newnbcourse,char newtuition, char newcourse[7][25],char newcourseName[7][25], int newnbcredit[7],char newgrade[7][2])
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->ID = newid;
    strcpy(newNode->name, newname);
    newNode->nbcourse = newnbcourse;
    newNode->tuition = newtuition;
    for (int i = 0; i < newnbcourse; i++)
    {
        strcpy(newNode->course[i], newcourse[i]);
        strcpy(newNode->courseName[i], newcourseName[i]);
        newNode->nbcredit[i] = newnbcredit[i];
        strcpy(newNode->grade[i], newgrade[i]);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

node *add_node(node *head, node *newNode)
{
    node *walker;
    if (head == NULL)
        head = newNode;
    else
    {
        walker = head;
        while (walker->next != NULL)
        {
            walker = walker->next;
        }
        walker->next = newNode;
        newNode->prev = walker;
    }
    return head;
}

void traverse(node *head)
{
    node *walker;
    if (head == NULL)
        printf("\n The list is empty");
    else
    {
        walker = head;
        while (walker != NULL)
        {
            printf("\n The ID is : %d ", walker->ID);
            // TESTING
            printf("id:%d name:%s nbCourse %d tuition %c ", walker->ID, walker->name,walker->nbcourse, walker->tuition);
            for (int i = 0; i < walker->nbcourse; i++)
            {
                printf("course name: %s", walker->course[i]);
                printf("\t grade: %s\n", walker->grade[i]);
            }
            walker = walker->next;
        }
    }
}

void menu()
{
    printf("\n\t\t----Menu----");
    printf("\n\t 1. Add a student");
    printf("\n\t 2. Update a student's course Grade");
    printf("\n\t 3. Delete a student");
    printf("\n\t 4. Search for a student");
    printf("\n\t 5. Exit");
    printf("\n\t Enter your choice : ");
}

int SumOfNumberOfCredits(int nbcredit[7], int nbcourse)
{
    int sum = 0;
    for (int i = 0; i < nbcourse; i++)
    {
        sum = sum + nbcredit[i];
    }
    return sum;
}

int numberOfPoint(char grade[7][2], int nbcourse, int nbcredit[7])
{
    int sum = 0;
    for (int i = 0; i < nbcourse; i++)
    {
        if (strcmp(grade[i], "A") == 0)
        {
            sum = sum + (4 * nbcredit[i]);
        }
        if (strcmp(grade[i], "B") == 0)
        {
            sum = sum + 3 * nbcredit[i];
        }
        if (strcmp(grade[i], "C") == 0)
        {
            sum = sum + 2 * nbcredit[i];
        }
        if (strcmp(grade[i], "D") == 0)
        {
            sum = sum + (1 * nbcredit[i]);
        }
        if (strcmp(grade[i], "F") == 0)
        {
            sum = sum + 0;
        }
    }

    return sum;
}

double computeGPA(int sumnbcredits, char studentGrade[7][2], int nbcourse,int credit[7])
{
    double sum = 0;
    for (int i = 0; i < nbcourse; i++)
    {
        sum = numberOfPoint(studentGrade, nbcourse, credit);
    }
    double result = sum / sumnbcredits;
    return result;
}

void searchStudent(node *head)
{

    // searching
    int ID, status = 0;
    node *toSearch, *node;

    printf("//Searching student//");
    do
    {
        printf("\nEnter ID:");
        scanf("%d", &ID);
        status = search(ID, head, &toSearch);
        if (status == 0)
            printf("\n ID Does not exist! Please enter a new ID:");
    } while (status != 1);

    // printf("Enter Student ID:");
    // scanf("%d", &searchID);
    // int status = search(searchID, head, &toSearch);
    // while (status == 0) {
    //   printf("Student not found \n");
    //   printf("Enter Student ID:");
    //   scanf("%d", &searchID);
    //   int status = search(searchID, node, &toSearch);
    // }
    node = toSearch;
    // return node

    // add numberOfCredits SumOfNumberOfCredits computeGPA
    if (node->tuition == 'Y')
    {
        printf("\nStudent name : %s ", node->name);
        printf("\nStudent ID : %d", node->ID);
        printf("\nNumber of courses enrolled: %d\n", node->nbcourse);
        printf("\n");

        printf("%*s  %*s  %*s  %*s \n", -20, "Course No", -20, "Course name", -20,"Credits", -20, "Grade");

        for (int i = 0; i < node->nbcourse; ++i)
        {
            printf("%-20s  %-20s  %-20d  %-20s \n", node->course[i],node->courseName[i], node->nbcredit[i], node->grade[i]);
        }

        printf("\n");

        printf("\nTotal number of credits: %d",SumOfNumberOfCredits(node->nbcredit, node->nbcourse));
        printf("\nMid-Semester GPA: %f",computeGPA(SumOfNumberOfCredits(node->nbcredit, node->nbcourse),node->grade, node->nbcourse, node->nbcredit));
    }
    else
    {
        printf("\nThe Student did not pay his tuition\n");
        printf("The amount to be paid: %d$\n", creditperhour * SumOfNumberOfCredits(node->nbcredit, node->nbcourse));
    }
}

node *Updatestudent(node *head)
{

    node *toSearch = NULL, *walker = head;
    int status = 0, ID, j = 0, i;

    char newGrade[2], searchcourse[25] = {}, flag = 'Y';
    printf("//Updating student grade//");
    do
    {
        printf("\nEnter ID:");
        scanf("%d", &ID);
        status = search(ID, head, &toSearch);
        if (status == 0)
            printf("\n ID Does not exist! Please enter a new ID:");
    } while (status != 1);

    while (flag != 'N')
    {
        printf("Enter the course that you want to update(course code):");
        getchar(); // to remove the \n after the scanf of the integer
        fgets(searchcourse, 25, stdin);

        // traverse the id node and search for matching courses
        while (walker != toSearch)
        {
            walker = walker->next;
        }
        for (i = 0; i < walker->nbcourse; i++)
        {
            if (strcmp(walker->course[i], searchcourse) == 0)
            {
                j = i;

                break;
            }
        }
        printf("Update the grade:");
        // the id node
        scanf("%s", newGrade);
        printf("\n the previous grade : %s", walker->grade[j]);
        strcpy(walker->grade[j], newGrade);
        printf("\n the new grade : %s", walker->grade[j]);

        getc(stdin);
        printf("\ndo you want to upgrade another course grade[Y/N]:");
        scanf("%c", &flag);
        while (flag != 'Y' && flag != 'N')
        {
            printf("\nInvalid char");
            getc(stdin);
            printf("\nDo you want to upgrade another course grade[Y/N]:");
            scanf("%c", &flag);
            if (flag == 'Y' || flag == 'N')
                break;
        }
    }
    return head;
}

node *AddStudent(node *head)
{
    node *newNode, *toSearch = NULL;
    int ID, nbcourse, nbcredit[7], status = 1;

    char name[25], lname[25], course[7][25], grade[7][2], courseName[7][25], c;
    char tuition;

    do
    {
        printf("//Adding a new Student //");
        printf("\nEnter ID:");
        scanf("%d", &ID);

        status = search(ID, head, &toSearch);
        if (status == 1)
            printf("\n ID already existing! \nPlease enter a new ID:");
    } while (status != 0);
    if (ID == 69)
        printf("\nNice :)\n");
    printf("Enter First name:");
    scanf("%s", name);
    printf("Enter Last name:");
    scanf("%s", lname);
    strcat(strcat(name, " "), lname);
    printf("Enter the number of courses taken:");
    scanf("%d", &nbcourse);

    getc(stdin);
    printf("Enter did he paid the tuition[Y/N]:");
    scanf("%c", &tuition);
    while (tuition != 'Y' && tuition != 'N')
    {
        printf("\nInvalid char");
        getc(stdin);
        printf("\nEnter did he paid the tuition[Y/N]:");
        scanf("%c", &tuition);
        if (tuition == 'Y' || tuition == 'N')
            break;
    }

    for (int i = 0; i < nbcourse; i++)
    {
        printf("Enter course code:");
        scanf("%s", course[i]);
        printf("Enter the course name:");
        scanf("%s", courseName[i]);
        printf("Enter the number of credits:");
        scanf("%d", &nbcredit[i]);
        printf("Enter grade:");
        scanf("%s", grade[i]);
    }
    // TESTING
    //   printf("id:%d name:%s nbCourse %d tuition %c ", ID, name, nbcourse,
    //   tuition); for (int i = 0; i < nbcourse; i++) {
    //     printf("course name: %s", course[i]);
    //     printf("\t grade: %s\n", grade[i]);
    //   }

    newNode = create_fill_node(ID, name, nbcourse, tuition, course, courseName,nbcredit, grade);
    head = add_node(head, newNode);

    printf("The student has been added successfully");
    studentenrolled++;
    return head;
}

int search(int IDtoSearch, node *head, node **toSearch)
{
    node *walker = head;
    if (walker == NULL)
    {
        (*toSearch) = NULL;
        return 0;
    }
    else
    {
        do
        {
            if (walker->ID == IDtoSearch)
            {
                (*toSearch) = walker;
                return 1;
            }
            else
                walker = walker->next;
        } while (walker != NULL);

        (*toSearch) = NULL;
        return 0;
    }
}

node *delete (node *head)
{
    node *temp = head;
    node *temp2, *toSearch;
    int id, status;
    printf("//Delete Student//\n[Enter -1 to exit]");

    do
    {
        printf("\nEnter ID:");
        scanf("%d", &id);
        if (id == -1)
            return head;
        status = search(id, head, &toSearch);
        if (status == 0)
            printf("\n ID Does not exist! \nPlease enter a new ID:");

    } while (status != 1);
    while (temp->ID != id)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nCan't delete\n");
            return head;
        }
    }
    // delete one node
    if (temp->next == NULL && temp == head)
    {
        head = NULL;
        free(head);
        printf("Student Successfully Deleted");
        studentenrolled--;
        return head;
    }
    // delete node at the beginning
    if (temp == head && temp->next != NULL)
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        printf("Student Successfully Deleted");
        studentenrolled--;
        return head;
    }
    // delete node at the end
    if (temp->next == NULL && temp != head)
    {
        temp2 = temp->prev;
        temp2->next = NULL;
        free(temp);
        printf("Student Successfully Deleted");
        studentenrolled--;
        return head;
    }

    // delete node at the middle
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
        printf("Student Successfully Deleted");
        studentenrolled--;
        return head;
    }

    return head;
}

node *read(node *head)
{
    node *newNode;

    int ID, nbcourse, nbcredit[7];
    char name[20], fname[20], lname[20], tuition, courseName[7][25],
        course[7][25], grade[7][2];
    char x[20];
    FILE *infp = fopen("stData.txt", "r");
    fscanf(infp, " %1023s", x);
    studentenrolled = atoi(x);
    fscanf(infp, " %1023s", x);
    creditperhour = atoi(x);

    for (int i = 0; i < studentenrolled; i++)
    {
        fscanf(infp, " %1023s", name);
        fscanf(infp, " %1023s", lname);
        strcat(strcat(name, " "), lname);
        fscanf(infp, " %1023s", x);
        ID = atoi(x);
        fscanf(infp, " %1023s", x);
        tuition = x[0];
        fscanf(infp, " %1023s", x);
        nbcourse = atoi(x);
        for (int j = 0; j < nbcourse; j++)
        {
            fscanf(infp, " %1023s", courseName[j]);
            fscanf(infp, " %1023s", course[j]);
            fscanf(infp, " %1023s", x);
            nbcredit[j] = atoi(x);
            fscanf(infp, " %1023s", grade[j]);
        }

        newNode = create_fill_node(ID, name, nbcourse, tuition, course, courseName,nbcredit, grade);

        head = add_node(head, newNode);
    }
    return head;
}

void updateFile(node *head)
{

    node *walker;
    FILE *infp = fopen("stData.txt", "w");
    fseek(infp, 0, 0); // refresh the cursor to the beginning

    if (head == NULL)
        return;
    else
    {
        fprintf(infp, "%d %d", studentenrolled, creditperhour);
        walker = head;
        fprintf(infp, "\n%s\t%d\t%c\t%d", walker->name, walker->ID, walker->tuition,
                walker->nbcourse);
        for (int i = 0; i < walker->nbcourse; i++)
        {
            int creditHours = walker->nbcredit[i];
            fprintf(infp, "\n%s\t%s\t%d\t%s", walker->courseName[i],
                    walker->course[i], creditHours, walker->grade[i]);
        }
        fprintf(infp, "\n");
        walker = walker->next;
        while (walker != NULL)
        {
            fprintf(infp, "\n%s\t%d\t%c\t%d", walker->name, walker->ID,
                    walker->tuition, walker->nbcourse);
            for (int i = 0; i < walker->nbcourse; i++)
            {
                int creditHours = walker->nbcredit[i];
                fprintf(infp, "\n%s\t%s\t%d\t%s", walker->courseName[i],
                        walker->course[i], creditHours, walker->grade[i]);
            }
            fprintf(infp, "\n");
            walker = walker->next;
        }
    }
}