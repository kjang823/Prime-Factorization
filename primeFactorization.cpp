#include <map>
#include <iostream>
using namespace std;


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
    if (prime_Map.empty()){
        prime_Map.insert(make_pair(2,1));

    //Handle primes greater than 2 case. Only odd numbers need be considered this point forward.
    } else {
        for (int i = 3; i*i <= user_Input; i = i + 2){
            //So long a i divides user_Input, add the prime to the prime factors map, continue to add 1 for each successful prime factorization.
            cout << "Trying out factors of " << i << endl;
            //If I divided evenly into user_Input, create the pair and add into map. Otherwise, skip.
            while (user_Input % i == 0){
                //Check if the number has been added to the map. If not add, else incrase power count by 1.
                it_check = prime_Map.find(i);
                if(it_check == prime_Map.end()){
                    prime_Map.insert(make_pair(i,1));
                } else {
                    it_check->second = (it_check->second)+1;
                    cout << (it_check->second) << endl;
                }

                user_Input = user_Input/i;
            }
        }
    }

    //Print out the map of prime factorizations.
    for (auto prime_Num : prime_Map){
        cout << "The Prime factors of the number you entered are(prime/power): " << prime_Num.first << " " << prime_Num.second << endl;
    }

    return 0;
}
