#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


/*for user defined paths to the soundfile to play and the software to play it with. The user can edit config.h paths*/
#include "config.h"


/*Checking date = hh:mm and are numerical values*/
void date_regex(char *buf)
{
	int byte_length = (int)strlen(buf);
	int length=0;
	
	if(byte_length!=5)
	{
		printf("[!]insufficient number of characters\n.");
		exit(EXIT_FAILURE);
	}
	else if(byte_length==5)
	{
	
		if((buf[0]-'0'<0 || buf[0]-'0'>9) || (buf[1]-'0'<0 || buf[1]-'0'>9))
		{
			printf("[!]hh must be numerical characters.\n");
			exit(EXIT_FAILURE);
		}
		if(buf[2]!=':')
		{
			printf("[!]Incorrect format.[+]\'hh:mm\'\n");
			exit(EXIT_FAILURE);
		}

		if((buf[3]-'0'<0 || buf[3]-'0'>9) && (buf[4]-'0'<0 || buf[4]-'0'>9))
		{
			printf("[!]mm must be numerical characters.\n");
			exit(EXIT_FAILURE);
		}
		if(((buf[3]-'0') * 10)+(buf[4]-'0')>=60)
		{
			printf("[!]mm must be less than 60.\n");
			exit(EXIT_FAILURE);
		}
		
	}

}

/*convert the "hh:mm" string to their total minutes*/
int convert_to_minutes(char *buf)
{
	/*hh will be in base 10 and base 1*/
	int hour[2];
	hour[0]=buf[0]-'0';hour[1]=buf[1]-'0';

	int t_minutes = ((hour[0]*10) + hour[1]) * 60;

	/*mm next*/
	int minutes[2];
	minutes[0]=buf[3]-'0';minutes[1]=buf[4]-'0';


	t_minutes+=((minutes[0]*10) + minutes[1]);

	printf("total minutes=%d\n",t_minutes);

	return t_minutes;
}

/*start the clock in the background as a daemon, so the user can close the terminal.Once we have slept
 * for the required minutes the daemon will play the soundfile.*/
void start_clock(int minutes)
{
	char command[100]="\0";
	sprintf(command,"sleep %dm",minutes);
	system(command);

	memset(command,'\0',100);
	sprintf(command,"%s %s",MPLAYER,SOUND);
	system(command);
}


int main (int argc , char **argv)
{
	/*run with no arguments to print the help menu*/
	if(argv[1]==NULL)
	{
		printf("./timer hh:mm\n");
		exit(EXIT_SUCCESS);
	}

	/*checking date format*/
	date_regex(argv[1]);
	/*converting hh:mm to minutes*/
	int minutes = convert_to_minutes(argv[1]);

	/*turning into a daemon process in / directory and starting the timer*/
	printf("[+]Timer Started in background and will play a soundfile once ended.[+]\n");
	daemon(0,0);
	start_clock(minutes);
	return 0;
}
