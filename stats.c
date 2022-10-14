#include "stats.h"

/* fucntion to swap the contents of a variable*/
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

    int stub_Val = 0;
    int p,q,r;
    int count = 0;
    float add = 0.0;
    float numset[setlength-1];
    
    /*-------------To calculate Average-------------------*/
    for(count=0; count<setlength;count++)
    {
		/*Inputs taken from the stats-test.cpp to read the numberset. */
        numset[count] = numberset[count]; 
    }

    for(r=0;r<setlength;r++)
    {
        add = add + numset[r];
    }

    s.average = (float) add/ setlength;   // For, TEST_CASE("reports average, minimum and maximum")


    /*-------------To calculate Min and Max-------------------*/

    for (p=0;p<setlength-1;p++)
    {
        stub_Val=p;
        for (q=p+1;q<setlength;q++)
        {
            if (numset[q]<numset[stub_Val])
            {
                stub_Val=q;
            }
        }

        swap(&numset[stub_Val], &numset[p]);   // Pass by address.
    }
    s.max = numset[setlength-1];               //TEST_CASE("reports average, minimum and maximum")
    s.min = numset[0];                         //TEST_CASE("reports average, minimum and maximum")


    return s;   // added Missing return Value
}


/* Adding function for Test case : raises alerts when max is greater than threshold */
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
