#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define VERSION "1.0"
#define BUFSIZE 128

#ifdef WIN32

#include <io.h>

#define R_OK 0
#define access _access

#else

#include <unistd.h>

#endif

int find_first(char* buf, int n);
void print_match(FILE* f, const char* arg);

int 
find_first(char* buf, int n)
{
	for (int i = 0; i < n; i++) {
		if ( buf[i] == '\n' )
			return -1;

		if ( buf[i] == ' ' || buf[i] == '\t' )
			return i;
	}

	return -1;
}

void
print_match(FILE* f, const char* arg)
{
	char buf[BUFSIZE], fmatch[BUFSIZE];
	int eindex = 0;

	while ( fgets(buf, BUFSIZE, f) ) {
		memset( fmatch, 0, BUFSIZE);
		eindex = find_first( buf, BUFSIZE );
		strncpy( fmatch, buf, eindex );

		if ( !strcmp( fmatch, arg ) ) {
			break;
		}

		eindex = -1;
	}

	if ( eindex != -1 ) {
		while (buf[eindex] == ' ' || buf[eindex] == '\t') { eindex++; }

		memset( fmatch, 0, BUFSIZE );
		strncpy( fmatch, buf + eindex, BUFSIZE-eindex );

		printf("%s", fmatch);
	}	
}

int
main(int argc, char* argv[])
{
	FILE* f;	

	if ( argc == 2 && !strcmp("-v", argv[1]) ) {
		printf("tabler-%s\n", VERSION);
		exit(-1);
	}

	if ( argc == 2 && !strcmp("-h", argv[1]) || argc == 1 ) {
		printf("usage: tabler filename [patterns...]\n");
		exit(-1);
	}

	if ( access(argv[1], R_OK) ) {
		printf("file doesn't exist or you do not have the permissions to read...\n");
		exit(-1);
	}

	f = fopen(argv[1], "r");
	
	for (int i = 2; i < argc; i++) {
		print_match(f, argv[i]);
		fseek(f, 0, SEEK_SET);
	}

	fclose(f);

	return 0;
}
