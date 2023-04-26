#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#define MAX_LEN 100


using namespace std;

//question1
int* common(int array1[],int array2[]){
    int size1 = sizeof(array1)/sizeof(array1[0]);
    int size2 = sizeof(array2)/sizeof(array2[0]);

    int* temp = new int[size1];


    int index = 0;
    for (int i = 0; i < size1; i++) {

        bool isFound = false;
        for (int j = 0; j < size2; j++) {
            if (array1[i] == array2[j]) {
                isFound = true;
                break;
            }
        }

        if (isFound) {
            temp[index] = array1[i];
            index++;
        }
    }

    int* finalTemp = new int[index];
    for (int i = 0; i < index; i++) {
        finalTemp[i] = temp[i];
    }

    delete[] temp;

    return finalTemp;
}




//question2
int isPalindrome(string string1) {
    int length = string1.length();
    for (int i = 0; i < length / 2; i++) {
        if (string1[i] != string1[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

//question3
bool is_prime(int number) {
    if(number < 2) {
        return false;
    }
    for(int i = 2; i <= sqrt(number); i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

//question4
bool is_anagram(char *word1, char *word2) {
    int number1[26] = {0}, number2[26] = {0};
    int length1 = strlen(word1), length2 = strlen(word2);

    if (length1 != length2) {
        return false;
    }

    for (int i = 0; i < length1; i++) {
        number1[word1[i] - 'a']++;
        number2[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (number1[i] != number2[i]) {
            return false;
        }
    }

    return true;
}




int main() {

    int list1[] = {18, 32, 76, 4, 1};

    int list2[] = {1, 4, 86, 71, 18};


    int* result = common(list1,list2 );

    int resultSize = sizeof(result) / sizeof(result[0]);

    cout<<"Q1";
    for (int i = 0; i < resultSize; i++) {
        std::cout << result[i] <<endl;
    }
    cout<<endl;

    string strings[] = {"selin", "ata", "ana", "kelime"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);
    string palindromes[numStrings];
    int numPalindromes = 0;
    for (int i = 0; i < numStrings; i++) {
        if (isPalindrome(strings[i])) {
            palindromes[numPalindromes] = strings[i];
            numPalindromes++;
        }
    }

    cout<<"Q2";
    for (int i = 0; i < numPalindromes; i++) {
        cout << palindromes[i] <<endl;
    }
    cout << endl;

    int nums[] = {2, 5,98,16,7,11};
    int size = sizeof(nums)/sizeof(nums[0]);
    int num_primes = 0;

    for(int i = 0; i < size; i++) {
        if(is_prime(nums[i])) {
            num_primes++;
        }
    }

    int primes[num_primes];
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(is_prime(nums[i])) {
            primes[j++] = nums[i];
        }
    }


    cout << endl << "Q3 ";
    for(int i = 0; i < num_primes; i++) {
        cout << primes[i] << endl;
    }
    cout<<endl;
    char word[MAX_LEN];
    char word_list[][MAX_LEN] = {"enlists", "google", "inlets", "banana"};
    int n = sizeof(word_list) / sizeof(word_list[0]);

    cout<<"Q4"<< endl;
    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; i < n; i++) {
        if (is_anagram(word, word_list[i])) {
            cout << word_list[i] << endl;
        }

    }


    return 0;
}
