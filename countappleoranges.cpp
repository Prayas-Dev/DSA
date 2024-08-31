#include<iostream>
#include<vector>

using std::cout;
using std::vector;
using std::endl;

void countApplesandOranges(int s, int t, int a, int b,int apples_count, const vector<int>& apples, int oranges_count, const vector<int>& oranges){
    int apples_on_house=0;
    int oranges_on_house=0;

// Counting apples that fall on the house
    for(int i=0;i<apples_count;i++){
        int landing_position=a+apples[i];               // Calculate where the apple falls
        if(landing_position>=s && landing_position <=t){
            apples_on_house++;
        }
    }

     // Counting oranges that fall on the house
    for(int i=0;i<oranges_count;i++){
        int landing_position=b+oranges[i];              // Calculate where the orange falls
        if(landing_position>=s && landing_position<=t){
            oranges_on_house++;
        }
    }
    cout<<apples_on_house<<endl;
    cout<<oranges_on_house<<endl;
}

int main(){
    int s=7, t=10;              // House boundaries
    int a=12,b=14;              // Apples and orange trees position
    
    vector<int> apples={2,3,-4};        // Distances of the apples from the trees
    vector<int> oranges={3,-2,-4};

    int apples_count=apples.size();
    int oranges_count=oranges.size();

    countApplesandOranges(s,t,a,b,apples_count,apples,oranges_count,oranges);

    return 0;
}
