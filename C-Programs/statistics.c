#include <stdio.h>
#include <math.h>
 
int main(){
    int n;
    int i,j;
    float val;
    float highest, lowest, median, mean, mode, sd, range, cv, cr,md, cmd;
    printf("Enter the frequency ");
    scanf("%d",&n);
    float x[n-1];
    float sq[n-1];
    float sum = 0;
    float sqSum=0;
    
    // input values
    printf("Enter the numbers \n");
    for(i=0;i < n;i++){
        scanf("%f",&val);
        x[i]= val;
        sq[i] = val * val;
        sum = sum + val;
        sqSum = sqSum + pow(val,2);
    };

    //finding greatest and lowest

    highest = x[0];
    lowest = x[0];
    for (i = 0; i < n; i++)
    {

        if(x[i]>highest){
            highest = x[i];
        };
        if (x[i] < lowest)
        {
            lowest = x[i];
        };
    };

    // Arrange in ascending order
    for(i = 0; i<n; i++){
        for( j = i+1 ; j<n; j++){
            if(x[i]>x[j]){
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    //Finding Median

    if(n%2==0){
        int r = (n)/2;
        median = (x[r-1]+x[r])/2;
    }else{
        int r = (n+1)/2;
        median = x[r];
    }
    
    //calculations

    mean = sum / n;
    float variance = (sqSum/n) - pow(mean,2);
    sd = sqrt(variance);
    range = highest - lowest;
    mode = 3*median - 2*mean;
    cv = sd/mean *100;
    cr = (highest - lowest) / (highest + lowest);

    float tempSum = 0;
    for(i=0;i<n;i++){
        tempSum = tempSum + abs(x[i]-mean);
    }

    md = tempSum / n;
    cmd = md/mean;


    //prinitng values
    printf("The mean is %f \n",mean);
    printf("The Mean Deviation (M.D) is %f \n", md);
    printf("The Coeff. of Mean Deviation (M.D) is %f \n", cmd);
    printf("The Median is %f \n", median);
    printf("The Mode is %f \n", mode);
    printf("The Standard Deviation (S.D) is %f \n", sd);
    printf("The Variance is %f \n", variance);
    printf("The Coeff. of variance is %f \n", cv);
    printf("The Range is %f \n", range);
    printf("The Coeff. of Range is %f \n", cr);

}
