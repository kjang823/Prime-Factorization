#include <map>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int updateElement( map <int, int>& givenMap, int prime_Key, int given_Number ){
    map <int, int>::iterator target_Prime;
    target_Prime = givenMap.find(prime_Key);
    if(target_Prime == givenMap.end()){
        givenMap.insert(make_pair(prime_Key,1));
    } else {
        target_Prime->second = (target_Prime->second)+1;   
    }
    return given_Number/prime_Key;
 }

int main(){

    map<int, int> prime_Map;
    int user_Input, orig_Number;

    //Take user requested number to prime factorize.
    cout << "Please enter the number you would like to check is a prime..." << endl;
    cin >> user_Input;
    orig_Number = user_Input;
    cout << "The number you entered is: " << user_Input << endl;

    //Start timer. 
    auto start = high_resolution_clock::now();
    //Create a map of primes up to the sqrt of the number.
    //Handle the prime of 2 case.
    while (user_Input % 2 == 0){
        user_Input = updateElement(prime_Map,2,user_Input);
    }

    //Handle primes greater than 2 case. Only odd numbers need be considered this point forward. Only up to the sqrt of the number.
    for (int i = 3; i*i <= user_Input; i = i + 2){
        //So long a i divides user_Input, add the prime to the prime factors map, continue to add 1 for each successful prime factorization.
        while (user_Input % i == 0){
            //Check if the number has been added to the map. If not add, else incrase power count by 1.
            user_Input = updateElement(prime_Map,i,user_Input);
        }
    }

    //If the number remaining is not 1, then it must be a prime number. Else we have found all prime factorizations.
    while (user_Input != 1){
        user_Input = updateElement(prime_Map,user_Input,user_Input);
    }

    //End timer.
    auto end = high_resolution_clock::now();

    //Print out the map of prime factorizations.
    cout << "The Prime factors of " << orig_Number << " are (prime^power): ";
    for (auto prime_Num : prime_Map){
        cout << prime_Num.first << "^" << prime_Num.second << " ";
    }
    cout << endl;

    cout << "Calculating prime factorization took " << (duration_cast<milliseconds>(end-start)).count() << " milliseconds." << endl;

    return 0;
}
