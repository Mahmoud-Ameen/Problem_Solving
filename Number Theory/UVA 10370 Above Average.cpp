#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<double> grades(1000);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> grades[i];
            sum += grades[i];
        }
        double average = sum / n;
        double aboveAverage = 0;
        for (int i = 0; i < n; ++i) {
            if(grades[i] > average)
                aboveAverage++;
        }

        cout << fixed << setprecision(3) << aboveAverage/n * 100 << "%\n";
    }
}