#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>
#include <time.h>
int isvalid(long num);
int sumofdoubleevenplace(long num);
int getdigit(int num);
int sumofoddplace(long num);
int prefixmatched(long num,int d);
int getsize(long d);
int getprefix(long num,int k);

int rowA,columnA,rowB,columnB,row,column,navigatee;

int sudoku[9][9];//The array which stores entries for the sudoku
void solvesudoku(int,int);

int matrix_add(int m,int n);
int sdmd(int first,int second);
int armstrong_number(int number);
int OE(int n);
int comstr(a,b);
int co(int a);
int Fibonacci_series(int a);
int Fibonacci_calculate(int a);
int mat_trans(int a);
int mat_multi(a);
int mat_Sub(a);
int sin_m(a);
int check_prime(int);
int c,pn;
int prime_num(a);
int po(a);
int log_e(a);
int log_10(a);
void Eratosthenes(int n);


int log_10(a)
{
  double n, result;

  printf("Enter a number to calculate it's log(base is 10)\n");
  scanf("%lf", &n);

  result = log10(n);

  printf("Common log of %.2lf = %.2lf\n", n, result);

  return 0;
}


int log_e(a)
{
  double n, result;

  printf("Enter a number to calculate it's natural log (base is e)\n");
  scanf("%lf", &n);

  result = log(n);

  printf("Natural log of %.2lf = %lf\n", n, result);

  return 0;
}


int po(a)
{
  double c, d, result;

  printf("Enter c and d to calculate c^d\n");
  scanf("%lf%lf", &c, &d);

  result = pow(c, d);

  printf("%.2lf raised to %.2lf = %.2lf\n", c, d, result);

  return 0;
}


int matrix_add(int m,int n)
{
   int c, d, first[10][10], second[10][10], sum[10][10];

   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d", &m, &n);
   printf("Enter the elements of first matrix\n");

   for ( c = 0 ; c < m ; c++ )
      for ( d = 0 ; d < n ; d++ )
         scanf("%d", &first[c][d]);

   printf("Enter the elements of second matrix\n");

   for ( c = 0 ; c < m ; c++ )
      for ( d = 0 ; d < n ; d++ )
            scanf("%d", &second[c][d]);

   for ( c = 0 ; c < m ; c++ )
      for ( d = 0 ; d < n ; d++ )
         sum[c][d] = first[c][d] + second[c][d];

   printf("Sum of entered matrices:-\n");

   for ( c = 0 ; c < m ; c++ )
   {
      for ( d = 0 ; d < n ; d++ )
         printf("%d\t", sum[c][d]);

     printf("\n");
   }

   return (sum[c][d]);
}



int sdmd(int first,int second)
{
   int add, subtract, multiply;
   float divide;

   printf("Enter two integers\n");
   scanf("%d%d", &first, &second);

   add        = first + second;
   subtract = first - second;
   multiply = first * second;
   divide     = first / (float)second;

   printf("Sum = %d\n",add);
   printf("Difference = %d\n",subtract);
   printf("Multiplication = %d\n",multiply);
   printf("Division = %.2f\n",divide);

   return (add,subtract,multiply,divide);
}


int armstrong_number(int number)
{
   int sum = 0, temp, remainder;

   printf("\nEnter an integer for armstriong number\n");
  scanf("%d",&number);

   temp = number;

   while( temp != 0 )
   {
      remainder = temp%10;
      sum = sum + remainder*remainder*remainder;
      temp = temp/10;
   }

   if ( number == sum )
      printf("Entered number is an armstrong number.\n");
   else
      printf("Entered number is not an armstrong number.\n");

   return 0;
}


int OE(int n)
{
   printf("\nEnter an integer for Even or Odd\n");
   scanf("%d",&n);

   if ( n%2 == 0 )
      printf("Even\n");
   else
      printf("Odd\n");

   return 0;
}


int comstr(a,b)
{
        printf("Enter the first string\n");
            scanf("%s",a);
            printf("Enter the second string\n");
            scanf("%s",b);
            if( strcmp(a,b) == 0 )
            printf("Entered strings are equal.\n");
            else
            printf("Entered strings are not equal.\n");
}


