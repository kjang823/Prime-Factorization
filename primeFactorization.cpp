#include <map>
#include <iostream>
#include <chrono>
#include <climits>
#include <vector>
// using namespace chrono;

#include <bitset>
#include <iostream>
#include <climits>

int main() {
    struct beyond_Long_Long {
        std::vector<uint64_t> bits; // Each element holds 64 bits
    };
    const size_t BITS_IN_UINT64 = 64;
    size_t num_Bits = 130; // Example: 130 bits
    size_t num_Elements = (num_Bits + BITS_IN_UINT64 - 1) / BITS_IN_UINT64; // Calculate number of uint64_t needed  
    beyond_Long_Long bigNum;
    bigNum.bits.resize(num_Elements, 0); // Initialize all bits to 0
    // Set some bits for demonstration
    bigNum.bits[0] = 0xFFFFFFFFFFFFFFFF; // First 64 bits set to 1
    bigNum.bits[1] = 0x0000000000000003; // Next bits set to 11 (for 130 bits total)
    // Print the bits
    for (size_t i = 0; i < bigNum.bits.size(); ++i) {
        std::bitset<BITS_IN_UINT64> bs(bigNum.bits[i]);
        std::cout << "Element " << i << ": " << bs << std::endl;
    }
    printf("The number is: %llu%llu\n", bigNum.bits[1], bigNum.bits[0]);
    return 0;
}

// unsigned long long updateElement( map <unsigned long long, int>& given_Map, unsigned long long prime_Key, unsigned long long given_Number ){
//     map <unsigned long long, int>::iterator target_Prime;
//     target_Prime = given_Map.find(prime_Key);
//     if(target_Prime == given_Map.end()){
//         given_Map.insert(make_pair(prime_Key,1));
//     } else {
//         target_Prime->second = (target_Prime->second)+1;   
//     }

//     return given_Number/prime_Key;
// }

// bool primeCheck(map <unsigned long long, int>& prime_Map, unsigned long long num2Check){
//     for (auto prime_Num : prime_Map){
//         if (num2Check % (prime_Num.first) == 0){
//             return false;
//         }
//     }
//     return true;
// }

// int main(){

//     //Use LONG LONG MAX for testing. 
    
//     map<unsigned long long, int> prime_Map;
//     unsigned long long user_Input;

//     //Take user requested number to prime factorize.
//     //TODO: Check to make sure user input is of correct type. 
//     cout << "Please enter the number you would like to check is a prime..." << endl;
//     cin >> user_Input;
//     if (user_Input > ULLONG_MAX){
//         cout << "The number is too large." << endl;
//         exit(EXIT_FAILURE);
//     }

//     cout << "The number you entered is: " << user_Input << endl;

//     //Start timer. 
//     auto start = high_resolution_clock::now();

//     //Start work.
//     while (primeCheck(prime_Map,2) && user_Input % 2 == 0){
//         user_Input = updateElement(prime_Map,2,user_Input);
//     }

//     //Handle primes greater than 2 case. Only odd numbers need be considered this point forward. Only up to the sqrt of the number.
//     //TODO: Going through every odd number is too resource intensive. Lots of wasted cycles. Should check if the number is a prime number first. 
//     for (unsigned long long i = 3; i*i <= user_Input; i = i + 2){

//         while (user_Input % i == 0){
//             user_Input = updateElement(prime_Map,i,user_Input);
//         }
//     }

//     //If the number remaining is not 1, then it must be a prime number. Else we have found all prime factorizations.
//     while (user_Input != 1){
//         user_Input = updateElement(prime_Map,user_Input,user_Input);
//     }

//     //End work. 

//     //End timer.
//     auto end = high_resolution_clock::now();

//     //Print out the map of prime factorizations.
//     cout << "The Prime factors are (prime^power): ";
//     for (auto prime_Num : prime_Map){
//         cout << prime_Num.first << "^" << prime_Num.second << " ";
//     }
//     cout << endl;

//     cout << "Calculating prime factorization took " << (duration_cast<milliseconds>(end-start)).count() << " milliseconds." << endl;

//     return 0;
// }
