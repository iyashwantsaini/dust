#include <bits/stdc++.h>
using namespace std;

void printstack(stack<int> &stemp)
{
    stack<int> s = stemp;
    while (!s.empty())
    {
        int x = s.top();
        cout << x << " ";
        s.pop();
    }
    cout << "\n";
}

int main()
{
    stack<int> s1, s2;
    int n;
    cin >> n;
    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s1.push(num);
    }

    while (!s1.empty())
    {
        if (s2.empty() || s1.top() > s2.top())
        {
            s2.push(s1.top());
            s1.pop();
            }else{
                break;
            }
        // }
            // start
            if (s1.top() <= 9 && s2.top() <= 9)
            {
                int x = s1.top();
                int y = s2.top();
                if (abs(x - y) == 1)
                {
                    s1.pop();
                    s2.pop();
                    if (x > y)
                    {
                        s2.push((x * 10) + y);
                    }
                    else
                    {
                        s2.push((y * 10) + x);
                    }
                }
            }

            else if (s1.top() <= 9 && s2.top() > 9)
            {
                int x = s1.top();
                int y = s2.top();
                int a = y / 10;
                int b = y % 10;
                if (abs(a - x) == 1 || abs(b - x) == 1)
                {
                    s1.pop();
                    s2.pop();
                    int max, min;

                    // max
                    if (a > b && a > x)
                    {
                        max = a;
                    }
                    else if (b > a && b > x)
                    {
                        max = b;
                    }
                    else if (x > a && x > b)
                    {
                        max = x;
                    }
                    // min
                    if (a < b && a < x)
                    {
                        min = a;
                    }
                    else if (b < a && b < x)
                    {
                        min = b;
                    }
                    else if (x < a && x < b)
                    {
                        min = x;
                    }

                    s2.push((max * 10) + min);
                    if (x > a)
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
            }

            else if (s1.top() > 9 && s2.top() <= 9)
            {
                int y = s1.top();
                int x = s2.top();
                int a = y / 10;
                int b = y % 10;
                if (abs(a - x) == 1 || abs(b - x) == 1)
                {
                    s1.pop();
                    s2.pop();
                    int max, min;

                    // max
                    if (a > b && a > x)
                    {
                        max = a;
                    }
                    else if (b > a && b > x)
                    {
                        max = b;
                    }
                    else if (x > a && x > b)
                    {
                        max = x;
                    }
                    // min
                    if (a < b && a < x)
                    {
                        min = a;
                    }
                    else if (b < a && b < x)
                    {
                        min = b;
                    }
                    else if (x < a && x < b)
                    {
                        min = x;
                    }

                    s2.push((max * 10) + min);
                    if (x > a)
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
            }

            else if (s1.top() > 9 && s2.top() > 9)
            {
                int y = s1.top();
                int x = s2.top();
                int a = y / 10;
                int b = y % 10;
                int c = x / 10;
                int d = x % 10;
                if (abs(a - d) == 1 || abs(b - c) == 1)
                {
                    s1.pop();
                    s2.pop();
                    int max, min;

                    // max
                    if (a > b && a > c && a > d)
                    {
                        max = a;
                    }
                    else if (b > a && b > c && b > d)
                    {
                        max = b;
                    }
                    else if (c > a && c > b && c > d)
                    {
                        max = c;
                    }
                    else if (d > a && d > b && d > c)
                    {
                        max = d;
                    }
                    // min
                    if (a < b && a < c && a < d)
                    {
                        min = a;
                    }
                    else if (b < a && b < c && b < d)
                    {
                        min = b;
                    }
                    else if (c < a && c < b && c < d)
                    {
                        min = c;
                    }
                    else if (d < a && d < b && d < c)
                    {
                        min = d;
                    }

                    s2.push((max * 10) + min);
                    if (x > a)
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
            }

            else if (s2.top() > s1.top())
            {
                int temp = s1.top();
                // s1.pop();
                while (s2.top() > temp
                       ||(
                        !(s2.top() <= 9 && temp <= 9)&&
                        !(s2.top() <= 9 && temp > 9)&&
                        !(s2.top() > 9 && temp <= 9)&&
                        !(s2.top() > 9 && temp > 9)
                       )
                )
                {
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            // printstack(s1);
            // printstack(s2);
        // }
        // else
        // {
        //     break;
        // }
    }

    // cout << "Reached!" << endl;
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    // while (!s1.empty())
    // {
    //     cout << s1.top();
    //     s1.pop();
    // }
}
