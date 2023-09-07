#include <iostream>
#include <cstdio>
#include <cstdlib>
const int size=6;
int main()
{
  int a[size][size]; 
  int d[size];
  int v[size]; 
  int temp, minindex, min;
  int begin_index = 0;
  
  
  for (int i = 0; i<size; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j<size; j++) {
      std::cout<<"Аралыктарды киргизүү "<<i + 1<<" : "<<j + 1<<" = ";
      scanf("%d", &temp);
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }
 
  for (int i = 0; i<size; i++)
  {
    for (int j = 0; j<size; j++)
      printf("%5d ", a[i][j]);
      printf("\n");
  }
  
  for (int i = 0; i<size; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[begin_index] = 0;
  
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<size; i++)
    { 
      if ((v[i] == 1) && (d[i]<min))
      { 
        min = d[i];
        minindex = i;
      }
    }
    
    if (minindex != 10000)
    {
      for (int i = 0; i<size; i++)
      {
        if (a[minindex][i] > 0)
        {
          temp = min + a[minindex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);
  
  for (int i = 0; i<size; i++)
    printf("%5d ", d[i]);

  
  int ver[size]; 
  int end = 4; 
  ver[0] = end + 1; 
  int k = 1; 
  int weight = d[end]; 

  while (end != begin_index) 
  {
    for (int i = 0; i<size; i++) 
      if (a[i][end] != 0)   
      {
        int temp = weight - a[i][end]; 
        if (temp == d[i]) 
        {                 
          weight = temp; 
          end = i;       
          ver[k] = i + 1; 
          k++;
        }
      }
  }
  
  for (int i = k - 1; i >= 0; i--)
    printf("%3d ", ver[i]);
  
  return 0;
}

