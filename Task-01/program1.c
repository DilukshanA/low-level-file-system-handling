/* Task 01
reate a text file named as doc1.txt and write name and age the user input using
standard input to doc1.txt with possible error handling. If doc1.txt exists; the
program should truncate it and rewrite
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	int size;
	printf("\n Enter size of your name: ");
	scanf("%d", &size);
	char name[size];
	printf("\n Enter your name: ");
	scanf("%s", name);
	char age[2];
	printf("\n Enter your age: ");
	scanf("%s", age);
	
	int fd1 = open("./doc1.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
	
	if(fd1 == -1) // error -1
	{
		perror("doc1.txt"); // perror pass the file name as the character
		printf("\n File could not be opened successfully. Error number is %d", errno);
		exit(0); // if it has error should be exit
	}
	else
	{
		printf("\n File opened successfully.");
		char buf[11] = "My Name is ";
		int bytes_written = write(fd1, (void *)buf, 11); //fd1 is the file descriptor //return no. of bytes writen to the file
		int bytes_written1 = write(fd1, (void *)name, size);
		
		char buf1[8] = " Age is ";
		int bytes_written2 = write(fd1, (void *)buf1, 8);
		int bytes_written3 = write(fd1, (void *)age, 2);
		
		if(bytes_written3 == -1)
		{
			perror("doc1.txt");
			printf("\n Couldn't write to the file successfully, Error number is %d", errno);
			exit(0); 				
		}
		else
		{
			printf("\n Written to the file successfully.");
			close(fd1);
		}
	}

	return(0);
}

