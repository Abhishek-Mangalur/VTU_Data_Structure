// Solving Tower of Hanoi problem with n disks 

#include <stdio.h>
#include <math.h>

void tower(int n, int source, int temp, int destination)
{
    if (n == 0)
        return;
    tower(n - 1, source, destination, temp);
    printf("\nMove disc %d from %c to %c", n, source, destination);
    tower(n - 1, temp, source, destination);
}

void main()
{
    int n;
    printf("\nEnter the number of discs: ");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    printf("\n\nTotal Number of moves are: %d\n", (int)pow(2, n) - 1);
}