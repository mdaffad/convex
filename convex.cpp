#include <cstdio>
#include <stdlib.h>
#include <time.h>  
struct point
{
    float x,y;
};
struct line
{
    point a,b;

};
bool over = false,below = false;
int num;
int main()
{
    
    srand (time(NULL));
    float a,b;
    int indexer = 0;
    scanf("%d",&num);
    point input[num];
    line output[num];
    for (int i = 0; i < num; i++)
    {
        input[i].x = rand()%100;
        input[i].y = rand()%100;
        // printf("%f %f\n",input[i].x, input[i].y);
    }
    clock_t begin = clock();


    for (int i = 0; i < num-1; i++)
    {
        for (int j = i+1; j < num; j++)
        {
            // printf("i j %d %d\n",i ,j);
            float test;
            for (int k = 0; k < num; k++)
            {
                // printf("i j k %d %d %d\n",i ,j, k);
                if (!( ((input[i].x == input[k].x) && (input[i].y == input[k].y)) || ( (input[j].x == input[k].x) && (input[j].y == input[k].y))))
                {
                    test = (input[j].y - input[i].y)*input[k].x + (input[i].x - input[j].x)*input[k].y - input[i].x*input[j].y + input[i].y*input[j].x; 
                    if (test > 0)
                    {
                        over = true;
                    }
                    else if (test < 0)
                    {
                        below = true;
                    }
                    else
                    {
                        if  (!(   ((input[i].x < input[k].x) && (input[i].y < input[k].y) &&
                                (input[j].x > input[k].x) && (input[j].y > input[k].y)) ||
                                ((input[i].x < input[k].x) && (input[i].y > input[k].y) &&
                                (input[j].x > input[k].x) && (input[j].y < input[k].y)) ||
                                ((input[i].x > input[k].x) && (input[i].y > input[k].y) &&
                                (input[j].x < input[k].x) && (input[j].y < input[k].y)) ||
                                ((input[i].x > input[k].x) && (input[i].y < input[k].y) &&
                                (input[j].x < input[k].x) && (input[j].y > input[k].y)) ||
                                ((input[i].x < input[k].x) && (input[i].y == input[k].y) &&
                                (input[j].x > input[k].x) && (input[j].y == input[k].y)) ||
                                ((input[j].x < input[k].x) && (input[j].y == input[k].y) &&
                                (input[i].x > input[k].x) && (input[i].y == input[k].y)) ||
                                ((input[i].x == input[k].x) && (input[i].y > input[k].y) &&
                                (input[j].x == input[k].x) && (input[j].y < input[k].y)) ||
                                ((input[j].x == input[k].x) && (input[j].y > input[k].y) &&
                                (input[i].x == input[k].x) && (input[i].y < input[k].y)) 
                            ))
                        {
                            over = true;
                            below = true;
                            break;
                        }
                    }
                }
                
            }
            if (!(below && over))
            {
                output[indexer].a = input[i];
                output[indexer].b = input[j];
                // printf("true\n");
                // printf("%f %f\n", input[i].x, input[i].y);
                // printf("%f %f\n", input[j].x, input[j].y);
                indexer++;
            }
            over = false;
            below = false;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    for (int i = 0; i < indexer; i++)
    {
        if (i == 0 && indexer != 1)
        {
            printf("[(%f,%f),(%f,%f),", output[i].a.x, output[i].a.y, output[i].b.x, output[i].b.y);
        }
        else if((i > 0) && (i != indexer-1))
        {
            printf("(%f,%f),", output[i].b.x, output[i].b.y);
        }
        else if (indexer == 1)
        {
             printf("[(%f,%f),(%f,%f)]\n", output[i].a.x, output[i].a.y, output[i].b.x, output[i].b.y);
        }
           
        else
        {
            printf("(%f,%f)]\n", output[0].a.x, output[0].a.y);
        }
        
        
    }
    printf("%f", time_spent);
    return 0;
}