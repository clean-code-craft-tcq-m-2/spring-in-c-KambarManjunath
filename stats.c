#include <stdio.h>
#include "stats.h"
#include <math.h>



struct Stats compute_statistics(const float* numberset, int setlength)
 {
    struct Stats s;
    int i;
    float sum = 0.0, avg = 0.0;
    float temp=0;
    s.average = 0;
    s.min = 0;
    s.max = 0;

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
    for(i=0; i < setlength; i++)
    {
        if(numberset[i] > numberset[i+1])
        {
            temp = numberset[i];
            numberset[i] = numberset[i+1];
            numberset[i] = temp;
        }
        
    }
    s.average = avg;
    s.min = numberset[0];
    s.max = numberset[setlength-1];

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
