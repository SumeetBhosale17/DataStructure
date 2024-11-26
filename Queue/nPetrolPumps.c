#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int petrol;
    int distance;
} PetrolPump;

int findStartingPetrolPump(PetrolPump* pumps, int n)
{
    int total_tank = 0;
    int current_tank = 0;
    int starting_point = 0;

    for (int i = 0; i<n; i++)
    {
        int surplus = pumps[i].petrol - pumps[i].distance;
        total_tank += surplus;
        current_tank += surplus;

        if (current_tank < 0)
        {
            starting_point = i + 1;
            current_tank = 0;
        }
    }

    if (total_tank >= 0 && starting_point < n)
    {
        return starting_point;
    }
    return -1;
}

int main()
{
    printf("Enter number of petrol pumps : ");
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Number of petrol pumps should be greater than zero!");
        return 1;
    }
    PetrolPump* pumps = (PetrolPump*)malloc(n*(sizeof(PetrolPump)));
    if (pumps == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter the petrol and distance for each pump : \n");
    for (int i = 0; i<n; i++)
    {
        printf("Pump %d : Petrol = ", i + 1);
        scanf("%d", &pumps[i].petrol);
        printf("Pump %d: Distance = ", i + 1);
        scanf("%d", &pumps[i].distance);
    }

    int start = findStartingPetrolPump(pumps, n);
    if (start == -1)
    {
        printf("No Solution exist!");
    }
    else 
    {
        printf("Starting point is : %d", start);
    }

    free(pumps);
    return 0;
}
