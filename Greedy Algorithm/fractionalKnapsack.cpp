#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool compare(Item a, Item b)
{
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    //irst sort the arr in descening order of value/weight ratio
    sort(arr, arr+n, compare);

    int currWeight = 0;
    double finalValue = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(currWeight + arr[i].weight <= W) // if value is less than the Weight we can occupy
        {
            currWeight += arr[i].weight; // put values weight to currWeight
            finalValue += arr[i].value; // update value 
        } // once the weight becomes greater than weight occupy
        else
        {
            int remain = W - currWeight; // get the remaining weight
            finalValue += (arr[i].value / (double) arr[i].weight) * (double) remain; // then update value to = value/weight * remain
            break;
        }
    }

    return finalValue;
}

int main()
{
    int n = 3, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    double ans = fractionalKnapsack(weight, arr, n);
    cout << "Maximum Value is: " << setprecision(2) << fixed << ans;

    return 0;
}