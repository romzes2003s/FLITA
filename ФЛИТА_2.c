#include <stdio.h>
#include <stdlib.h>

int main(){
    int counter=0;
    int s=0;
    char c;
    FILE *file=fopen("list_of_edges70.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    c=fgetc(file);
    while(c!=EOF)
    {
        if(c=='\n')
        {
            counter++;
        }
        c=fgetc(file);
    }
    fclose(file);
    s=counter;
    int matrix[100][2];
    int i, j, k;
    FILE* file1 = fopen("list_of_edges70.txt", "r");
    if (!file1)
        exit(EXIT_FAILURE);
    for (i = 0; i < s && !feof(file1); i++)
    {
        for (j = 0; j < 2 && !feof(file1); j++)
        {
            fscanf(file1, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    fclose(file1);
    FILE* out;
    out = fopen("output.dot", "w");
    fprintf(out, "graph{\n");
    for (i = 0; i < s; i++)
    {
        fprintf(out, "%d -- %d\n", matrix[i][0], matrix[i][1]);
    }
    fprintf(out, "}\n");
    fclose(out);
    system("dot output.dot -Tpng -o image.png");
    return (EXIT_SUCCESS);
}