int co(int a)
{
    printf("Enter the number for value of cos\n");

  double result,c;
  scanf("%lf",&c);
  result = cos(c);

  printf("cos(%.4lf) = %.2lf\n", c, result);

  return 0;
}


int Fibonacci_series(int a)
{
   int n, first = 0, second = 1, next, c;

   printf("Enter the number of terms\n");
   scanf("%d",&n);

   printf("First %d terms of Fibonacci series are :-\n",n);

   for ( c = 0 ; c < n ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      printf("%d\n",next);
   }

   return 0;
}


int Fibonacci_calculate(int a)
{
  int c, n, fact = 1;

  printf("Enter a number to calculate it's factorial\n");
  scanf("%d", &n);

  for (c = 1; c <= n; c++)
    fact = fact * c;

  printf("Factorial of %d = %d\n", n, fact);

  return 0;
}



int mat_trans(int a)
{
   int m, n, c, d, matrix[10][10], transpose[10][10];

   printf("Enter the number of rows and columns of matrix ");
   scanf("%d%d",&m,&n);
   printf("Enter the elements of matrix \n");

   for( c = 0 ; c < m ; c++ )
   {
      for( d = 0 ; d < n ; d++ )
      {
         scanf("%d",&matrix[c][d]);
      }
   }

   for( c = 0 ; c < m ; c++ )
   {
      for( d = 0 ; d < n ; d++ )
      {
         transpose[d][c] = matrix[c][d];
      }
   }

   printf("Transpose of entered matrix :-\n");

   for( c = 0 ; c < n ; c++ )
   {
      for( d = 0 ; d < m ; d++ )
      {
         printf("%d\t",transpose[c][d]);
      }
      printf("\n");
   }

   return 0;
}



int mat_multi(a)
{
  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];

  printf("Enter the number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter the elements of first matrix\n");

  for (  c = 0 ; c < m ; c++ )
    for ( d = 0 ; d < n ; d++ )
      scanf("%d", &first[c][d]);

  printf("Enter the number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);

  if ( n != p )
    printf("Matrices with entered orders can't be multiplied with each other.\n");
  else
  {
    printf("Enter the elements of second matrix\n");

    for ( c = 0 ; c < p ; c++ )
      for ( d = 0 ; d < q ; d++ )
        scanf("%d", &second[c][d]);

    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
      {
        for ( k = 0 ; k < p ; k++ )
        {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }

    printf("Product of entered matrices:-\n");

    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
        printf("%d\t", multiply[c][d]);

      printf("\n");
    }
  }

  return 0;
}


int mat_Sub(a)
{
  int m, n, c, d, first[10][10], second[10][10], difference[10][10];

  printf("Enter the number of rows and columns of matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter the elements of first matrix\n");

  for (c = 0; c < m; c++)
    for (d = 0 ; d < n; d++)
      scanf("%d", &first[c][d]);

  printf("Enter the elements of second matrix\n");

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
        scanf("%d", &second[c][d]);

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      difference[c][d] = first[c][d] - second[c][d];

  printf("difference of entered matrices:-\n");

  for (c = 0; c < m; c++)
  {
    for (d = 0; d < n; d++)
      printf("%d\t",difference[c][d]);

    printf("\n");
  }

  return 0;
}
int sin_m(a)
{
  double result, x ;
   printf("Enter the number for value of sin\n");
  scanf("%lf",&x);

  result = sin(x);

  printf("The sin(%lf) = %.2lf\n", x, result);

  return 0;
}


int check_prime(int a)
{

   for ( c = 2 ; c <= a - 1 ; c++ )
   {
      if ( a%c == 0 )
	 return 0,c;
   }
   if ( c == a )
      return 1;
}

int prime_num(a)
{
   int n, i = 3, count, c;

   printf("Enter the number of prime numbers required\n");
   scanf("%d",&n);

   if ( n >= 1 )
   {
      printf("First %d prime numbers are :\n",n);
      printf("2\n");
   }

   for ( count = 2 ; count <= n ;  )
   {
      for ( c = 2 ; c <= i - 1 ; c++ )
      {
         if ( i%c == 0 )
            break;
      }
      if ( c == i )
      {
         printf("%d\n",i);
         count++;
      }
      i++;
   }

   return 0;
}



