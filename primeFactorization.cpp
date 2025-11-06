#include <map>
#include <iostream>
#include <chrono>
#include <vector>
#include <cstdint>


using namespace std::chrono;
using namespace std;
#include <bitset>

int updateElement( map <int, int>& given_Map, int prime_Key, int given_Number ){
    map <int, int>::iterator target_Prime;
    target_Prime = given_Map.find(prime_Key);
    if(target_Prime == given_Map.end()){
        given_Map.insert(make_pair(prime_Key,1));
    } else {
        target_Prime->second = (target_Prime->second)+1;   
    }

    return given_Number/prime_Key;
}

bool primeCheck(map <int, int>& prime_Map, int num2Check){
    for (auto prime_Num : prime_Map){
        if (num2Check % (prime_Num.first) == 0){
            return false;
        }
    }
    return true;
}

int main(){

    //Use LONG LONG MAX for testing. 

    //TODO: Set bits for any int, then implement prime factorization on that.
    cout << "THIS PROGRAM IS UNDER CONSTRUCTION." << endl;

    string user_Input;
    cout << "Enter a positive integer to prime factorize: ";
    cin >> user_Input;
    
    map<int, int> prime_Map;
    unsigned long long user_Number = strtoull(user_Input.c_str(), nullptr, 10);;
    if (errno == ERANGE){
        cout << "The number you have entered is out of range. Please enter a smaller positive integer." << endl;
        return 1;
    }


    //Take user requested number to prime factorize.
    //TODO: Check to make sure user input is of correct type. 

    cout << "The number you entered is: " << user_Number << endl;

    //Start timer. 
    auto start = high_resolution_clock::now();

    //Start work.
    while (primeCheck(prime_Map,2) && user_Number % 2 == 0){
        user_Number = updateElement(prime_Map,2,user_Number);
    }

    //Handle primes greater than 2 case. Only odd numbers need be considered this point forward. Only up to the sqrt of the number.
    //TODO: Going through every odd number is too resource intensive. Lots of wasted cycles. Should check if the number is a prime number first. 
    for (unsigned long long i = 3; i*i <= user_Number; i = i + 2){

        while (user_Number % i == 0){
            user_Number = updateElement(prime_Map,i,user_Number);
        }
    }

    //If the number remaining is not 1, then it must be a prime number. Else we have found all prime factorizations.
    while (user_Number != 1){
        user_Number = updateElement(prime_Map,user_Number,user_Number);
    }

    //End work. 

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
