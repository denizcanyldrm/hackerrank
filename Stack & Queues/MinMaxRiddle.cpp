#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split_string(string);
void helper(queue<int>&, queue<int>&, vector<long>&, long&, int);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    // complete this function
    int maxWindowSize = arr.size();
    long wMax = 0, i = 0;
    vector<long> maxOfMinimas;
    queue<int> q1, q2;
    
    maxOfMinimas.push_back(*max_element(arr.begin(), arr.end()));
    
    if (maxWindowSize > 2)
        for(int w = 2; w < maxWindowSize; ++w) {
            wMax = 0;
            if (w % 2 == 0)
                helper(q1, q2, arr, wMax, w);
            else 
                helper(q2, q1, arr, wMax, w);
            
            maxOfMinimas.push_back(wMax); 
        }
    
    if (maxWindowSize >= 2)
        maxOfMinimas.push_back(*min_element(arr.begin(), arr.end()));
    return maxOfMinimas;
}

void helper(queue<int>& q1, queue<int>& q2, vector<long>& arr, long& wMax, int w) {
    int i = 0, popCount = 0;
    long localMin = pow(10, 9) + 1;
    for(i = 0; i < w; ++i) {
        q1.push(i);                
        localMin = localMin < arr[i] ? localMin : arr[i];  
    }
    wMax = localMin;
    
    while(i < arr.size()) {
        q2.push(q1.front());
        q1.pop();
        ++popCount;
        
        localMin = *min_element(arr.begin() + popCount, arr.begin() + i + 1);
        wMax = wMax < localMin ? localMin : wMax; 
        q1.push(i);
        ++i;
    }
    
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
