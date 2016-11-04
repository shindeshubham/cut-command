/*************************************************************************
*   <cut_command>
*   Copyright (C) 2016  Shubham Subhash Shinde shindess16.it@coep.ac.in
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>
**************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//void help();
int main(int argc, char *argv[]) {
	/* Pointer to the file */
	FILE *fp1;
	int i=1, j=1, val, len, val1;
	/* Character variable to read the content of file */
	char c;
	/* for cut(for only one arguement) */ 
	if(argc == 1) {
    		printf("./project: you must specify a list of bytes, characters.\n");
    		printf("Try './project --help' for more information.\n");
    		return 0;
    	}
    	/* option for cut --help */
	if(strcmp(argv[1], "--help") == 0) {
    		FILE *fp;
		char c, *s="help.txt";
		fp = fopen(s,"r");
		if(fp == NULL){
			printf("cann't open file");
			exit(0);
		}
		c=fgetc(fp);
		while(c != EOF){
			printf("%c",c);
			c=fgetc(fp);
		}
		fclose(fp);
		return 0;
    	}
    	/* for cut -c or -b */
    	if(argv[0] && argv[1] && (!argv[2])) {
    		if(argv[1][1] == 'c') {
    			printf("./project : less arguement is provided\n");
    			printf("Try './project --help' for more information.\n");
    			return 0;
    		}
    		else if(argv[1][1] == 'b') {
    			printf("./project : less arguement is provided\n");
    			printf("Try './project --help' for more information.\n");
    			return 0;
    		}
    	}
    	/* for cut -c filename or cut -b filename */
    	else if(argv[0] && argv[2] && (!argv[3])) {
    		if(argv[1][1] == 'c') {
    			printf("./project: invalid byte, character position %s\n", argv[2]);
    			printf("Try './project --help' for more information.\n");
    			return 0;
    		}
    		else if(argv[1][1] == 'b') {
    			printf("./project: invalid byte, character position %s\n", argv[2]);
    			printf("Try './project --help' for more information.\n");
    			return 0;
    		}

    	}
/*-----------------------------------------------------option fob cut -c-------------------------------------------------------------*/	
    	if(argc == 4) {
		/* this code sets the case for -c option */
		if(strcmp(argv[1], "-c") == 0) {
			char *p = argv[2];
			int cas = 0;
			int count = 0;
			while(*p != '\0' ) {
				if(*p == '-') {
					if(count == 0) {
			 			cas = 1;
			 			break;
			 		}
			 		else if(count == (strlen(argv[2])-1)) {
			 			cas = 2;
			 			break;
			 		}
			 		else {
			 			cas = 3;
			 			break;
			 		}
			 		
			 	}
			 	p++;
			 	count++;
			 }
			//printf("case: %d\n", cas);
			/* end */
			switch(cas) {
		/*-------------------------------------for cut -c 13 filename----------------------------------------*/
				case 0:
					val = atoi(argv[2]);
				/*------------ if range is zero cut -c 0 filename -------------------*/
					if(val == 0) {
			    		printf("./project: byte/character positions are numbered from 1.\n");
			    		printf("Try './project --help' for more information.\n");
			    		return 0;
			    		}
	      				/* Opening a file in r mode*/
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					//printf("%d\n", len);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						if(c == '\n') {
							i = 1;
							printf("%c", c);
							continue;
							}
						if(i == val) {
							printf("%c", c);
						}
						if(i >= len) {
							break;
						}
						i++;
					}
					printf("\n");
					break;
		/*-------------------------------------for cut -c -13 filename----------------------------------------*/	
				case 1:
					count = 0;
	    	  			val1 = atoi(argv[2]);
					val = (-1)*(val1);
				/*------------ if range is zero cut -c -0 filename -------------------*/
					if(val == -0) {
			    		printf("./project: byte/character positions are numbered from 1.\n");
			    		printf("Try './project --help' for more information.\n");
			    		return 0;
			    		}
					//printf("%d\n", val);
	      				/* Opening a file in r mode*/
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					//printf("%d\n", len);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						count++;
						if(count >= len || i >= len) {
							break;
						}
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
					}
					printf("\n");
					break;
		/*-------------------------------------for cut -c 13- filename----------------------------------------*/
				case 2:
					val = atoi(argv[2]);
				/*------------ if range is zero cut -c 0- filename -------------------*/
					if(val == 0) {
			    		printf("./project: byte/character positions are numbered from 1.\n");
			    		printf("Try './project --help' for more information.\n");
			    		return 0;
			    		}
	      				/* Opening a file in r mode */
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					//printf("%d\n", len);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						count++;
						if(count >= len) {
							break;
						}
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
						//printf("%c", c);
					}
					printf("\n");
					break;
		/*-------------------------------------for cut -c 13-26 filename----------------------------------------*/
				case 3:
					/* Opening a file in r mode */
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					char *arg = argv[2];
					char a[8];
					char b[8];
					int i = 0;
					while(arg[i] != '-') {
						a[i] = arg[i];	
						i++;
					}
					a[i] = '\0';
					int n = 0;
					i++;
					while(arg[i] != '\0') {
						b[n++] = arg[i];
						i++;
					}
					val = atoi(a);
					val1 = atoi(b);
				/*---------------for val1 less than val-------------------*/
					if(val1 < val) {
						printf("./project: invalid decreasing range\n");
						printf("Try './project --help' for more information.\n");
						break;
					}
				/*------------ if range is zero cut -c 0-12 filename -------------------*/
					if(val == 0) {
						printf("./project: byte/character positions are numbered from 1\n");
						printf("Try './project --help' for more information.\n");
						break;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					//printf("%d\n", len);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						count++;
						if(count >= len) {
							break;
						}
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
						if(j > val1) {
							continue;
						}
						printf("%c", c);
						j++;
						//printf("%c", c);
					}
					printf("\n");
					break;
			}
		}
		
	}
