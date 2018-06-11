#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define D 3


typedef struct{
    double vec[D];
}Vector;
/*ベクトルを入力する*/
/*Vector InputVector()
{
    int f;
    Vector vec;
    for (f = 0; f < D; f++)
    {
        printf("Input Vector[%d]: ", f + 1);
        scanf("%lf", &(vec.vec[f]));
    }
    return vec;
}*/
/*引数の二つのベクトルの和を計算する*/
Vector *AdditionVec(Vector vec1, Vector vec2)
{
    int f;
    Vector *sum;
    for (f = 0; f < D; f++)sum->vec[f] = vec1.vec[f] + vec2.vec[f];
    printf("a\n");
    return sum;
}
/*引数の二つのベクトルの差を計算する*/
Vector *SubtractionVec(Vector vec1, Vector vec2)
{
    int f;
    Vector *sum;
    for (f = 0; f < D; f ++)sum -> vec[f] = vec1.vec[f] - vec2.vec[f];
    return sum; 
}
/*引数二つのベクトルで構成された角度のcosを計算する*/
double AngelVec(Vector vec1, Vector vec2)
{
    int f, g;
    double sum_cos, internal_vec, product_vec, vec1_sum = 0, vec2_sum = 0;
    for (f = 0; f < D; f++)internal_vec += vec1.vec[f] * vec2.vec[f];
    for (f = 0; f < D; f++)vec1_sum += vec1.vec[f] * vec1.vec[f];
    vec1_sum = sqrt(vec1_sum); 
    for (f = 0; f < D; f++)vec2_sum += vec2.vec[f] * vec2.vec[f];
    vec2_sum = sqrt(vec2_sum); 
    product_vec = vec1_sum * vec2_sum;
    sum_cos = internal_vec / product_vec;
    return sum_cos;
}
/*ベクトルの大きさを計算する*/
double ValueVector(Vector vec)
{
    int f;
    double sum;
    for (f = 0; f < D; f++)sum += vec.vec[f] * vec.vec[f];
    return sqrt(sum);
}
/*ベクトルを表示する*/
void PrintVector(Vector vec)
{
    int f;
    for (f = 0; f < D; f++)printf("%f ", vec.vec[f]);
    return;
}

int main()
{
    Vector *vec, minAdd[2], minSub[2], minAng[2], *minaddA, *minsubA;
    double minadd, minsub, minang;
    int n, f, g;
    printf("Input n: ");
    scanf("%d", &n); 
    if (n < 2)
    {
        printf("Input Error\n");
        return 0;
    }
    vec = (Vector *)malloc(n * sizeof(Vector));
    if (vec == NULL)
    {
        printf("Memory Error\n");
        return 0;
    }
    for (f = 0; f < n; f++)
    {
        printf("Input %d.Vector\n", f + 1);
        //vec[f] = InputVector();
        for (g = 0; g < D; g++)
        {
            printf("Input Vector[%d]: ", g + 1);
            scanf("%lf", &(vec[f].vec[g]));
        }
    }
    for (f = 0; f < n; f++)
    {
        for (g = 0; g < n; g++)
        {
            minaddA = AdditionVec(vec[f], vec[g]);
            minsubA = SubtractionVec(vec[f], vec[g]);
            if (f == 0 && g == 0)
            {
                minadd = ValueVector(*minaddA);
                minAdd[0] = vec[f];
                minAdd[1] = vec[g];
                minsub = ValueVector(*minsubA);
                minAng[0] = vec[f];
                minAng[1] = vec[g];
                minang = AngelVec(vec[f], vec[g]);
                minAng[0] = vec[f];
                minAng[1] = vec[g];
                continue;
            }
            if (minadd > ValueVector(*minaddA))
            {
                minadd = ValueVector(*minaddA);
                minAdd[0] = vec[f];
                minAdd[1] = vec[g];
            }
            if (minsub > ValueVector(*minaddA))
            {
                minsub = ValueVector(*minaddA);
                minAng[0] = vec[f];
                minAng[1] = vec[g];
            }
            if (minang > AngelVec(vec[f], vec[g]))
            {
                minang = AngelVec(vec[f], vec[g]);
                minAng[0] = vec[f];
                minAng[1] = vec[g];
            }
        }
    }
    printf("Addition:(");
    PrintVector(minAdd[0]);
    printf(", ");
    PrintVector(minAdd[1]);
    printf(" )\n");

    free(vec);
    return 0;
}