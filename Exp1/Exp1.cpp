#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long counter = 0;
int maxDepth = 0;

void complexRec(int n, int depth) 
{
    maxDepth = max(depth, maxDepth);

    if (n <= 2) {
        return;
    }
    int p = n;

    // O(n log n)
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) 
        {
            temp[i] = i ^ p;
            counter++;
        }
        p >>= 1;
    }

    vector<int> small(n);

    // O(n)
    for (int i = 0; i < n; i++)  
    {
        small[i] = i * i;
        counter++;
    }

    if (n % 3 == 0) 
    {
        counter += n;
        reverse(small.begin(), small.end());
    } 
    else 
    {
        counter += n;
        reverse(small.begin(), small.end());
    }


   complexRec(n / 2, depth + 1);
   complexRec(n / 2, depth + 1);
   complexRec(n / 2, depth + 1);
}


int main()
{
    int n = 16;

    auto start = high_resolution_clock::now(); 
    complexRec(n, 1);
    auto end = high_resolution_clock::now();
    auto dur = duration_cast<milliseconds> (end - start);

    cout<<"n = "<<n<<endl;
    cout<<"Maximum depth or recursion tree: "<<maxDepth<<endl;
    cout<<"Number of operations: "<<counter<<endl;
    cout<<"Total time: "<<dur.count()<<" ms"<< endl;

    cout<<"Recurrence Relation: T(n) = 3 T(n / 2) + O(n log n)"<<endl;
    cout<<"Time Complexity: O(n ^ log_2 3)"<<endl;

    return 0;

}

/*
    Recurrence Relation
    T(n) = 3 T(n / 2) + O(n log n)
*/ 


/*
    Master Theorem 
    f(n) = O(n log n)
    a = 3, b = 2

    Case 1 used
    T(n) = Theta(n ^ (log_2 3))
*/

