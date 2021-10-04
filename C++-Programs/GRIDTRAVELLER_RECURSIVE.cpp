##The problem is to count all the possible paths from a point (a,b) of a mXn matrix with the constraints that from each cell you can either move only to right or down##


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define mod 1000000007

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007







using namespace std;


int grid(int n,int m)
{
  if(n==1&&m==1)
    return 1;
  if(n==0||m==0)
    return 0;
  
  return(grid(n-1,m)+grid(n,m-1));

}




int main(int argc, char const *argv[])
{
  int a,b;
  cin >> a >> b;
  grid(a,b);
  return 0;
}