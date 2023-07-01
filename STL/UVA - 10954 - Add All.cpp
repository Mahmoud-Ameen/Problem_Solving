/**
 * problem link: https://vjudge.net/problem/UVA-10954
 * */
#include <iostream>
#include <queue>

using namespace std;

int main()
{

    int n;
    cin >> n;
    while (n != 0)
    {
        std::priority_queue<int> pq;

        // read and push numbers in pq
        // push numbers to the pq multiplied by -1 to sort them in ascending order
        for (size_t i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            pq.push(num * -1);
        }

        long long cost = 0;
        long long sum = pq.top() * -1;
        pq.pop();

        while (pq.size() >= 2)
        {
            int num = pq.top() * -1;
            pq.pop();
            int num2 = pq.top() * -1;

            if (num + num2 <= sum + num)
            {
                // sum += num + num2;
                cost += num + num2;
                pq.pop();
                pq.push((num + num2) * -1);
            }
            else
            {
                sum += num;
                cost += sum;
            }
        }
        if (!pq.empty())
        {
            int num = pq.top() * -1;
            sum += num;
            cost += sum;
        }

        cout << cost << endl;

        /*----------*/
        cin >> n;
    }
}