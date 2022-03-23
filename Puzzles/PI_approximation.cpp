#ifdef CPP

static double approx(vector<Point> &pts) {
    //srand( time(NULL) );
    int i, count;
    double x,y,z,pi;

    count = 0;
    for(i = 0; i < pts.size(); ++i){
        z = pts[i].x * pts[i].x + pts[i].y * pts[i].y;
        if( z <= 1 ) count++;
    }
    
    pi = (double) count / pts.size() * 4;

    return(pi);
}

#else //C code

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const uint64_t RR = RAND_MAX*RAND_MAX;

double MonteCarlo(int n) {
  int k=0;
  for (int i=0; i<n; ++i) {
    uint64_t x=rand(), y=rand();
    if (x*x + y*y <= RR) k++;
  }
  return 4.0*k/n;
}

double Abso(double x) {return (x<0)? -x : x;}

int main() {
  printf("RAND_MAX = %u",RAND_MAX);

  printf("\n\nMonteCarlo:\n");
  for (int n=10; n<=100000000; n*=10) printf("  n=%9i: pi=%.14f\n",n,MonteCarlo(n));
  printf("précis:        pi=3.14159265358979");

  printf("\n\nMonteCarlo:  srand(478)\n");
  for (int n=10; n<=100000000; n*=10) {
    srand(478);
    printf("  n=%9i: pi=%.14f\n",n,MonteCarlo(n));
  }
  printf("précis:        pi=3.14159265358979");

  getchar();
}
#endif
