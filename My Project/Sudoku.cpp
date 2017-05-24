#include <stdio.h> 
#include <conio.h> 
#include <time.h> 
#include <stdlib.h> 

unsigned short s[81] = { 
8, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 3, 6, 0, 0, 0, 0, 0, 
0, 7, 0, 0, 9, 0, 2, 0, 0, 

0, 5, 0, 0, 0, 7, 0, 0, 0, 
0, 0, 0, 0, 4, 5, 7, 0, 0, 
0, 0, 0, 1, 0, 0, 0, 3, 0, 

0, 0, 1, 0, 0, 0, 0, 6, 8, 
0, 0, 8, 5, 0, 0, 0, 1, 0, 
0, 9, 0, 0, 0, 0, 4, 0, 0}; 

unsigned long i = 0; 

void print(void) 
{ 
  printf("+-------+-------+-------+\n"); 
  for(unsigned short a = 0; a < 81; a++) 
  { 
    if(a % 9 == 0) 
      printf("|"); 
    printf("%2u", s[a]); 
    if(a % 3 == 2) 
      printf(" |"); 
    if(a % 9 == 8) 
    { 
      printf("\n"); 
      if(a % 27 == 26) 
        printf("+-------+-------+-------+\n"); 
    } 
  } 
} 

unsigned short check(unsigned short q) 
{ 
  for(unsigned short a = 0; a < 9; a++) 
  { 
    if((a + (q / 9) * 9 != q && s[a + (q / 9) * 9] == s[q]) 
    || (a * 9 + q % 9 != q && s[a * 9 + q % 9] == s[q]) 
    || (a % 3 + (a / 3) * 9 + ((q % 9) / 3) * 3 + (q / 27) * 27 != q && s[a % 3 + (a / 3) * 9 + ((q % 9) / 3) * 3 + (q / 27) * 27] == s[q])) 
      return 0; 
  } 
  return 1; 
} 

unsigned short solve(unsigned short p) 
{ 
  while(p <81> 80) 
    return 1; 
  for(s[p] = 1; s[p] < 10; s[p]++) 
  { 
    i++; 
    if(check(p) && solve(p + 1)) 
      return 1; 
  } 
  s[p] = 0; 
  return 0; 
} 

void main( void) 
{ 
  clock_t t = clock(); 
  clrscr(); 
  if(solve(0)) 
    print(); 
  else 
    printf("Unsolvable!\n"); 
  printf("Run %u iterations.\n", i); 
  printf("%u ms.\n", double(clock() - t) / (double(CLOCKS_PER_SEC) / 1000.0)); 
} 
