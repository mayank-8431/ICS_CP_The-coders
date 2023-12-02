#include <stdio.h>
#include <math.h>

// Function to solve a pair of linear equations
void pair_linear(int *a1, int *b1, int *c1, int *a2, int *b2, int *c2) {
   if (*a1 / (*a2) == *b1 / (*b2) && *c1 / (*c2) == *b1 / (*b2) && *a1 / (*a2) == *c1 / (*c2) ) {
        printf("There are infinitely many solutions of x and y.\n \n \n");
    } else if (*a1 / (*a2) == *b1 / (*b2) && *c1 / (*c2) != *a1 / (*a2) && *b1 / (*b2) != *c1 / (*c2)) {
        printf("There are no possible solutions of x and y.\n \n \n");
    } else {
        int x, y;
        int p = (-(*c1));
        int q = (-(*c2));
        float dell = (*a1) * (*b2) - (*b1) * (*a2);
        float dell_1 = p * (*b2) - q * (*b1);
        float dell_2 = (*a1) * q - (*a2) * p;
        float s = (dell_1) / (dell);
        float t = (dell_2) / (dell);

        printf("The value of x is %f\n", s);
        printf("The value of y is %f\n \n \n", t);
    }
}


// Function to solve a quadratic equation
void solveQuadratic(double *a, double *b, double *c, double *x1, double *x2) {
   double discriminant = (*b) * (*b) - 4 * (*a) * (*c);

    if (discriminant > 0) {
        *x1 = (-(*b) + sqrt(discriminant)) / (2 * (*a));
        *x2 = (-(*b) - sqrt(discriminant)) / (2 * (*a));
        printf("Two real roots: x1 = %.5f and x2 = %.5f\n \n \n", *x1, *x2);
    } else if (discriminant == 0) {
        *x1 = -(*b) / (2 * (*a));
        *x2 = *x1;
        printf("Repeated real roots: x1 = x2 = %.5f\n \n \n", *x1);
    } else {
        double realPart = -(*b) / (2 * (*a));
        double imaginaryPart = sqrt(-discriminant) / (2 * (*a));
        printf("Complex roots: x1 = %.5f + %.5fi and x2 = %.5f - %.5fi\n \n \n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

// Function to solve a linear equation
void solveLinearEquation(float *a, float *b, float *solution) {
    if (*a == 0) {
        if (*b == 0) {
            printf("Infinite solutions (identity)\n \n \n");
        } else {
            printf("No solution (contradiction)\n \n \n");
        }
    } else {
        *solution = -(*b) / (*a);
        printf("The solution for x is: %f\n \n \n", *solution);
    }
}

// Function to solve three linear equations in three variables
void three_var(int a[3][3], int num[3][1], float result[3][1]) {
    printf("The first equation is %dx+%dy+%dz=%d\n",a[0][0],a[0][1],a[0][2],num[0][0]);
    printf("The second equation is %dx+%dy+%dz=%d\n",a[1][0],a[1][1],a[1][2],num[1][0]);
    printf("The third equation is %dx+%dy+%dz=%d\n",a[2][0],a[2][1],a[2][2],num[2][0]);
   
    int c1,c2,c3,c4,c5,c6,c7,c8,c9,j1,j2,j3;
    c1=((a[1][1]*a[2][2])-(a[1][2]*a[2][1]));
    c2=-((a[1][0]*a[2][2])-(a[1][2]*a[2][0]));
    c3=((a[1][0]*a[2][1])-(a[1][1]*a[2][0]));
    c4=-((a[0][1]*a[2][2])-(a[0][2]*a[2][1]));
    c5=((a[0][0]*a[2][2])-(a[0][2]*a[2][0]));
    c6=-((a[0][0]*a[2][1])-(a[0][1]*a[2][0]));
    c7=((a[0][1]*a[1][2])-(a[0][2]*a[1][1]));
    c8=-((a[0][0]*a[1][2])-(a[0][2]*a[1][0]));
    c9=((a[0][0]*a[1][1])-(a[0][1]*a[1][0]));
    int dell=(a[0][0]*c1)+(a[0][1]*c2)+(a[0][2]*c3);
    int dell_2=(num[0][0]*c1)+(num[1][0]*c4)+(num[2][0]*c7);
    int dell_3=(num[0][1]*c2)+(num[1][1]*c5)+(num[2][1]*c8);
    int dell_4=(num[0][2]*c3)+(num[1][2]*c6)+(num[2][2]*c9);
    float d1=c1/(float)dell;
    float d2=c2/(float)dell;
    float d3=c3/(float)dell;
    float d4=c4/(float)dell;
    float d5=c5/(float)dell;
    float d6=c6/(float)dell;
    float d7=c7/(float)dell;
    float d8=c8/(float)dell;
    float d9=c9/(float)dell;
    float b[3][3]={{d1,d4,d7},
                 {d2,d5,d8},
                 {d3,d6,d9}};
        if(dell==0 && dell_2==0 && dell_3==0 && dell_4==0){
            printf("The matrix of coefficints is non invertible\n");
            printf("The Equation has infinite solutions\n \n \n");
        }
        if(dell==0 && (dell_2!=0 || dell_3!=0 || dell_4!=0)){
            printf("The matrix of coefficients is non invertible\n");
            printf("The Equation has no solution\n \n \n");
        }
        if (dell!=0){
            printf("1. Type 1 to check inverse of coefficients\n");
    printf("2. Type 2 for Solution of Linear equation in three variable\n");
    printf("Enter your choice\n");
    int choice;
    scanf("%d",&choice);
        switch(choice){
            case 1:
                 printf("The inverse of coefficients matrix is\n");
    for(int i=0;i<3;i++){//
        for(int j=0;j<3;j++){
           printf("%f ",b[i][j]) ;
        }
        printf("\n");
    }             
  break;
   case 2:
    float sum=0;
    for (int i=0;i<3;i++){        
        for (int j=0;j<1;j++){ 
            for (int k=0;k<3;k++){
                sum+=b[i][k] * num[k][j];}
                result[i][j]=sum;
                sum=0; 
                }
    
}
printf("The value of x is %f\n",result[0][0]);
printf("The value of y is %f\n",result[1][0]);
printf("The value of z is %f\n \n \n",result[2][0]);
    break;
        }
            }

}

int main() {
    while(1){int choice;

    printf("Select the type of equation:\n");
    printf("1. Pair of linear equations (a1x + b1y + c1 = 0 and a2x + b2y + c2 = 0)\n");
    printf("2. Quadratic equation (ax^2 + bx + c = 0)\n");
    printf("3. Linear equation (ax + b = 0)\n");
    printf("4. Three linear equations in three variables\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int a1, b1, c1, a2, b2, c2;
            printf("Enter the value of a1\n");
            scanf("%d", &a1);
            printf("Enter the value of b1\n");
            scanf("%d", &b1);
            printf("Enter the value of c1\n");
            scanf("%d", &c1);
            printf("Enter the value of a2\n");
            scanf("%d", &a2);
            printf("Enter the value of b2\n");
            scanf("%d", &b2);
            printf("Enter the value of c2\n");
            scanf("%d", &c2);

            printf("The 1st equation is %dx+%dy+%d=0\n", a1, b1, c1);
            printf("The 2nd equation is %dx+%dy+%d=0\n", a2, b2, c2);

            pair_linear(&a1, &b1, &c1, &a2, &b2, &c2);
            break;
        }
        case 2: {
            double a, b, c;
            printf("Enter the value of a\n");
            scanf("%lf", &a);
            printf("Enter the value of b\n");
            scanf("%lf", &b);
            printf("Enter the value of c\n");
            scanf("%lf", &c);

            double root1, root2;
            solveQuadratic(&a, &b, &c, &root1, &root2);
            break;
            
        }
        case 3: {
            
             float a, b, solution;
            printf("Enter the coefficient 'a': ");
            scanf("%f", &a);
            printf("Enter the constant term 'b': ");
            scanf("%f", &b);

            solveLinearEquation(&a, &b, &solution);
            break;
        }
        case 4: {
            
            int coeff[3][3],cons[3][1];
            float product[3][1];
    
            printf("Enter the coefficients\n");
            for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&coeff[i][j]);
        }
    }
    printf("Enter the constants\n");
    for (int i=0;i<3;i++){
        for(int j=0;j<1;j++){
            scanf("%d",&cons[i][j]);
        }
    }
    
    three_var(coeff,cons,product);
        
        }
        break;
        default:
            printf("Invalid choice.\n");
    }
    }
    return 0;}
