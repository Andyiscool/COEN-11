#include<stdio.h>
struct Time{
    int month;
    int date;
    int year;
    int hours;
    int minutes;
    float seconds;
};
struct Appointment{
    char name[20];
    int duration;
    char location[40];
    struct Time DateAndTime;
};

int main(void)
{
    int size = 5;
    int totaldays;
    struct Appointment *AppointmentNameList;
    AppointmentNameList = (struct Appointment*)malloc(size * sizeof(struct Appointment));
    struct Appointment tempappointment;
    printf("Month\n");
    scanf("%d", &tempappointment.DateAndTime.month);
    if (tempappointment.DateAndTime.month > 12){
        printf("No Such Month\n");
        return;
    }
    if (tempappointment.DateAndTime.month == 1 || tempappointment.DateAndTime.month == 3 || tempappointment.DateAndTime.month == 5 || tempappointment.DateAndTime.month == 7 || tempappointment.DateAndTime.month == 8 || tempappointment.DateAndTime.month == 10 || tempappointment.DateAndTime.month == 12){
        totaldays = 31;
    }
    if (tempappointment.DateAndTime.month == 4 || tempappointment.DateAndTime.month == 6 || tempappointment.DateAndTime.month == 9 || tempappointment.DateAndTime.month == 11){
        totaldays = 30;
    }
    if ((tempappointment.DateAndTime.month) == 2){
        totaldays = 28;
    }
    printf("Day\n");
    scanf("%d", &tempappointment.DateAndTime.date);
    if (tempappointment.DateAndTime.date > totaldays){
        printf("No Such Date\n");
	return;
    }
    printf("Year\n");
    scanf("%d", &tempappointment.DateAndTime.year);
    if (tempappointment.DateAndTime.year < 2020){
        printf("This Year Has Passed\n");
        return;
    }
    printf("Hours\n");
    scanf("%d", &tempappointment.DateAndTime.hours);
    if (tempappointment.DateAndTime.hours > 23){
        printf("We only have 24 hours each day\n");
        return;
    }
    printf("Minutes\n");
    scanf("%d", &tempappointment.DateAndTime.minutes);
    if (tempappointment.DateAndTime.minutes > 60){
        printf("We only have 60 minutes in each hour\n");
        return;
    }
    printf("Seconds\n");
    scanf("%f", &tempappointment.DateAndTime.seconds);
    if (tempappointment.DateAndTime.seconds > 60){
        printf("We only have 60 seconds in each minute\n");
        return;
    }
    printf("Name\n");
    scanf("%s", &tempappointment.name[20]);
    printf("Duration\n");
    scanf("%d", &tempappointment.duration);
    printf("Location\n");
    scanf("%s", &tempappointment.location[40]);
//if (month != 1,2,3,5,7,8,10,12) {
  // totaldays = 30;
//}
printf("%s",tempappointment.name, tempappointment.location, tempappointment.duration, tempappointment.DateAndTime.month, tempappointment.DateAndTime.date, tempappointment.DateAndTime.year, tempappointment.DateAndTime.hours, tempappointment.DateAndTime.minutes, tempappointment.DateAndTime.seconds);
//scanf("%d",&date);
//if (date > totaldays){
//printf("No Such Date\n");
//return;
//}
/*struct Appointment i = {month,3};
meettime(i);
printf("%d %d", i.month, i.date);
return 0;
}
//void meettime(struct Appointment  m){

m.month++;
m.date *= 2;*/
}
