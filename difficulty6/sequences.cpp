//https://open.kattis.com/problems/sequences
//0-1 sequence, difficulty 6.7

//Note: using long long int is critical since square(1000000007) can easily exceed limitation of int


#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#define MODNUM 1000000007
long long int power[500001];
//Generate powers of two.
void genpows() {
    int num = 1;
    for(int i = 0; i<= 500000;i++) {
        power[i] = num;
        num*= 2;
        num = num%MODNUM;
    }
}

int main(int argc, char* argv[]){
    int mod_num = MODNUM;
    using namespace::std;
    int count_1 = 0;
    long long int res_3 = 0;
    char x;
    string buff;
    vector<int> counts;
    genpows();

    //Count from start, check inversion of 1 and unknown. Build string of input and vector of unknowns.
    while(cin.get(x) && (x == '1' || x == '0' || x=='?')){
        buff += x;
        switch (x)
        {
        case '1':
            count_1++;
            break;
        case '?':
            counts.push_back(count_1);
            break;
        default:
            res_3 += count_1;
            res_3 %= mod_num;
            break;
        }
    }
    int count_0 = 0;
    int count_que = counts.size() - 1;
    //Count from back, check inversion of 0 and unknown.
    for(int i = buff.size() - 1; i >= 0; i--){
        switch (buff[i])
        {
        case '0':
            count_0++;
            break;
        case '?':
            counts[count_que] += count_0;
            count_que --;
            break;
        default:
            break;
        }
    }
    long long int res_1 = counts.size() * (counts.size() - 1) / 2 %mod_num;
    long long int res_2 = 0;
    for(int i = 0; i < counts.size(); i++){
        res_2 += counts[i];
        res_2 %= mod_num;
    }

    //res_1 : inversion of unknown and unknown
    //res_2 : inversion of known and unknown
    //res_3 : inversion of known and known

    if(counts.size() == 0){
        cout << res_3% mod_num << endl;
    }else if(counts.size() == 1){
        cout << (res_2 + res_3*2)% mod_num << endl;
    }else{
        long long int mul_1 = power[counts.size() - 2] ;
        long long int mul_2 = power[counts.size() - 1] ;
        long long int mul_3 = power[counts.size()];
        
        cout << ((res_1*mul_1 % mod_num+ res_2 * mul_2 % mod_num+ res_3 * mul_3% mod_num) % mod_num) << endl;
    }
    return 0;
}
