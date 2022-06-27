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
    sort(arr, arr+n, compare);

    int currWeight = 0;
    double finalValue = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(currWeight + arr[i].weight <= W)
        {
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - currWeight;
            finalValue += (arr[i].value / (double) arr[i].weight) * (double) remain;
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