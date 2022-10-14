struct Stats compute_statistics 
{
    float average;
    float min;
    float max;
};
struct Stats compute_statistics(const float* numberset, int setlength);
extern int emailAlertCallCount;
extern int ledAlertCallCount;

/*void emailAlerter(float maxThreshold, struct Stats *sp);
void ledAlerter(float maxThreshold, struct Stats *sp);
*/
void emailAlerter(void);
void ledAlerter(void)

void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

//void (*check_and_alert[])(float maxThreshold, struct Stats *ptr)={emailAlerter, ledAlerter};

