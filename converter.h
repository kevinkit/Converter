#include <stdlib.h>
#include <stdio.h>

FILE* open_file_write(char* file_name)
{
	FILE* file;
	file = fopen(file_name, "r");
	if(file != NULL)
	{
		printf("CAUTION!!! THE FILE %s WOULD BE OVERWRITTEN !!! \n",file_name);
		printf("TO CONTINUE PRESS ENTER - ELSE EXIT PROGRAM WITH strg+c \n");
	}
	fclose(file);
	file = fopen(file_name, "w+");
	if(file == NULL)
	{
		printf("Could not create file %s", file_name);
	}
	else
	{
		return file;
	}
}


FILE* open_file_read(char* file_name)
{
	FILE* file;
	file = fopen(file_name, "r");
	if(file == NULL)
	{
		printf("could not find input file %s - maybe a typo?", file_name);
		exit(1);
	}
	else
	{
		return file;
	}
}



float* read_double_tab(char* file_name, int length)
{
	FILE* file;
	float* values;
	int i = 0;
	values = (float*) malloc(sizeof(float) * (length +1));
	file = open_file_read(file_name);
	for(i=0; i < length; i++)
	{
		fscanf(file,"%f\t", &values[i]);
	}
	return values;
}

float* read_double_new_line(char* file_name, int length)
{
	FILE* file;
	float* values;
	int i = 0;
	values = (float*) malloc(sizeof(float) * (length +1));
	file = open_file_read(file_name);
	for(i=0; i < length; i++)
	{
		fscanf(file,"%f\n", &values[i]);
	}
	return values;
}

void write_double_one_column(char* file_name,float* values, int length)
{
	int i = 0;
	FILE* file;
	int x;	
	file = fopen(file_name, "r");
	if(file != NULL)
	{
		printf("CAUTION!!! THE FILE %s WOULD BE OVERWRITTEN !!! \n",file_name);
		printf("TO CONTINUE PRESS 1 - ELSE EXIT PROGRAM WITH strg+c \n");
		scanf("%d", &x);
		if(x != 1)
		{
			exit(1);
		}

	}
	

	file = fopen(file_name, "w+");
	if(file == NULL)
	{
		printf("Could not create file %s", file_name);
	}
	else
	{
		for(; i < length; i++)
		{
			fprintf(file, "%.2f;", values[i]);
		}
		fclose(file);



	}


}

void write_double_one_line(char* file_name, float* values, int length)
{
	    int i = 0;
        FILE* file;
	int x = 0;
        file = fopen(file_name, "r");
        if(file != NULL)
        {
                printf("CAUTION!!! THE FILE %s WOULD BE OVERWRITTEN !!! \n",file_name);
                printf("TO CONTINUE PRESS 1 - ELSE EXIT PROGRAM WITH strg+c \n");
        	if(x != 1)
		{
			exit(1);
		}        
        }
        file = fopen(file_name, "w+");
        if(file == NULL)
        {
                printf("Could not create file %s", file_name);
        }
        else
        {
                for(; i < length; i++)
                {
                        fprintf(file, "%.2f;\n", values[i]);
                }
                fclose(file);



        }



}

