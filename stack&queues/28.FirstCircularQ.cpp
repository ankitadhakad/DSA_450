#include<iostream>
using namespace std;
// Suppose there is a circle. There are N petrol pumps on that circle. 
// You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle 
// without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

// Example 1:

// Input:
// N = 4
// Petrol = 4 6 7 4
// Distance = 6 5 3 5
// Output: 1
// Explanation: There are 4 petrol pumps with
// amount of petrol and distance to next
// petrol pump value pairs as {4, 6}, {6, 5},
// {7, 3} and {4, 5}. The first point from
// where truck can make a circular tour is
// 2nd petrol pump. Output in this case is 1
// (index of 2nd petrol pump).


//approach 1 O(N^2)
 int tourI(petrolPump p[],int n)
    {
       
       for(int i = 0; i < n; i++){
            int totalFuel = 0;
            int stopCount = 0, j = i;
            while(stopCount < n){
                totalFuel += p[j % n].petrol - p[j % n].distance;
                if(totalFuel < 0) break; // whenever we reach -ve
                stopCount++;
                j++;
            }
            if(stopCount == n && totalFuel >= 0) return i; // cover all the stops & our fuel left is 0 or more than that
        }
        return -1;
    }


//pproach 2 O(N)
int tourII(petrolPump p[],int n)
    {
       int totalDis = 0;
       int totalPet = 0;
       int start = 0;
       int sum = 0;
       for(int i=0;i<n;i++)
       {
           totalDis+=p[i].distance;
           totalPet+=p[i].petrol;
           sum+=p[i].petrol-p[i].distance;
           if(sum<0)
           {
               start = i+1;
               sum = 0;
           }
       }
       return totalPet-totalDis<0?-1:start;
    }
int main()
{

    return 0;

}