#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    int c=0;
for(int num = i;num<=j;num++){

    string numstr(to_string(num));
    string str;

    for(int i=0;i<numstr.size();i++){
        str[i] = numstr[numstr.size()-i-1];
    }
    int numx = stoi(str);

    if(abs(num - numx) % k==0){
        c++;
    }
}
return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
