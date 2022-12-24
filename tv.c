#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000

// Structure to represent a node in the graph.
struct Node
{
    int value;
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
    int num_Vertices;
    struct AdjList *array;
};

// Structure to represent a project.
struct Project
{
    double initialCost;
    double expectedRevenue;
    double operatingExpenses;
    int num_Periods;
    double Net_Present_Value;
    double Internal_Rate_Return;
    double paybackPeriod;
};

// Function to create a new node.
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices.
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->num_Vertices = numVertices;
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

// Function to calculate the net present value of a project.
double calculateNet_Present_Value(double initialCost, double expectedRevenue, double discountRate, int num_Periods)
{
    double net_present_value = initialCost;
    for (int i = 0; i < num_Periods; i++)
    {
        net_present_value += expectedRevenue / pow(1 + discountRate, i + 1);
    }
    return net_present_value;
}

// Function to calculate the internal rate of return of a project.
double calculateInternal_Rate_Return(double initialCost, double expectedRevenue, int num_Periods)
{
    double rate = 0.0;
    double precision = 0.00001;
    double net_present_value = 0.0;
    double high = 1.0;
    double low = 0.0;
    while (high - low > precision)
    {
        rate = (high + low) / 2;
        net_present_value = initialCost;
        for (int i = 0; i < num_Periods; i++)
        {
            net_present_value += expectedRevenue / pow(1 + rate, i + 1);
        }
        if (net_present_value > 0)
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

// Function to calculate the payback period of a project.
double calculatePaybackPeriod(double initialCost, double expectedRevenue, double operatingExpenses, int num_Periods)
{
    double cumulativeCashFlow = 0.0;
    for (int i = 0; i < num_Periods; i++)
    {
        cumulativeCashFlow += expectedRevenue - operatingExpenses;
        if (cumulativeCashFlow >= initialCost)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    // Create an empty graph to store the projects.
    struct Graph *graph = createGraph(100); // Assume there are at most 100 projects.
    int numProjects = 0;

    // Read the project data from the user.
    printf("Enter the number of projects: ");
    scanf("%d", &numProjects);

    // Create an array to store the data for each project.
    struct Project *projects = (struct Project *)malloc(numProjects * sizeof(struct Project));

    for (int i = 0; i < numProjects; i++)
    {
        printf("Enter the data for project %d\n", i + 1);
        printf("Enter the initial cost: ");
        scanf("%lf", &projects[i].initialCost);
        printf("Enter the expected revenue: ");
        scanf("%lf", &projects[i].expectedRevenue);
        printf("Enter the operating expenses: ");
        scanf("%lf", &projects[i].operatingExpenses);
        printf("Enter the number of periods: ");
        scanf("%d", &projects[i].num_Periods);
        // Calculate the net present value of the project.
        double net_present_value = calculateNet_Present_Value(projects[i].initialCost, projects[i].expectedRevenue, 0, projects[i].num_Periods);
        // Calculate the internal rate of return of the project.
        double internal_rate_return = calculateInternal_Rate_Return(projects[i].initialCost, projects[i].expectedRevenue, projects[i].num_Periods);
        // Calculate the payback period of the project.
        double payback_period = calculatePaybackPeriod(projects[i].initialCost, projects[i].expectedRevenue, projects[i].operatingExpenses, projects[i].num_Periods);
        // Store the results in the corresponding struct.
        // Store the results in the corresponding struct.
        projects[i].Net_Present_Value = net_present_value;
        projects[i].Internal_Rate_Return = internal_rate_return;
        projects[i].paybackPeriod = payback_period;

        // Print the results for each project.
        for (int i = 0; i < numProjects; i++)
        {
            printf("Results for project %d:\n", i + 1);
            printf("Net present value: %.2lf\n", projects[i].Net_Present_Value);
            printf("Internal rate of return: %.2lf%%\n", projects[i].Internal_Rate_Return * 100);
            if (projects[i].paybackPeriod == -1)
            {
                printf("Payback period: Never\n");
            }
            else
            {
                printf("Payback period: %.2lf years\n", projects[i].paybackPeriod);
            }
        }

        return 0;
    }
}