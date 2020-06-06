#include<stdio.h>
#include<string.h>
#define N 80
char a[N], b[N], res[N + 1];
/*int main ()
{
  char op;
  scanf ("%s %s %c", a, b, &op);
  switch (op) {
    case '+':
    add (a, b, res);
    break;
    case '-':
    sub (a, b, res);
    }
// print result
  char buf [20];
  int l1 = strlen (a), l2 = strlen (b), l3 = strlen (res );
  int m = l1 > l2 ? l1 : l2;
  m = m > l3 ? m : l3;
  sprintf (buf , "%% %ds\n%% %ds\n%% %ds\n", m, m, m);
  printf (buf , a, b, res );
}*/

void add ( const char a[], const char b[], char res []) {
/* Adds two decimal numbers stored as strings and returns their sum .
Input
a: an array of characters storing decimal digits ; a[0] != '0'.
b: an array of characters storing decimal digits ; b[0] != '0'.
Output
res : an array of characters storing a decimal number that is
the sum of the numbers represented in a and b.
*/
int length = strlen(a);
int len_b = strlen(b);
if (length < len_b){
  length = len_b;
}
int a_val,b_val,c,ans,carry = 0;
int q=length-1;
res[length] = '\0';
int i = (strlen(a)-1);
int j = len_b - 1;
while (a[i] != ' ' && b[j] != ' ' && i>= 0 && j >= 0) {
    c,ans = 0;
    a_val = a[i] - '0';
    b_val = b[j] - '0';
    if (carry == 1){
      c = a_val + b_val + carry;
      carry--;
    }
    else{
      c = a_val + b_val;
    }
  if (c >= 10) {
      ans = c - 10;
      carry++;
    }
    else{ans = c;}
    res[q] = ans + '0';
    q--;
  i--;j--;
}
while (a[i] != ' ' && i>= 0) {
  ans = 0;
  if (carry == 1){
    ans = (a[i] - '0') + 1;
    carry--;
  }
  else{ans = a[i] - '0';}
  res[q] = ans + '0';
  i--;
  q--;
}
while (b[j] != ' ' && j>= 0) {
ans = 0;
if (carry == 1){
  ans = (b[j] - '0') + 1;
  carry--;
}
else{ans = b[j] - '0';}
res[q] = ans + '0';
j--;q--;
}
if (carry == 1){
  res[q] = 1;
  carry--;
}
}
void sub ( const char a[], const char b[], char res []) {
/* Subtracts two decimal numbers stored as strings and returns their
difference .
Input
a: an array of characters storing decimal digits ; a[0] != '0'.
b: an array of characters storing decimal digits ; b[0] != '0'.
Output
res : an array of characters storing a decimal number that is
the difference of the numbers represented in a and b.
*/

int length = strlen(a);
int len_b = strlen(b);
int a_val,b_val,c,dec = 0;
int i = strlen(a) - 1;
int j = len_b - 1;
if (length < len_b || (len_b == length && (b[0] > a[0]))){
  length = len_b;
  int q=length;
  while (b[j] != ' ' && j >= 0) {
    c = 0;
    a_val = a[i] - '0';
    if (a_val < 0){a_val = 0;}
    b_val = b[j] - '0';
    if (dec == 1){
      b_val = b_val -1;
      dec = 0;
    }
    if (a_val > b_val){
      c = (10 + b_val) - a_val;
      dec = 1;
    }
    else{
      c = b_val - a_val;
      dec = 0;
    }
    res[q] = c + '0';
    q--;i--;j--;
  }
  res[0] = '-';
  if (res[1] == '0'){res[1] = res[0]; res[0] = ' ';}
  res[-1] = '\0';
  }
else{
  int q=length-1;
  res[length] = '\0';
  while (a[i] != ' ' && i >= 0) {
    c = 0;
    a_val = a[i] - '0';
    b_val = b[j] - '0';
    if (b_val < 0){b_val = 0;};
    if (dec == 1){
      a_val = a_val -1;
      dec = 0;
    }
    if (a_val < b_val){
      c = (10 + a_val) - b_val;
      dec = 1;
    }
    else{
      c = a_val - b_val;
      dec = 0;
    }
    res[q] = c + '0';
    if (res[0] == '0'){res[0] = ' ';}
    q--;i--;j--;
  }
}
}
