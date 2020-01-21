#include <cstdio>
struct point
{
    float x,y;
};
struct line
{
    point a,b;
    bool over = false,below = false;
};

int num;
int main()
{
    
    FILE *fp;
    float a,b;
    int indexer = 0;
    fp = fopen("test.txt", "r");
    fscanf(fp,"%d",&num);
    point input[num];
    line output[num];
    for (int i = 0; i < num; i++)
    {
        fscanf(fp,"%f %f", &input[i].x,&input[i].y);
        printf("%f %f\n",input[i].x, input[i].y);
    }
    fclose(fp);
    
    for (int i = 0; i < num-1; i++)
    {
        for (int j = i+1; j < num; j++)
        {
            // printf("i j %d %d\n",i ,j);
            for (int k = 0; k < num; k++)
            {
                // printf("i j k %d %d %d\n",i ,j, k);
                if ((input[k].y - input[i].y) / (input[j].y - input[i].y) - (input[k].x - input[i].x) / (input[j].x - input[i].x) > 0 && i != k && j != k);
                {
                    checker = false;
                    // printf("bureiki %d %d\n",i ,j);
                    break;
                }   
            }
            if (checker)
            {
                output[indexer].a = input[i];
                output[indexer].b = input[j];
                indexer++;
                // printf("the truth %d %d\n",i,j);
            }
        }
    }
    printf("%d \n",indexer);
    return 0;
}