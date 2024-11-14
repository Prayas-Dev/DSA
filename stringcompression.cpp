#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // int compress(vector<char> &chars)
    // {
    //     int n = chars.size();
    //     int idx = 0;

    //     for (int i = 0; i < n;)
    //     {
    //         char ch = chars[i];
    //         int count = 0;

    //         while (i < n && chars[i] == ch)
    //         {
    //             count++;
    //             i++;
    //         }

    //         chars[idx++] = ch;

    //         if (count > 1)
    //         {
    //             string str = to_string(count);
    //             for (char dig : str)
    //             {
    //                 chars[idx++] = dig;
    //             }
    //         }
    //     }
    //     chars.resize(idx);
    //     return idx;
    // }
    int compress(vector<char>&chars){
        int n=chars.size();
        int idx=0;

        for(int i=0;i<n;){
            int count=0;
            int ch=chars[i];

            while(i<n && chars[i]==ch){
                count++;
                i++;
            }
            chars[idx++]=ch;

            if(count>1){
                string str=to_string(count);
                for(char dig:str){
                    chars[idx++]=dig;
                }
            }
        }
        chars.resize(idx);
        return idx;
    }
};

int main()
{

    Solution sol;
    int number;
    char ch;

    cout<<"Enter the number of characters you want to add : ";
    cin>>number;
    vector<char> chars;
    for(int i=0;i<number;i++){
        cout<<"Enter character : "<<i+1<<": ";
        cin>>ch;
        chars.push_back(ch);
    }
    int newLength = sol.compress(chars);
    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for (char c : chars)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}