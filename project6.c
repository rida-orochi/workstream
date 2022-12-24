/*
-Authorship: Rida Allah Jaija,Aymane Hasini,
-Purpose:For our project, we are going to develop of a software tool that assists engineers and project managers
 in evaluating the economic feasibility of different projects.
 What this tool will do is to allow users to input data such as initial costs, expected revenues, and operating expenses,
 and then use this data to calculate indicators like the present worth, internal rate of return ( percentage i), and payback period.
 The program will also give users the opportunity to compare multiple projects and choose the most viable one based on their economic performance.
 To implement this tool, we plan to use the data structures we have studied in class such as graphs, queues, and tables to represent and analyze the financial data. 
-Date: December 22, 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000

// Structure to represent a node in the graph.
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent an adjacency list.
struct AdjList
{
    struct Node *head;
};

// Structure to represent a graph.
struct Graph
{
    int number_Vertices;
    struct AdjList *array;
};

// Structure to represent a project.
struct Project
{
    double starting_price;
    double anticipated_Income;
    double operational_Costs;
    int number_periods;
    double Net_Present_data;
    double IRR;
    double repayment_Period;
    double Benefit_Cost_Ratio;
};

// Function to create a new node: use of malloc function.
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices.
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->number_Vertices = numVertices;
    graph->array = (struct AdjList *)malloc(numVertices * sizeof(struct AdjList));
    for (int i = 0; i < numVertices; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to a graph.
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to calculate the net present data of a project.
double calculateNet_Present_data(double starting_price, double anticipated_Income, double discountRate, int number_periods)
{
    double net_present_data = starting_price;
    for (int i = 0; i < number_periods; i++)
    {
        net_present_data += anticipated_Income / pow(1 + discountRate, i + 1);
    }
    return net_present_data;
}

// Function to calculate the internal rate of return of a project.
double calculateIRR(double starting_price, double anticipated_Income, int number_periods)
{
    // Internal rate of return (IRR) is the percentage of returns that a project will
    // generate within a period to cover its initial investment
    double rate = 0.0;
    double precision = 0.00001;
    double net_present_data = 0.0;
    double high = 1.0;
    double low = 0.0;
    while (high - low > precision)
    {
        rate = (high + low) / 2;
        net_present_data = starting_price;
        for (int i = 0; i < number_periods; i++)
        {
        }
        while (high - low > precision)
        {
            rate = (high + low) / 2;
            net_present_data = starting_price;
            for (int i = 0; i < number_periods; i++)
            {
                net_present_data += anticipated_Income / pow(1 + rate, i + 1);
            }
            if (net_present_data > 0)
            {
                low = rate;
            }
            else
            {
                high = rate;
            }
        }
        return rate;
    }
}

// Function to calculate the payback period of a project.
double calculaterepayment_Period(double starting_price, double anticipated_Income, double operational_Costs, int number_periods)
{
    // the number of years required for the cash income from a project to return the initial cash investment in the project.
    double cumulativeCashFlow = 0.0;
    for (int i = 0; i < number_periods; i++)
    {
        cumulativeCashFlow += anticipated_Income - operational_Costs;
        if (cumulativeCashFlow >= starting_price)
        {
            return i + 1;
        }
    }
    return -1;
}

// Function to calculate the benefit-cost ratio of a project.
double calculateBenefitCostRatio(double starting_price, double anticipated_Income, double operational_Costs, int number_periods, double discountRate)
{
    // an indicator showing the relationship between the relative costs and benefits of a
    // proposed project, expressed in monetary or qualitative terms
    // Calculate the present data of the expected benefits of the project
    double presentdataBenefits = 0.0;
    for (int i = 0; i < number_periods; i++)
    {
        presentdataBenefits += anticipated_Income / pow(1 + discountRate, i + 1);
    }

    // Calculate the present data of the expected costs of the project
    double presentdataCosts = starting_price;
    for (int i = 0; i < number_periods; i++)
    {
        presentdataCosts += operational_Costs / pow(1 + discountRate, i + 1);
    }

    // Calculate the benefit-cost ratio
    return presentdataBenefits / presentdataCosts;
}

// Main function
int main()
{
    // Create an empty graph to store the projects.
    struct Graph *graph = createGraph(100); // Assume there are at most 100 projects.
    int numProjects = 0;

    // Read the project data from the user.
    // We wanted to use a file and use the data to analyse project directly, but we couldn't have enough time to find reliable one :(
    printf("Enter the number of projects: ");
    scanf("%d", &numProjects);
    for (int i = 0; i < numProjects; i++)
    {
        struct Project project;
        printf("For year number please do %d:\n ", i + 1);
        printf("Enter the initial cost\n");
        scanf("%lf", &project.starting_price);
        printf("Enter the expected revenue\n");
        scanf("%lf", &project.anticipated_Income);
        printf("Enter the operating annual expenses\n");
        scanf("%lf", &project.operational_Costs);
        printf("Enter the number of years for project\n");
        scanf("%d", &project.number_periods);

        // Calculate the net present data of the project.
        project.Net_Present_data = calculateNet_Present_data(project.starting_price, project.anticipated_Income, 0.1, project.number_periods);

        // Calculate the internal rate of return of the project.
        project.IRR = calculateIRR(project.starting_price, project.anticipated_Income, project.number_periods);

        // Calculate the payback period of the project.
        project.repayment_Period = calculaterepayment_Period(project.starting_price, project.anticipated_Income, project.operational_Costs, project.number_periods);

        // Calculate the benefit-cost ratio of the project.
        project.Benefit_Cost_Ratio = calculateBenefitCostRatio(project.starting_price, project.anticipated_Income, project.operational_Costs, project.number_periods, 0.1);

        // Add the project to the graph.
        addEdge(graph, i, i);

        // Print the results for the project.
        printf("\n-----------------------------------------\n");
        printf("\nHere is project number %d analysis:\nNPV (net present value) = %.2f\nIRR(internal rate of return) = %.2f\nPayback Period = %.2f year\nBCR = %.2f %\n", i + 1, project.Net_Present_data, project.IRR, project.repayment_Period, project.Benefit_Cost_Ratio);
        // Reminder :)!
        // NPV means the net present value/worth, IRR is the internal rate of return (%) , BCR is the benefit cost ratio
        // Payback period means (the number of years required for the cash income from a project to return the initial cash investment in the project.)
    }

    return 0;
}