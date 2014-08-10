#include "converter.h"



int getinfos()
{

	int x = 0;
	scanf("%d", &x);
	switch(x)
	{
		case 1: return x; break; 
		case 2: return x; break;
		default: printf("This was not a valid option, pleas choose between:\n\t1) Seperated by a tab? \n\t2) Seperated by a newline ?\n\n\n");
			 getinfos(); 
			 break;
	}


}


int getsizes()
{
	
	int x;
	printf("How many values are in your file? \n");
	scanf("%d", &x);
	return x;

}

int getoutinfo()
{
	int x;
	printf("Do you want to have the output in \n\t1) ONE COLUMN\n\t2) ONE LINE (CAUTION! LIMITED!)\n\nPlease choose....\n");
	scanf("%d", &x);
	switch(x)
	{
		case 1: return x;break;
		case 2: return x;break;
		default: printf("This was not a valid option. Please choose another one\n"); 
			 getoutinfo();

	}


}

char* entername()
{
	printf("Please enter the Name of your .txt File like this:\n\n\t ExampleFile.txt\n");
}


int main(int argc, char* argv[])
{

	int x;
	int y;
	int size;
	float* values;
	char file_name[1024];
	char new_file_name[1024];

	printf("Hello \n");
	printf("This is version 0.01 Feel free to change and mess it up however you want \n");
	printf("So....you have some files which should be converted to a .CVS format?\n Are your files .....");

        printf("\n\n\t1) Seperated by a tab? \n\t2) Seperated by a newline ?\n\n\n Please choose 1 or 2\n");
	
	x = getinfos();
	y = getoutinfo();
	size = getsizes();
	
	values = (float*) malloc(sizeof(float) * (size +1));
	
	entername();
	scanf("%99s", &file_name[0]);	

	printf("%s", file_name);
	
	switch(x)
	{
		case 1: values = read_double_tab(file_name,size);      break; 
		case 2: values = read_double_new_line(file_name,size); break;
	}

	       printf("\n Please name the new file like this:\n Example.CVS \n");
        scanf("%99s", &new_file_name[0]);


	switch(y)
	{	
		case 1: write_double_one_line(new_file_name,values, size); break;
		case 2: write_double_one_column(new_file_name,values, size); break;
	}

	free(values);
}
