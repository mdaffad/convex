#include <cstdio>
struct point
{
    float x,y;
} input[100];
int num;
int main()
{
    scanf("%d",&num);
    FILE *fp;
    float a,b;

    fp = fopen("test.txt", "r");
    for (int i = 0; i < num; i++)
    {
        fscanf(fp,"%f %f", &input[i].x,&input[i].y);
        printf("%f %f\n",input[i].x, input[i].y);
    }
    fclose(fp);
    
    return 0;
}