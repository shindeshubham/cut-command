void help() {
	printf("cut:\n");
	printf("        cut - remove sections from each line of files.\n");

	printf("\nSYNTAX:\n");
	printf("        cut OPTION... [FILE]...\n");
	
	printf("\nDESCRIPTION:\n");
	
	printf("       	Print selected parts of character or byte or lines from each FILE to standard output.\n");
	
	printf("\n1.OPTION:\n");

	printf("       -c, --characters=LIST\n");
	printf("           select only characters from file\n");\
	
	printf("\nEXAMPLE:\n");
	printf("	1. cut -c 2 filename\n");
	printf("	2. cut -c - 2 filename\n");
	
	printf("\n2.OPTION:\n");
	printf("       --help display this help and exit\n");
	
	printf("\nEXAMPLE:\n");
	printf("	1. cut --help\n");
	return;
}
