#include <stdio.h>
#include "stats.h"
#include <math.h>


void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct Stats compute_statistics(const float* numberset, int setlength)
 {
    struct Stats s;
    int i,j,k;
    float sum = 0.0, avg = 0.0;
    float temp=0;
    s.average = 0;
    s.min = 0;
    s.max = 0;

    int  stub_Val = 0;
   float numset[setlength-1];
   
    if(setlength == 0)
    {
        //printf("Number set array has zero elements\n");
        s.average = 0;
        s.min = 0;
        s.max = 0;
        return s;
    }
// calculation of avg of given aray
    for(i=0; i < setlength; i++)
    {
        sum = sum + numberset[i];
    }
    
    avg = (sum)/(setlength);

// sorting given array
   for (i=0;i<setlength-1;i++)
    {
        stub_Val=i;
        for (j=i+1;j<setlength;j++)
        {
            if (numset[j]<numset[stub_Val])
            {
                stub_Val=j;
            }
        }

        swap(&numset[stub_Val], &numset[i]);   
    }
    s.average = avg;
    s.max = numset[setlength-1]; 
    s.min = numset[0]; 
return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void)
{
    emailAlertCallCount++;
}

void ledAlerter(void)
{
    ledAlertCallCount++;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold )
    {
        alerters[0]();
        alerters[1]();
    }
}
