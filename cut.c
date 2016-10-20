/* execute program ex: ./cut -c 4 filename*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "help.h"
void help();
int main(int argc, char *argv[]) {
	/* Pointer to the file */
	FILE *fp1;
	int i=1, j=1, val;
	/* Character variable to read the content of file */
	char c;
	if(argc == 1) {
    		printf("./cut: invalid byte, character or field list\n");
    		printf("Try 'cut --help' for more information.\n");
    		return 0;
    	}
	/* option for cut --help */
	if(strcmp(argv[1], "--help") == 0) {
    		help();
		return 0;
    	}
    	if(argc == 4 && argv[1] && argv[2] && argv[3]) {
    	    		val = atoi(argv[2]);
      			/* Opening a file in r mode*/
     			fp1= fopen (argv[3], "r");
     			if(!fp1) {
	 			printf("cut: %s: No such file or directory\n",argv[4]);
	 			return 0;
			}
			/* for option cut -c */
     			if(strcmp(argv[1], "-c") == 0) {
					while((c = fgetc(fp1)) != EOF) {
						
						if(c == '\n') {
							i = 1;
							printf("%c", c);
							continue;
						}
						if(i == val) {
							printf("%c", c);
							
						}
						i++;
					}
			}
	}
	
	/* for option cut -c -2 filename */
	else if(argc == 5 && argv[1] && argv[2] && argv[3] && argv[4]) {
    	  		val = atoi(argv[3]);
    	    		//printf("%d\n",val);
      			/* Opening a file in r mode*/
     			fp1= fopen (argv[4], "r");
     			if(!fp1) {
	 			printf("cut: %s: No such file or directory\n",argv[4]);
	 			return 0;
			}
			
     			if(strcmp(argv[1], "-c") == 0) {
     				if(strcmp(argv[2], "-") == 0) {
					while((c = fgetc(fp1)) != EOF) {
						//printf("\t%d %c %d\n", j, c, c);
						if(c == 10) {
							j = 1;
							i = i + 1;
							printf("\n");
							continue;
						}
						if(j > val) {
							j++;
							continue;
						}
						printf("%c", c);
					j++;
					//printf("%c", c);
						
					}
				}
			}
	}
	else {
		printf("./cut: invalid byte, character or field list\n");
    		printf("Try 'cut --help' for more information.\n");
    		return 0;
	}
	/* for option cut -c 2 - filename */
	/*else if(argc == 5) {
    	    		val = atoi(argv[2]);
    	    		printf("%d\n",val);
      			Opening a file in r mode
     			fp1= fopen (argv[4], "r");
     			if(!fp1) {
	 			printf("cut: %s: No such file or directory\n",argv[4]);
	 			return 0;
			}
			
     			if(strcmp(argv[1], "-c") == 0) {
     				if(strcmp(argv[3], "-") == 0) {
					while((c = fgetc(fp1)) != EOF) {
						printf("\t%d %c %d\n", j, c, c);
						if(c == 10) {
							j = 1;
							i = i + 1;
							printf("\n");
							continue;
						}
						if(j < val) {
							j++;
							continue;
						}
						printf("%c", c);
					j++;
					printf("%c", c);
				
					}
				}
			}
	}*/				
			/* for option cut -f */
			/*else if(strcmp(argv[1], "-f") == 0) {
					while((c = fgetc(fp1)) != EOF) {
						if(c != '\t') {
						printf("%c", c);
						j++;
						}
						if(c == '\n') {
							if(i == val)
									break;
							j = 1;
							i = i + 1;
							continue;
						}
		
					}
			}*/
					
	
	fclose(fp1);	
	return 0;
}
