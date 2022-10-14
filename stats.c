#include "stats.h"

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

    int index = 0;
    int i,j,k;
    int count = 0;
    float add = 0.0;
    float numset[setlength-1];
    
    for(count=0; count<setlength;count++)
    {
        numset[count] = numberset[count]; 
    }

    for(k=0;k<setlength;k++)
    {
        add = add + numset[k];
    }

    s.average = (float) add/ setlength;   

    for (i=0;p<setlength-1;i++)
    {
        index=i;
        for (j=i+1;j<setlength;j++)
        {
            if (numset[j]<numset[index])
            {
                index=j;
            }
        }

        swap(&numset[index], &numset[p]);  
    }
    s.max = numset[setlength-1];           
    s.min = numset[0];                         


    return s;   // added Missing return Value
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
