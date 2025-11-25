#include <map>
#include <iostream>
#include <chrono>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <bitset>
#include <cerrno>


int updateElement( std::map <int, int>& given_Map, int prime_Key, int given_Number ){
    std::map <int, int>::iterator target_Prime;
    target_Prime = given_Map.find(prime_Key);
    if(target_Prime == given_Map.end()){
        given_Map.insert(std::make_pair(prime_Key,1));
    } else {
        target_Prime->second = (target_Prime->second)+1;   
    }

    return given_Number/prime_Key;
}

bool primeCheck(std::map <int, int>& prime_Map, int num2Check){
    for (auto prime_Num : prime_Map){
        if (num2Check % (prime_Num.first) == 0){
            return false;
        }
    }
    return true;
}

int main(){
    
    std::map<int, int> prime_Map;
    //Use LONG LONG MAX for testing. 

    //TODO: Set bits for any int, then implement prime factorization on that.
    std::cout << "THIS PROGRAM IS UNDER CONSTRUCTION." << std::endl;

    int user_Number;
    std::cout << "Enter a positive integer to prime factorize: ";
    std::cin >> user_Number;    

    /*
    TODO: Multithreading Implementation
        1. Thread the clock
        2. Thread integers to check if they are a prime number.
        3. Thread to make sure that the prime numbers are prime factors of the user entered number.
    */
    auto start = std::chrono::high_resolution_clock::now();
    //Start timer.
    //Start work.
    while (primeCheck(prime_Map,2) && user_Number % 2 == 0){
        user_Number = updateElement(prime_Map,2,user_Number);
    }

    //Handle primes greater than 2 case. Only odd numbers need be considered this point forward. Only up to the sqrt of the number.
    //TODO: Going through every odd number is too resource intensive. Lots of wasted cycles. Should check if the number is a prime number first. 
    for (int i = 3; i*i <= user_Number; i = i + 2){

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
    auto end = std::chrono::high_resolution_clock::now();

    //Print out the map of prime factorizations.
    std::cout << "The Prime factors are (prime^power): ";
    for (auto prime_Num : prime_Map){
        std::cout << prime_Num.first << "^" << prime_Num.second << " ";
    }
    std::cout << std::endl;

    std::cout << "Calculating prime factorization took " << (std::chrono::duration_cast<std::chrono::nanoseconds>(end-start)).count() << " nanoseconds." << std::endl;

    return 0;
}