#define TRUE    1
#define FALSE   0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputyear(void)
{
	int year;

	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	return year;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}

		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );

			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}


int isvalid(long num){
if(((sumofoddplace(num)+sumofdoubleevenplace(num))%10==0)
   && (getsize(num)<=16 && getsize(num)>=13)
   && (prefixmatched(num,4)==1 || prefixmatched(num,5)==1 ||
       prefixmatched(num,6)==1 || prefixmatched(num,37==1)))
    return 1;
else
    return 0;
}

int sumofdoubleevenplace(long num){
int numdigits=getsize(num)-1;
int sum=0,i;
num/=10;
for(i=0;i<numdigits;i+=2){
    sum+=getdigit((int)(2*(num % 10)));
    num/=100;
}
return sum;
}

int getdigit(int num){
return ((num-num%10)/10)+num%10;
}

int sumofoddplace(long num){
int numberofdigits=getsize(num);
int sum=0,i;
for(i=0;i<numberofdigits;i+=2){
    sum+=num%10;
    num/=100;
}
return sum;
}

int prefixmatched(long num,int d){
if(getprefix(num,getsize(d))==d)
    return 1;
else
    return 0;
}

int getsize(long d){
int n=0;
while(d!=0){
    d/=10;
    n++;
}
return n;
}

int getprefix(long num,int k){
int numberofdigits=getsize(num);
int i;
if(numberofdigits-k>0){
    for(i=0;i<numberofdigits-k;i++){
        num/=10;
    }
    return num;
}
else
    return num;
}


int checkrow(int row,int num)
{//This function checks whether we can put the number(num) in the row(row) of the Sudoku or not
int column;
for(column=0;column<9;column++)
    if(sudoku[row][column]==num)
        return 0 ;//If the number is found already present at certain location we return zero
return 1;//If the number is not found anywhere we return 1
}
int checkcolumn(int column,int num)
{//This function checks whether we can put the number(num) in the column(column) of the Sudoku or not
int row;
for(row=0;row<9;row++)
    if(sudoku[row][column]==num)
        return 0;//If the number is found already present at certain location we return zero
return 1;//If the number is not found anywhere we return 1
}
int checkgrid(int row,int column,int num)
{//This function checks whether we can put the number(num) in the 3*3 grid or not
//We get the starting row and column for the 3*3 grid
row=(row/3)*3 ;
column=(column/3)*3;
int r,c;
for(r=0;r<3;r++)
    for(c=0;c<3;c++)
         if(sudoku[row+r][column+c]==num)
            return 0;//If the number is found already present at certain location we return zero
return 1;//If the number is not found anywhere we return 1
}
void navigate(int row,int column)
{//Function to move to the next cell in case we have filled one cell
if(column<8)
        solvesudoku(row,column+1);
    else
       solvesudoku(row+1,0);
}
void display()
{//The function to display the solved Sudoku
int row,column;
printf("THE SOLVED SUDOKU \n");
for(row=0;row<9;row++)
{
for(column=0;column<9;column++)
printf("%d ",sudoku[row][column]);
printf("\n");
}
getch();
}
void solvesudoku(int row,int column)
{
    if(row>8)//If the row number is greater than 8 than we have filled all cells hence we have solved the sudoku
    display();
    if(sudoku[row][column]!=0)
    navigate(row,column);//If the value filled at a cell is not zero than it is filled with some value from 0 to 9 hence we move further
    else
    {
        int ctr;//This is a counter to check numbers from 1 to 9 whether the number can be filled in the cell or not
        for(ctr=1;ctr<=9;ctr++)
        {//We check row,column and the grid
        if((checkrow(row,ctr)==1)&&(checkcolumn(column,ctr)==1)&&(checkgrid(row,column,ctr)==1))
        {
            sudoku[row][column]=ctr;
             navigate(row,column);
        }
        }
        sudoku[row][column]=0;//No valid number was found so we clean up and return to the caller.
    }

}