/*----------------------------------------------------for option cut -b -----------------------------------------------------*/
	if(argc == 4) {
		/* this code sets the case for -b option */
		if(strcmp(argv[1], "-b") == 0) {
			char *p = argv[2];
			int cas = 0;
			int count = 0;
			while(*p != '\0' ) {
				if(*p == '-') {
					if(count == 0) {
			 			cas = 1;
			 			break;
			 		}
			 		else if(count == (strlen(argv[2])-1)) {
			 			cas = 2;
			 			break;
			 		}
			 		else {
			 			cas = 3;
			 			break;
			 		}
			 		
			 	}
			 	p++;
			 	count++;
			 }
			/* end */
			switch(cas) {
		/*-------------------------------------for cut -b 13 filename----------------------------------------*/
				case 0:
					val = atoi(argv[2]);
				/*------------ if range is zero cut -b 0 filename -------------------*/
					if(val == 0) {
			    		printf("./project: byte/character positions are numbered from 1.\n");
			    		printf("Try './project --help' for more information.\n");
			    		return 0;
			    		}
	      				/* Opening a file in r mode*/
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						if(c == '\n') {
							i = 1;
							printf("%c", c);
							continue;
							}
						if(i == val) {
							printf("%c", c);
						}
						if(i >= len) {
							break;
						}
						i++;
					}
					printf("\n");
					break;
		/*-------------------------------------for cut -b -13 filename----------------------------------------*/	
				case 1:
					count = 0;
	    	  			val1 = atoi(argv[2]);
					val = (-1)*(val1);
				/*------------ if range is zero cut -b -0 filename -------------------*/
					if(val == -0) {
			    		printf("./project: byte/character positions are numbered from 1.\n");
			    		printf("Try './project --help' for more information.\n");
			    		return 0;
			    		}
	      				/* Opening a file in r mode*/
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						count++;
						if(count >= len || i >= len) {
							break;
						}
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
					}
					printf("\n");
					break;
		/*-------------------------------------for cut -b 13- filename----------------------------------------*/
				case 2:
					val = atoi(argv[2]);
				/*------------ if range is zero cut -b 0- filename -------------------*/
					if(val == 0) {
			    		printf("./project: byte/character positions are numbered from 1.\n");
			    		printf("Try './project --help' for more information.\n");
			    		return 0;
			    		}
	      				/* Opening a file in r mode */
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					//printf("%d\n", len);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						count++;
						if(count >= len) {
							break;
						}
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
					}
					printf("\n");
					break;
		/*-------------------------------------for cut -b 13-26 filename ----------------------------------------*/
				case 3:
					/* Opening a file in r mode */
	     				fp1= fopen (argv[3], "r");
	     				if(!fp1) {
		 				printf("./project: %s: No such file or directory\n",argv[3]);
		 				return 0;
					}
					char *arg = argv[2];
					char a[8];
					char b[8];
					int i = 0;
					while(arg[i] != '-') {
						a[i] = arg[i];	
						i++;
					}
					a[i] = '\0';
					int n = 0;
					i++;
					while(arg[i] != '\0') {
						b[n++] = arg[i];
						i++;
					}
					val = atoi(a);
					val1 = atoi(b);
					/*---------------for val1 less than val-------------------*/
					if(val1 < val) {
						printf("./project: invalid decreasing range\n");
						printf("Try './project --help' for more information.\n");
						break; 
					}
				/*------------ if range is zero cut -b 0-12 filename -------------------*/
					if(val == 0) {
						printf("./project: byte/character positions are numbered from 1\n");
						printf("Try './project --help' for more information.\n");
						break;
					}
					fseek(fp1, 0L, SEEK_END);
					len = ftell(fp1);
					fseek(fp1, 0L, SEEK_SET);
					while((c = fgetc(fp1)) != len) {
						count++;
						if(count >= len) {
							break;
						}
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
						if(j > val1) {
							continue;
						}
						printf("%c", c);
						j++;
					}
					printf("\n");
					break;
			}
		}
		
	}
	/*-------------------------------------------------for option cut -b/-c complement --------------------------------------------*/
	if(argc == 5) {
		if(strcmp(argv[4], "--complement") == 0) {
			/* this code sets the case for --coplement option */
			if(strcmp(argv[1], "-b") == 0 || strcmp(argv[1], "-c") == 0) {
				char *p = argv[2];
				int cas = 0;
				int count = 0;
				while(*p != '\0' ) {
					if(*p == '-') {
						if(count == 0) {
			 				cas = 1;
			 				break;
			 			}
			 			else if(count == (strlen(argv[2])-1)) {
			 				cas = 2;
			 				break;
			 			}
			 			else {
			 				cas = 3;
			 				break;
			 			}
			 		
			 		}
			 		p++;
			 		count++;
			 	}
				/* end */
				switch(cas) {
		/*-------------------------------------for cut -b/-c 13 filename --complement  --------------------------------------*/
					case 0:
						val = atoi(argv[2]);
				/*------------ if range is zero cut -b/-c 0 filename --complement -------------------*/
						if(val == 0) {
					    		printf("./project: byte/character positions are numbered from 1.\n");
					    		printf("Try '/project --help' for more information.\n");
					    		return 0;
				    		}
		      				/* Opening a file in r mode*/
		     				fp1= fopen (argv[3], "r");
		     				if(!fp1) {
			 				printf("./project: %s: No such file or directory\n",argv[3]);
			 				return 0;
						}
						fseek(fp1, 0L, SEEK_END);
						len = ftell(fp1);
						fseek(fp1, 0L, SEEK_SET);
						int count = 0;
						while(count != len) {
							c = fgetc(fp1);
							if(c == '\n') {
								i = 1;
								printf("%c", c);
								count++;
								continue;
								}
							if(i == val) {
								i++;
								count++;
								continue;
							}
							if(i >= len) {
								count++;
								break;
							}
							count++;
							i++;
							printf("%c", c);
						}
						printf("\n");
						break;
		/*-------------------------------------for cut -b/-c -13 filename --complement  -------------------------------------*/	
					case 1:
						count = 0;
		    	  			val1 = atoi(argv[2]);
						val = (-1)*(val1);
					/*------------ if range is zero cut -b/-c -0 filename --complement -------------------*/
						if(val == -0) {
				    		printf("./project: byte/character positions are numbered from 1.\n");
				    		printf("Try './project --help' for more information.\n");
				    		return 0;
				    		}
		      				/* Opening a file in r mode*/
		     				fp1= fopen (argv[3], "r");
		     				if(!fp1) {
			 				printf("./project: %s: No such file or directory\n",argv[3]);
			 				return 0;
						}
						fseek(fp1, 0L, SEEK_END);
						len = ftell(fp1);
						fseek(fp1, 0L, SEEK_SET);
						count = 0;
						while(count != len) {
						c = fgetc(fp1);
						if(c == '\n') {
							i = 1;
							printf("%c", c);
							count++;
							continue;
							}
						if(i > val) {
							printf("%c", c);
							count++;
							continue;
						}
						if(i >= len) {
							count++;
							break;
						}
						i++;
						count++;
						}
						printf("\n");
						break;
		/*-------------------------------------for cut -b 13- filename --complement --------------------------------------*/
					case 2:
						val = atoi(argv[2]);
					/*------------ if range is zero cut -b/-c 0- filename --coplement -------------------*/
						if(val == 0) {
				    		printf("./project: byte/character positions are numbered from 1.\n");
				    		printf("Try './project --help' for more information.\n");
				    		return 0;
				    		}
		      				/* Opening a file in r mode */
		     				fp1= fopen (argv[3], "r");
		     				if(!fp1) {
			 				printf("./project: %s: No such file or directory\n",argv[3]);
			 				return 0;
						}
						fseek(fp1, 0L, SEEK_END);
						len = ftell(fp1);
						//printf("%d\n", len);
						fseek(fp1, 0L, SEEK_SET);
						while((c = fgetc(fp1)) != len) {
						count++;
						if(count >= len || i >= len) {
							break;
						}
						if(c == 10) {
							j = 1;
							i = i + 1;
							printf("\n");
							continue;
						}
						if(j >= val) {
							j++;
							continue;
						}
						printf("%c", c);
						j++;
						}
						printf("\n");
						break;
		/*-------------------------------------for cut -b 13-26 filename --complement --------------------------------------*/
					case 3:
						/* Opening a file in r mode */
		     				fp1= fopen (argv[3], "r");
		     				if(!fp1) {
			 				printf("./project: %s: No such file or directory\n",argv[3]);
			 				return 0;
						}
						char *arg = argv[2];
						char a[8];
						char b[8];
						int i = 0;
						while(arg[i] != '-') {
							a[i] = arg[i];	
							i++;
						}
						a[i] = '\0';
						int n = 0;
						i++;
						while(arg[i] != '\0') {
							b[n++] = arg[i];
							i++;
						}
						val = atoi(a);
						val1 = atoi(b);
						/*---------------for val1 less than val-------------------*/
						if(val1 < val) {
							printf("./project: invalid decreasing range\n");
							printf("Try './project --help' for more information.\n");
							break;
						}
					/*------------ if range is zero cut -b/-c 0-12 filename --coplement -------------------*/
						if(val == 0) {
							printf("./project: byte/character positions are numbered from 1\n");
							printf("Try './project --help' for more information.\n");
							break;
						}
						fseek(fp1, 0L, SEEK_END);
						len = ftell(fp1);
						fseek(fp1, 0L, SEEK_SET);
						while((c = fgetc(fp1)) != len) {
							count++;
							if(count >= len) {
								break;
							}
							if(c == 10) {
								j = 1;
								i = i + 1;
								printf("\n");
								continue;
							}
							if(j < val) {
								printf("%c", c);
								j++;
								continue;
							}
							if(j > val1) {
								printf("%c", c);
								continue;
							}
							//printf("%c", c);
							j++;
						}
						printf("\n");
						break;
				}
			}
		
		}
	}	  
	return 0;
}		 
