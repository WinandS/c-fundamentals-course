#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct relative_time relative_time;

void print(relative_time const * rt);
int check_invariants(relative_time const * rt);
relative_time * rt_init(int days, int hours, int minutes, int seconds);
relative_time * rt_add(relative_time const * a, relative_time const * b);
relative_time * rt_substract(relative_time const * a, relative_time const * b);
relative_time * rt_read();

int h = 24,m = 60,s=60;

struct relative_time{
	int days;
	int hours;
	int minutes;
	int seconds;

};

int main(int argc, char * argv[]){
	relative_time * a = rt_read();
	relative_time * b = rt_read();
	relative_time * sum = rt_add(a,b);
	relative_time * diff = rt_substract(a,b);
	print(sum);
	print(diff);
	free(sum);
	free(diff);
}


relative_time * rt_init(int days, int hours, int minutes, int seconds){
                relative_time * rt = malloc(sizeof(relative_time));
                rt->days=days;
                rt->hours=hours;
                rt->minutes=minutes;
                rt->seconds=seconds;
		check_invariants(rt);	
		return rt;
        };

int check_invariants(relative_time const * rt){
	assert(rt->hours<h &&"Too Many hours.");
	assert(rt->minutes<m && "Too Many minutes.");
	assert(rt->seconds<s && "Too Many seconds.");
	return 0;
        };

void print(relative_time const * rt){
	printf("{ days: %i; hours: %i; minutes: %i; seconds: %i; }\n",rt->days,rt->hours,rt->minutes,rt->seconds);
	return;
}

relative_time * rt_add(relative_time const * a, relative_time const * b){
	relative_time * sum = malloc(sizeof(relative_time));
	sum->days = a->days+b->days;
	
	sum->hours = a->hours+b->hours;
	if(sum->hours>h){
                int times = sum->hours/h;
		printf("test %i\n",times);
                sum->hours-=times*h;
                sum->days+=times;
        }

	sum->minutes = a->minutes+b->minutes;
        if(sum->minutes>m){
                int times = sum->minutes/m;
                sum->minutes-=times*m;
                sum->hours+=times;
        }

	sum->seconds = a->seconds+b->seconds;
	if(sum->seconds<s){
                int times = sum->seconds/s;
                sum->seconds-=times*s;
                sum->minutes+=times;
        }

	return sum;
}

relative_time * rt_substract(relative_time const * a, relative_time const * b){
	relative_time * diff = malloc(sizeof(relative_time));
	if(a->days<b->days)
		return NULL;

	diff->days = a->days - b->days;	

	diff->hours = a->hours-b->hours;
        while(diff->hours<0){
                diff->hours+=h;
                diff->days--;
        }

	diff->minutes = a->minutes-b->minutes;
        while(diff->hours<0){
                diff->minutes+=m;
                diff->hours--;
        }

	diff->seconds = a->seconds-b->seconds;
        while(diff->hours<0){
                diff->hours+=s;
                diff->days--;
	}
	return diff;

}
relative_time * rt_read(){
	int d, h, m, s;
	printf("Enter a time.\n");
	printf("Days\n");
	scanf("%d",&d);
	printf("Hours\n");
	scanf("%d",&h);
	printf("Minutes\n");
	scanf("%d",&m);
	printf("Seconds\n");
	scanf("%d",&s);
	return rt_init(d,h,m,s);
}