void Eratosthenes(int n)
{
int boolean[n-1];//boolean array holds 0 if the numbers is not prime
int list[n-1];//store the numbers till given range from 2 onwards
int ctr,outctr,inctr,primeassm;
for(ctr=0;ctr<n-1;ctr++)
{
    list[ctr]=ctr+2;//start storing numbers from 2 onwars
    boolean[ctr]=1;//assume all to be prime
}
for(outctr=0;outctr<n/2+1;outctr++)
{
    if(boolean[outctr]==1)
    {
    primeassm=list[outctr];//perform primality check for indivusal numbers
    for(inctr=outctr+1;inctr<n-1;inctr++)
    if(list[inctr]%primeassm==0)//if divisible set boolean to 0
    boolean[inctr]=0;
    }
}
printf("\nThe prime numbers till the given range are\n");
for(ctr=0;ctr<n-1;ctr++)
if(boolean[ctr]==1)//display the list of prime numbers
printf("%d\n",list[ctr]);
}




float **matrixA;//for the first matrix
float **matrixB;//for the second matrix
float **matrixRes;//for the results of additon,multiplication and subtraction matrix
//rowA,columnA,rowB,columnB store sizes of A and B row and column are counters
void add()
{//function to add two matrices
if((rowA==rowB)&&(columnA==columnB))
    {
    printf("A+B\n");//Unless the dimensions are same addition not possible
    matrixRes=(float **)malloc(rowA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixRes[row]=(float *)malloc(columnA*sizeof(float));
    for(row=0;row<rowB;row++)
    {
        for(column=0;column<columnB;column++)
        {
            matrixRes[row][column]=matrixA[row][column]+matrixB[row][column];//Add corresponding elements
            printf("%.2f ",matrixRes[row][column]);
        }
        printf("\n");
    }
    for(row=0;row<rowA;row++)
        free(matrixRes[row]);
    free(matrixRes);
    }
else
printf("Incompatible for addition\n");
}
void sub()
{
if((rowA==rowB)&&(columnA==columnB))
    {//unless dimension are smae subtraction not possible
    printf("A-B\n");
    matrixRes=(float **)malloc(rowA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixRes[row]=(float *)malloc(columnA*sizeof(float));//dynamic allocation
    for(row=0;row<rowB;row++)
    {
        for(column=0;column<columnB;column++)
        {
            matrixRes[row][column]=matrixA[row][column]-matrixB[row][column];//subtracting the corresponding elements
            printf("%.2f ",matrixRes[row][column]);
        }
        printf("\n");
    }
    for(row=0;row<rowA;row++)
        free(matrixRes[row]);
    free(matrixRes);
    }
else
printf("Incompatible for subtraction\n");
}
void mult()
{
if((columnA==rowB))
    {//for two matrices to allow for multiplication number of column of first matrix should be equal to number of rows in other matrix
    printf("A*B\n");
    matrixRes=(float **)malloc(rowA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixRes[row]=(float *)malloc(columnB*sizeof(float));
    for(row=0;row<rowB;row++)
    {
        for(column=0;column<columnB;column++)
        {//code to multiply two matrices
            matrixRes[row][column]=0;
            for(navigatee=0;navigatee<columnA;navigatee++)
            matrixRes[row][column]+=matrixA[row][navigatee]*matrixB[navigatee][column];
            printf("%.2f ",matrixRes[row][column]);
        }
        printf("\n");
    }
    for(row=0;row<rowA;row++)
        free(matrixRes[row]);
    free(matrixRes);
    }
else
printf("Incompatible for multiplication\n");
}
float determinant(float **matrix,int size)
{
    //A recursive function to get the determinant
    float **temp;//the temporary matrix to store subsequent smaller matrix
    float det=0;//initalise value of deteminant zero

    if(size==1)
    det=matrix[0][0];//in case the matrix passed has size 1
else
    if(size==2)
    det=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];//in case the matrix passed has size 2
else
    {

        int cctr,ictr,ctr;
    for(column=0;column<size;column++)
    {//now we create another matrix properly exculding the first row and the element's corresponding colummn and then find its resulting determinant
        temp=(float **)malloc((size-1)*sizeof(float));
        for(ctr=0;ctr<size-1;ctr++)
        temp[ctr]=(float *)malloc((size-1)*sizeof(float));
        for(ctr=1;ctr<size;ctr++)
        {
            cctr=0;
            for(ictr=0;ictr<size;ictr++)
            {
                if(ictr==column)
                    continue;
                temp[ctr-1][cctr]=matrix[ctr][ictr];
                cctr++;
            }
        }
            det=det+pow(-1,column)*matrix[0][column]*determinant(temp,size-1);//pass the new matrix
        for(ctr=0;ctr<size-1;ctr++)
        free(temp[ctr]);
        free(temp);
    }
}
    return det;//return claculated determinant
}
void matrixInverse(float **matrix,int size,float res)
{
float **tem;//matrix to store smaller matrix whose determinant we find out
int ctr,ictr,rowT,columnT;
float **matrixCft;
matrixCft=(float **)malloc(size*sizeof(float));//matrix to store cofactor matrix
tem=(float **)malloc((size-1)*sizeof(float));
for(ctr=0;ctr<size-1;ctr++)
tem[ctr]=(float *)malloc((size-1)*sizeof(float));
for(ctr=0;ctr<size;ctr++)
matrixCft[ctr]=(float *)malloc(size*sizeof(float));
for(row=0;row<size;row++)
{
for(column=0;column<size;column++)
{//we in these loops calculate the smaller matrix which is we pass to the determinant function which allows us to calculate the cofactors
    rowT=0;
    columnT=0;
    for(ctr=0;ctr<size;ctr++)
        for(ictr=0;ictr<size;ictr++)
            if(ctr!=row&&ictr!=column)
                {
     tem[rowT][columnT++]=matrix[ctr][ictr];
                    if(columnT==size-1)
                    {
                        rowT++;
                        columnT=0;
                    }
                }
    matrixCft[row][column]=pow(-1,(row+column))*determinant(tem,size-1);//multiplying the minor obtained with appropriate power of -1 to get the cofactor
}
}
for(column=0;column<size;column++)
for(row=0;row<size;row++)
matrixCft[column][row]=matrixCft[column][row]/res;//In this step i divide the cofactor matrix with the determinant of the matrix
float **Result;
Result=(float **)malloc(size*sizeof(float));
for(ctr=0;ctr<size;ctr++)
Result[ctr]=(float *)malloc(size*sizeof(float));
for(column=0;column<size;column++)
for(row=0;row<size;row++)
Result[column][row]=matrixCft[row][column];//calulating the transpose of the cofactor matrix
for(row=0;row<size;row++)
    {
        for(column=0;column<size;column++)
        printf("%.2f ",Result[row][column]);
        printf("\n");//display the inverse
    }
for(ctr=0;ctr<size-1;ctr++)
    free(tem[ctr]);
free(tem);
for(row=0;row<size;row++)
    {
        free(Result[row]);
        free(matrixCft[row]);
    }
free(Result);
free(matrixCft);
}


int main()
{

	int  num1,num2,arm,O,f,i=0,s,x,mt,mm,ms;
	char a[100], b[100] ,n[100],ch;


	printf("1) If you want to Fibonacci_calculate!Please press Fib_cal or fib_cal or FIB_CAL");
    printf("2) If you want to Fibonacci_series!Please press FIB_SER or Fib_ser or fib_ser\n");
	printf("3) If you want to value of cos!Please press COS or cos or Cos\n");
    printf("4) If you want to compare two string!Please press COM_STR or com_str or Com_str\n");
	printf("5) If you want to value of sin!Please press sin or Sin or SIN\n");
	printf("6) If you want to play the sudoku!Please press sudoku or Sudoku or SUDOKU\n");
    printf("7) If you want to Normal math! Please press Nasmd or NASMD or nasmd\n");
	printf("8) If you want to armstrong_number! Please press Arm_num or arm_num or ARM_NUM\n");
	printf("9) If you want to Ever or odd number !Please press ODD_EVEN or odd_even or Odd_    even\n\n");
	printf("10) If you want to check the prime number !Please press PRIME or prime or Prime\n");
	printf("11) If you want to check the prime number !Please press PRIME_NUM or prime_num      or Prime_num\n");
	printf("12) If you want to list of prime number !Please press List-prime or LIST-PRIME or list-prime\n");
	printf("13) If you want to natural log (base is e) !Please press LOG_E or log_e or Log_e");
	printf("14) If you want to value of log (base is 10) !Please press LOG_10 or log_10 or      Log_10\n");
	printf("15) If you want to value of pow !Please press pow or Pow or POW\n");
	printf("16) If you want to Transpose of matrix!Please press MAT_TRANS or Mat_trans or       mat_trans\n");
	printf("17) If you want to Multiply of matrix!Please press MAT_MULTI or Mat_multi or        mat_multi\n");
    printf("18) If you want to Substract of matrix!Please press MAT_SUB or Mat_sub or           mat_sub\n");
    printf("19) If you want to Matrix add!please press MAT_ADD or mat_add or Mat_add\n");
    printf("20) If you want to Matrix all!please press MAT_ASMID or mat_asmid or Mat_asmid\n");
    printf("21) If you want to check your card AND if card digit 16 !Please press               check-card-16 or Check-card-16 or CHECK-CARD-16\n");
    printf("22) If you want to check your card AND if card digit 13 !Please press               check-card-13 or Check-card-13 or CHECK-CARD-13\n");
    printf("23) If you want to check your card AND if card digit 8 !Please press                check-card-8 or Check-card-8 or CHECK-CARD-8\n");
    printf("14) If you want to measure the temperature Fahrenheit from degree!Please press      Find-vowels or FIND-VOWELS or find-vowels\n");
    printf("25) If you want to Find Number of Vowels, Consonants, Digits and White Space        Character!Please press F-TO-D or F-to-d or f-to-d\n");
    printf("26) If you want to see the calendar for any year!Please press CALENDAR or           Calendar or calendar\n\n\n");

     {
		time_t mytime;
		mytime = time(NULL);
		printf(ctime(&mytime));
		printf("\n\n\t\t\tPerpared by Al-Amin\n\n");

	}

  {
    time_t sec;
    sec = time (NULL);

    printf ("Number of hours since January 1, 1970 is %ld \n\n", sec/3600);
  }

     while (scanf("%s",&n))
     if(strcmp(n,"MAT_ADD") == 0||strcmp(n,"mat_add")==0||strcmp(n,"Mat_add")==0)
        {
          matrix_add(num1,num2);
        }
    else if(strcmp(n,"NASMD") == 0||strcmp(n,"nasmd")==0||strcmp(n,"Nasmd")==0)
        {
	  sdmd(num1,num2);
	    }
    else if(strcmp(n,"Arm_num") == 0||strcmp(n,"arm_num")==0||strcmp(n,"ARM_NUM")==0)

        {
          armstrong_number(arm);
        }
    else if(strcmp(n,"ODD_EVEN") == 0||strcmp(n,"odd_even")==0||strcmp(n,"Odd_even")==0)
        {
          OE(O);
        }
    else if(strcmp(n,"COM_STR") == 0||strcmp(n,"com_str")==0||strcmp(n,"Com_str")==0)
        {
          comstr(a,b);
        }
    else if(strcmp(n,"COS") == 0||strcmp(n,"Cos")==0||strcmp(n,"cos")==0)
        {
            co(x);
        }
    else if(strcmp(n,"FIB_SER") == 0||strcmp(n,"Fib_ser")==0||strcmp(n,"fib_ser")==0)
        {
          Fibonacci_series(f);
        }
    else if(strcmp(n,"FIB_CAL") == 0||strcmp(n,"Fib_cal")==0||strcmp(n,"fib_cal")==0)
       {
         Fibonacci_calculate(s);
       }
    else if(strcmp(n,"MAT_TRANS") == 0||strcmp(n,"mat_trans")==0||strcmp(n,"Mat_trans")==0)
       {
         mat_trans(mt);
       }
    else if(strcmp(n,"MAT_MULTI") == 0||strcmp(n,"mat_multi")==0||strcmp(n,"Mat_multi")==0)
       {
         mat_multi(mm);
       }
    else if(strcmp(n,"MAT_SUB") == 0||strcmp(n,"mat_sub")==0||strcmp(n,"Mat_sub")==0)
       {
          mat_Sub(ms);
       }
    else if(strcmp(n,"SIN") == 0||strcmp(n,"sin")==0||strcmp(n,"sin")==0)
       {
          sin_m(sin);
       }
    else if(strcmp(n,"PRIME") == 0||strcmp(n,"prime")==0||strcmp(n,"Prime")==0)
       {
         int n, result;
         printf("Enter an integer to check whether it is prime or not.\n");
         scanf("%d",&n);
         result = check_prime(n);
         if ( result == 1 )
         printf("%d is prime.\n", n);
         else
         printf("%d is not prime,because its divided by = %d\n",n,c);
       }
    else if(strcmp(n,"PRIME_NUM") == 0||strcmp(n,"prime_num")==0||strcmp(n,"Prime_num")==0)
       {
         prime_num(pn);
       }
    else if(strcmp(n,"POW") == 0||strcmp(n,"pow")==0||strcmp(n,"Pow")==0)
       {
         po(pn);
       }
    else if(strcmp(n,"LOG_E") == 0||strcmp(n,"Log_e")==0||strcmp(n,"log_e")==0)
       {
          log_e(a);
       }
    else if(strcmp(n,"LOG_10") == 0||strcmp(n,"Log_10")==0||strcmp(n,"log_10")==0)
       {
         log_10(a);
       }
    else if(strcmp(n,"Calendar") == 0||strcmp(n,"calendar")==0||strcmp(n,"CALENDAR")==0)
       {
           {
	         int year, daycode, leapyear;

	         year = inputyear();
	         daycode = determinedaycode(year);
	         determineleapyear(year);
             calendar(year, daycode);
	         printf("\n");
           }
       }
    else if(strcmp(n,"F-TO-D") == 0||strcmp(n,"f-to-d")==0||strcmp(n,"F-to-d")==0)
       {
	       int Fahrenheit;
	       for (Fahrenheit = 0; Fahrenheit <= 300; Fahrenheit = Fahrenheit + 20)
		   printf("%3d %06.3f\n", Fahrenheit, (5.0/9.0)*(Fahrenheit-32));
       }
    else if(strcmp(n,"Find-vowels") == 0||strcmp(n,"FIND-VOWELS")==0||strcmp(n,"find-vowels")==0)
       {
         char line[150];
         int i,v,c,ch,d,s,o;
         o=v=c=ch=d=s=0;
         printf("Enter a line of string:\n");
         scanf("%s",line);
            //gets(line);
            for(i=0;line[i]!='\0';++i)
                {
                    if(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='A' || line[i]=='E' || line[i]=='I' || line[i]=='O' || line[i]=='U')
                    ++v;
                    else if((line[i]>='a'&& line[i]<='z') || (line[i]>='A'&& line[i]<='Z'))
                    ++c;
                else if(line[i]>='0'&&c<='9')
                    ++d;
                else if (line[i]==' ')
                    ++s;
                }
                    printf("Vowels: %d",v);
                    printf("\nConsonants: %d",c);
                    printf("\nDigits: %d",d);
                    printf("\nWhite spaces: %d",s);

       }
    else if(strcmp(n,"CHECK-CARD-16") == 0||strcmp(n,"check-card-16")==0||strcmp(n,"Check-card-16")==0)
       {
            long cardnum=0;
            printf("Enter credit card number ");
            scanf("%ld",&cardnum);
            if(isvalid(cardnum)==1)
            printf("Valid card number\n");
        else
            printf("Invalid card number\n ");
       }
    else if(strcmp(n,"CHECK-CARD-13") == 0||strcmp(n,"check-card-13")==0||strcmp(n,"Check-card-13")==0)
       {
            long long master_card;
            int S1, S2, S, CDigit, number1,i, number2;
            S1=S2=S=CDigit=0;
            printf("Enter Credit Card Number: \n");
            scanf("%lld", &master_card);
            master_card=master_card/10;
            for( i=1;i<=13;i++)
                {
              number1=master_card%10;
              number1=number1*2;
              if (number1>9) number1=number1-9;
              S1=S1 + number1;
              master_card=master_card/10;
              number2=master_card%10;
              S2=S2+ number2;
                }
            S=S1+S2;
            CDigit=10-(S%10);
            if (CDigit==5) printf("Your card is validation");
            else printf("Your card is not validation");
            getch();
        }
    else if(strcmp(n,"CHECK-CARD-8") == 0||strcmp(n,"check-card-8")==0||strcmp(n,"Check-card-8")==0)
       {
        __int64 master_card;
        int S1, i,S2, S, CDigit, number1, number2, temp;
        S1=S2=S=CDigit=0;
        printf("Enter Credit Card Number: \n");
        scanf("%I64d", &master_card);
        for(i=1;i<=8;i++)
            {
              master_card=master_card/10;
              number1=master_card%10;
              number1=number1*2;
              if (number1>9) number1=number1-9;
              S1=S1 + number1;
              master_card=master_card/10;
              number2=master_card%10;
              S2=S2+ number2;
            };
            S=S1+S2;
            CDigit=10-(S%10);
            if (CDigit==5) printf("\nYour card is validation");
            else printf("\nYour card is not validation");
            getch();
        }
     else if(strcmp(n,"SUDOKU") == 0||strcmp(n,"Sudoku")==0||strcmp(n,"sudoku")==0)
        {
            int row,column;
            printf("Enter the desired sudoku and enter 0 for unknown entries\n");
            for(row=0;row<9;row++)
            for(column=0;column<9;column++)
            scanf("%d",&sudoku[row][column]);
            solvesudoku(0,0);//We start solving the sudoku.
        }
    else if(strcmp(n,"LIST-PRIME") == 0||strcmp(n,"list-prime")==0||strcmp(n,"List-prime")==0)
        {
            int num;
            printf("ENTER THE RANGE WITHIN WHICH YOU WANT TO SEE THE PRIME NUMBERS\n");
            scanf("%d",&num);
            Eratosthenes(num);
            getch();
        }
   else if(strcmp(n,"MAT_ASMID") == 0||strcmp(n,"mat_asmid")==0||strcmp(n,"Mat_asmid")==0)
        {
    printf("Enter the number of rows and column in A\n");
    scanf("%d%d",&rowA,&columnA);
    printf("Enter the number of rows and column in B\n");
    scanf("%d%d",&rowB,&columnB);//entering sizes
    matrixA=(float **)malloc(rowA*sizeof(float));
    matrixB=(float **)malloc(rowB*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixA[row]=(float *)malloc(columnA*sizeof(float));
    for(row=0;row<rowA;row++)
    matrixB[row]=(float *)malloc(columnB*sizeof(float));
    printf("Enter the matrix A\n");
    for(row=0;row<rowA;row++)//entering the matrices
    for(column=0;column<columnA;column++)
    scanf("%f",&matrixA[row][column]);
    printf("Enter the matrix B\n");
    for(row=0;row<rowB;row++)
    for(column=0;column<columnB;column++)
    scanf("%f",&matrixB[row][column]);
    add();//performing additon,multiplication and subtraction
    sub();
    mult();
    if(rowA==columnA)
    {//It is only possible to find detrminant and inverse for square matrix so checking that condition
    float resA=determinant(matrixA,rowA);
    printf("Determinant of matrix A is %.2f\n",resA);
    if(resA!=0)
    {//If determinant is zero than inverse can not be calculated
    printf("The matrix inverse is\n");
    matrixInverse(matrixA,rowA,resA);
    }
    else
    printf("The inverse can not be calculated\n");
    }
    else
    {
        printf("Determinant of matrix A can not be calculated\n");
        printf("Inverse of matrix A can notbe calculated\n");
    }
    if(rowB==columnB)
    {
    float resB=determinant(matrixB,rowB);
    printf("Determinant of matrix B is %.2f\n",resB);
    if(resB!=0)
    {//Similarly operate on matrix B
    printf("The matrix inverse is\n");
    matrixInverse(matrixB,rowB,resB);
    }
    else
    printf("The inverse can not be calculated");
    }
    else
    {
        printf("Determinant of matrix B can not be calculated\n");
        printf("Inverse of matrix B can not be calculated\n");
    }
    for(row=0;row<rowA;row++)
        free(matrixA[row]);
    for(row=0;row<rowB;row++)
        free(matrixB[row]);
    free(matrixA);
    free(matrixB);
    getch();
}
    else
         {
            return 0;
         }

}




