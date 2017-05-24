#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include<dos.h>
#include<time.h>

struct node
{
	char data [ 20 ] ;
	char m [ 5 ] [ 20 ] ;
	int mcount ;
	struct node * link ;
} ;


struct node * dic [ 26 ] ;

void add ( char * ) ;
int  search ( char * ) ;
void show( ) ;
void deldic( ) ;
int about();
void window();
int screen();
void SetColor(int ForgC);

     FILE *fp;
     COORD coord = {0, 0};
COORD max_res,cursor_size;

void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main( )
{
    screen();
    //main_menu();
    return 0;


    fp=fopen("dictionary.txt","a");
	char word [ 20 ] , ch ;
	int i ;

	system ( "cls" ) ;

	while ( 1 )
	{
		system ( "cls" ) ;
		printf ( "\n\t\tDictionary\n" ) ;
		printf ( "\n\t\t1.Add Word.\n" ) ;
		printf ( "\t\t2.Search Word.\n" ) ;
		printf ( "\t\t3.Show Dictionary.\n" ) ;
		printf ( "\t\t0.Exit." ) ;
		printf ( "\n\n\t\tYour Choice ") ;
		scanf ( "%s", &ch ) ;

		switch ( ch )
		{
			case 1 :

				printf ( "\nEnter any word : " ) ;
				fflush ( stdin ) ;
				gets ( word ) ;
				add ( word ) ;
				break ;

			case 2 :

				printf ( "\nEnter the word to search : " ) ;
				fflush ( stdin ) ;
				gets ( word ) ;
				i = search ( word ) ;
				if ( ! i )
					printf ( "Word does not exists." ) ;
        getch( ) ;
				break ;

			case 3 :

				show( ) ;
        getch( ) ;
				break ;

			case 0 :

				deldic( ) ;
				exit ( 0 ) ;

			default :

				printf ( "\nWrong Choice" ) ;
		}
	}
  return 0 ;
}

void SetColor(int ForgC)
{
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

int screen()
{
    system("cls");
    system("color 1D");

    int i,j;
    char name[50]="Welcome to Railway station simulation project";
    printf("\n\n\n\n\n\n\n\t\t");
    for(i=0;i<50;i++)
    {
        printf("%c",name[i]);
        Sleep(50);
    }
    printf("\n\n\n\n\t\t\t");
    char name1[60]="\t\tLOADING......";
    printf("\n\t\t");
    for(j=0;j<60;j++)
    {
        printf("%c",name1[j]);
        Sleep(50);
    }
    Sleep(2000);
    return 0;
}


void add ( char * str )
{
	int i, j = toupper ( str [ 0 ] ) - 65 ;
	struct node * r, * temp = dic [ j ], * q ;
	char mean [ 5 ] [ 20 ], ch = 'y' ;

	i = search ( str ) ;
	if ( i )
	{
		printf ( "\nWord already exists." ) ;
		return ;
	}
	q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	strcpy ( q -> data, str ) ;
	q -> link = NULL ;

	for ( i = 0 ; tolower ( ch ) == 'y' && i < 5 ; i++ )
	{
		fflush ( stdin ) ;
		printf ( "\n\nEnter the meaning(s) : " ) ;
		gets ( mean [ i ] ) ;
		strcpy ( q -> m [ i ] , mean [ i ] ) ;
		if ( i != 4 )
			printf ( "\nAdd more meanings (y/n) " ) ;
		else
			printf ( "You cannot enter more than 5 meanings." ) ;
		fflush ( stdin ) ;
		fclose(fp);
		ch = getche( ) ;
	}

	q -> mcount = i ;
	if ( dic [ j ] == NULL || strcmp ( dic [ j ] -> data, str ) > 0 )
	{
		r = dic [ j ] ;
		dic [ j ] = q ;
		q -> link = r ;
		return ;
	}

	else
	{
		while ( temp != NULL )
		{
			if ( ( strcmp ( temp -> data, str ) < 0 ) && ( ( strcmp ( temp -> link -> data, str ) > 0 ) ||
											temp -> link == NULL ) )
			{
				q -> link = temp -> link ;
				temp -> link = q ;
				return ;
			}
			temp = temp -> link ;
		}
	}
}

int search ( char *str )
{
	struct node *n ;
	char temp1 [ 20 ] ;
	char temp2 [ 20 ] ;
	int i ;

	n = dic [ toupper ( str [ 0 ] ) - 65 ] ;
	strcpy ( temp2, str ) ;
	strupr ( temp2 ) ;

	while ( n != NULL )
	{
		strcpy ( temp1, n -> data ) ;

		if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 )
		{
			printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
			for ( i = 1 ; i < n -> mcount ; i++ )
				printf ( "\n\t\t%s", n -> m [ i ] ) ;
			return 1 ;
		}
		n = n -> link ;
	}
	return 0 ;
}

void show( )
{
	struct node *n ;
	int i, j ;

    fp=fopen("dictionary.txt","a");
	printf ( "Word\t\tMeaning\n" ) ;

	fprintf(fp,"Word\t\tMeaning\n");

	for ( i = 0 ; i <= 30 ; i++ ){

		printf ( "-" ) ;
        fprintf(fp,"-");
	}


	for ( i = 0 ; i <= 25 ; i++ )
	{
		n = dic [ i ] ;
		while ( n != NULL )
		{
			printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;

			fprintf(fp,"\n%s\t\t%s", n -> data, n -> m [ 0 ]);

			for ( j = 1 ; j < n -> mcount ; j++ )
				printf ( "\n\t\t%s", n -> m [ j ] ) ;


				fprintf(fp,"\n\t\t%s", n -> m [ j ] );

			n = n -> link ;

		}
	}
	fclose(fp);

}

void deldic( )
{
	struct node *n, *t ;
	int i ;

	for ( i = 0 ; i <= 25 ; i++ )
	{
		n = dic [ i ] ;
		while ( n != NULL )
		{
			t = n -> link ;
			free ( n ) ;
			n = t ;
		}
	}
}

void window(){

    gotoxy(28,2);
    SetColor(35);
    printf("  Train Station Simulation");
    gotoxy(16,3);
    SetColor(25);
    printf("Daffodil International University,Bangladesh");
    gotoxy(22,4);
    SetColor(45);
    printf("\t\t BID");
    gotoxy(22,5);
    gotoxy(1,1);

    gotoxy(18,24);
    SetColor(17);

}

/*int about()
{
    system("cls");
    system("color 0E");

        int a=8;
        printf("\n\n\n");
		gotoxy(16,3);
		printf("Programmers....");
		gotoxy(16,5);
		printf("1. Al-Amin            (132-15-2625)");
		gotoxy(16,7);

		printf("2. Md.Waliullah       (132-15-2788)");
		gotoxy(16,9);

		printf("3. Istiaq Hasan       (132-15-2698)");
		gotoxy(16,11);

		printf("4. Ariful Islam       (132-15-2685)");
		gotoxy(16,13);

		printf("5. Parvez             (132-15-2755)");
		gotoxy(16,15);

		printf("6. Tasfia Jaki        (132-15-2784)");
		gotoxy(16,17);

		printf("press 8 to go back to the main menu : ");
		scanf("%d",&a);
		if(a==8)
            {
                //main_menu();
            }
            else
            {
                printf("You have press wrong key");
            }
}*/
