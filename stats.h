struct Stats 
{
    float average;
    float min;
    float max;
};

struct Stats compute_statistics(const float* numberset, int setlength);
typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
void emailAlerter(void);
void ledAlerter(void);

/*void emailAlerter(float maxThreshold, struct Stats *sp);
void ledAlerter(float maxThreshold, struct Stats *sp);
*/
//void (*check_and_alert[])(float maxThreshold, struct Stats *ptr)={emailAlerter, ledAlerter};

