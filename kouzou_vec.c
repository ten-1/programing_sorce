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
    
    Vector *addtive_result = (Vector *)malloc(sizeof(Vector));
    for (int f = 0; f < D; f++)
    {
        addtive_result->vec[f] = vec1.vec[f] + vec2.vec[f];
    }
    return addtive_result;
}
/*引数の二つのベクトルの差を計算する*/
Vector *SubtractionVec(Vector vec1, Vector vec2)
{
    int f;
    Vector *sum;
    sum = (Vector *)malloc(sizeof(Vector));
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

    Vector min_addtive_vectors[2];
    Vector min_subtract_vectors[2];
    Vector min_cos_angle_vectors[2];
    float min_addtive_vector_magnitude = MAXFLOAT;
    float min_subtract_vector_magnitude = MAXFLOAT;
    float min_cos_angle = MAXFLOAT;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            /** 同じVector要素は見る必要がない **/
            if(i == j)
            {
                continue;
            }

        /** 加算比較 **/
           Vector*  addtive_vec = AdditionVec(vec[i],vec[g]);
            float vector_magunitude = ValueVector(*addtive_vec);
            if(min_addtive_vector_magnitude > vector_magunitude)
            {
                min_addtive_vector_magnitude = (float)vector_magunitude;
                min_addtive_vectors[0] = vec[i];
                min_addtive_vectors[1] = vec[g];
            }
            free(addtive_vec);

        /** 減算比較 **/
            Vector*  subtract_vec = SubtractionVec(vec[i],vec[g]);
            vector_magunitude = ValueVector(*subtract_vec);
            if(min_subtract_vector_magnitude > vector_magunitude)
            {
                min_subtract_vector_magnitude = (float)vector_magunitude;
                min_subtract_vectors[0] = vec[i];
                min_subtract_vectors[1] = vec[j];
            }
            free(addtive_vec);

        /** 角度比較 **/
            float angle = AngelVec(vec[i],vec[g]);            
            if(min_cos_angle > angle)
            {
                min_cos_angle = (float)angle;
                min_cos_angle_vectors[0] = vec[i];
                min_cos_angle_vectors[1] = vec[j];
            }

        }
    }

    printf("Addition:(");
    PrintVector(minAdd[0]);
    printf(", ");
    PrintVector(minAdd[1]);
    printf(" )\n");

    printf("Submition:(");
    PrintVector(minSub[0]);
    printf(", ");
    PrintVector(minSub[1]);
    printf(" )\n");

    printf("cos:(");
    PrintVector(minAng[0]);
    printf(", ");
    PrintVector(minAng[1]);
    printf(" )\n");

    free(vec);
    return 0;
}
