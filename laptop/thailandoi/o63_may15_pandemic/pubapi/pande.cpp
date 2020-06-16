#include "pandelib.h"
#include <vector>
#include <cstdio>

int n,k,l;

assignment_t a[100000];
bool results[100000];

int main()
{
  pandemic_init(n,k,l);

  for(int i=0; i<k; i++)
    for(int j=0; j<n; j++)
      a[i].push_back(j);
  
  pandemic_assign(a,results);

  for(int i=0; i<k; i++)
    a[i].clear();

  pandemic_assign(a,results);

  pandemic_answer(0);
}

