/* code for printing alphabet */
#include<stdio.h>
void main ()
{
	int ascii_code = 0;
	printf (" enter ascii_code = ");
	scanf("%d" , &ascii_code );
	for ( ; ascii_code !=0 ;  )
	{
	//	asciicode ++ ;
		printf( " you have entered ascii code is = %d and it's respective character is =%c\n " , ascii_code , ascii_code  );
	ascii_code -- ;	
	}
}
