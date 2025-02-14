#include <map>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int updateElement( map <long long, int>& givenMap, long long prime_Key, long long given_Number ){
    //TODO: A large enough number will result in a negative prime number. This needs to be investigated and dealth with.
    map <long long, int>::iterator target_Prime;
    target_Prime = givenMap.find(prime_Key);
    if(target_Prime == givenMap.end()){
        givenMap.insert(make_pair(prime_Key,1));
    } else {
        target_Prime->second = (target_Prime->second)+1;   
    }

    //Debugging lines
    cout << "The original number is: " << given_Number << endl;
    cout << "The prime number is: " << prime_Key << endl;
    cout << "The division result is: " << given_Number/prime_Key << endl;
    // cout << given_Number/prime_Key << endl;
    return given_Number/prime_Key;
 }

int main(){

    //Use LONG LONG MAX for testing. 
    
    map<long long, int> prime_Map;
    long long user_Input;

    //Take user requested number to prime factorize.
    //TODO: Check to make sure user input is of correct type. 
    cout << "Please enter the number you would like to check is a prime..." << endl;
    cin >> user_Input;
    cout << "The number you entered is: " << user_Input << endl;

    //Start timer. 
    auto start = high_resolution_clock::now();

    //Create a map of primes up to the sqrt of the number.
    //Handle the prime of 2 case.
    while (user_Input % 2 == 0){
        user_Input = updateElement(prime_Map,2,user_Input);
    }

    //Handle primes greater than 2 case. Only odd numbers need be considered this point forward. Only up to the sqrt of the number.
    //TODO: Going through every odd number is too resource intensive. Lots of wasted cycles. Should check if the number is a prime number first. 
    for (long long i = 3; i*i <= user_Input; i = i + 2){
        //So long a i divides user_Input, add the prime to the prime factors map, continue to add 1 for each successful prime factorization.
        while (user_Input % i == 0){
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
    cout << "The Prime factors are (prime^power): ";
    for (auto prime_Num : prime_Map){
        cout << prime_Num.first << "^" << prime_Num.second << " ";
    }
    cout << endl;

    cout << "Calculating prime factorization took " << (duration_cast<milliseconds>(end-start)).count() << " milliseconds." << endl;

    return 0;
}
