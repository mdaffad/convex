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

int main()
{
    int indexer = 0;
    bool over = false,below = false;
    int num;

    // Generate array and random point
    scanf("%d",&num);
    point input[num];
    line output[num];
    for (int i = 0; i < num; i++)
    {
        input[i].x = rand();
        input[i].y = rand();
    }
    
    // start clock time
    clock_t begin = clock();

    // Start Brute Force
    for (int i = 0; i < num-1; i++)
    {
        for (int j = i+1; j < num; j++)
        {
            float test;
            for (int k = 0; k < num; k++)
            {
                if (!( ((input[i].x == input[k].x) && (input[i].y == input[k].y)) || ( (input[j].x == input[k].x) && (input[j].y == input[k].y))))
                // There are not an identical-pair point
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
                        // Collinier test
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
                            // If not satisfy the Collinier test
                            over = true;
                            below = true;
                        }
                    }
                    if (over && below)
                    {
                        // Two region plane has been filled with point
                        break;
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

    // end clock
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    

    // print result
    printf("\n\n");
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
    printf("\ntime spent : %f\n", time_spent);
    return 0;
}