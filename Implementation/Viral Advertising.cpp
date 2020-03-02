#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {

int liked = 0;
int shared = 5;
int sum=0;

liked = floor(shared/2) * 1;
shared = (liked) *3;
sum = liked;

for(int i=1;i<n;i++){
    liked = floor(shared/2);
    shared = (liked) *3;
    sum += liked;
}
return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
