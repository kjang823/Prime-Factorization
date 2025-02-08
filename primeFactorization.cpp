#include <map>
#include <iostream>
using namespace std;

int updateElement( map <int, int>& givenMap, int prime_Key, int given_Number ){
    map <int, int>::iterator itr;
    itr = givenMap.find(prime_Key);
    if(itr == givenMap.end()){
        givenMap.insert(make_pair(prime_Key,1));
    } else {
        itr->second = (itr->second)+1;   
    }
    return given_Number/prime_Key;
 }

int main(){

    map<int, int> prime_Map;
    map<int,int>::iterator it_check;

    //Take user requested number to prime factorize.
    cout << "Please enter the number you would like to check is a prime..." << endl;
    int user_Input;
    cin >> user_Input;
    cout << "The number you entered is: " << user_Input << endl;

    //Create a map of primes up to the sqrt of the number.
    //Handle the prime of 2 case.
    while (user_Input % 2 == 0){
        user_Input = updateElement(prime_Map,2,user_Input);
    }
    // } else {
        //Handle primes greater than 2 case. Only odd numbers need be considered this point forward. Only up to the sqrt of the number.
        for (int i = 3; i*i <= user_Input; i = i + 2){
            //So long a i divides user_Input, add the prime to the prime factors map, continue to add 1 for each successful prime factorization.
            while (user_Input % i == 0){
                //Check if the number has been added to the map. If not add, else incrase power count by 1.
                user_Input = updateElement(prime_Map,i,user_Input);
            }
        }
    // }

    //Print out the map of prime factorizations.
    for (auto prime_Num : prime_Map){
        cout << "The Prime factors of the number you entered are(prime/power): " << prime_Num.first << "^" << prime_Num.second << endl;
    }

    return 0;
}
