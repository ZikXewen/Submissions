#include "pandelib.h"
#include <cstdio>
#include <cstdlib>

#define MAX_K 100010
#define MAX_N 100010

int pandemic_n, pandemic_k, pandemic_l;
int pandemic_victim;

int pandemic_contacted_date[MAX_K];
bool pandemic_used[MAX_K];
int pandemic_date;
int pandemic_hit_day[MAX_N];
int pandemic_hit_count[MAX_N];

void pandemic_init(int& n, int& k, int& l)
{
  scanf("%d %d %d",
	&pandemic_n,
	&pandemic_k,
	&pandemic_l);

  scanf("%d", &pandemic_victim);
  
  for(int i=0; i<pandemic_k; i++) {
    pandemic_contacted_date[i] = -1;
    pandemic_used[i] = false;
  }
  pandemic_date = 0;

  for(int i=0; i<pandemic_n; i++) {
    pandemic_hit_count[i] = 0;
    pandemic_hit_day[i] = 0;
  }
  
  n = pandemic_n;
  k = pandemic_k;
  l = pandemic_l;
}

void pandemic_assign(assignment_t assignments[], bool results[])
{
  pandemic_date += 1;

  if(pandemic_date > 34) {
    printf("Incorrect\nToo many calls to assign (%d)\n", pandemic_date);
    exit(0);
  }
  
  int max_hit = 0;
  
  for(int i=0; i<pandemic_k; i++) {
    int ic = assignments[i].size();
    if(ic != 0) {
      pandemic_used[i] = true;
    }
    for(int j=0; j<ic; j++) {
      int u = assignments[i][j];

      if(u == pandemic_victim) {
	if(pandemic_contacted_date[i] == -1)
	  pandemic_contacted_date[i] = pandemic_date;
      }

      if(pandemic_hit_day[u] == pandemic_date) {
	pandemic_hit_count[u]++;
      } else {
	pandemic_hit_day[u] = pandemic_date;
	pandemic_hit_count[u] = 1;
      }
      if(pandemic_hit_count[u] > max_hit)
	max_hit = pandemic_hit_count[u];
    }
  }

  if(max_hit > pandemic_l) {
    printf("Incorrect\nToo many contacts (%d)\n", max_hit);
    exit(0);
  }
  
  for(int i=0; i<pandemic_k; i++) {
    results[i] = ((pandemic_contacted_date[i] != -1) &&
		  (pandemic_date >= pandemic_contacted_date[i] + 30));
  }
}

void pandemic_answer(int ans)
{
  if(ans == pandemic_victim) {
    printf("Correct\n");
    int count = 0;
    for(int i=0; i<pandemic_k; i++)
      if(pandemic_used[i])
	count++;
    printf("%d volunteers used\n",count);
  } else {
    printf("Incorrect\n");
    printf("Answer %d, correct answer %d\n",ans,pandemic_victim);
  }
  exit(0);
}

		   
