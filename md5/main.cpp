#include <iostream>
#include "includes/md5.h"
#include <chrono>

using std::cout; using std::endl;
using std::string;
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using namespace std::literals::chrono_literals;


const string charOptions = "abcdefghijklmnopqrstuvwxyz1234567890";
const int charOptionSize = charOptions.size();
const int aprox_max_word_len = 4;

const string givenHash = "275a9c70bf8f48e9a54540e3962579c3"; //abc8
long long count = 0;

int main(int argc, char *argv[])
{
    time_point<Clock> start = Clock::now();

    for(int i = 0; i < charOptionSize; i++)
    {
        string guess1{charOptions[i]};
        cout << guess1 << endl;
        if(md5(guess1) == givenHash) {cout << "match, password is: " << guess1 << endl; goto _exit;}
        count++;
        if(aprox_max_word_len == 1) continue;

        for (int j = 0; j < charOptionSize; j++)
        {
            string guess2 = guess1 + charOptions[j];
            cout << guess2 << endl;
            if(md5(guess2) == givenHash) {cout << "match, password is: " << guess2 << endl; goto _exit;}
            count++;
            if(aprox_max_word_len == 2) continue;

            for(int k = 0; k < charOptionSize; k++)
            {
                string guess3 = guess2 + charOptions[k];
                cout << guess3 << endl;
                if(md5(guess3) == givenHash) {cout << "match, password is: " << guess3 << endl; goto _exit;}
                count++;
                if(aprox_max_word_len == 3) continue;

                for(int l = 0; l < charOptionSize; l++)
                {
                    string guess4 = guess3 + charOptions[l];
                    cout << guess4 << endl;
                    if(md5(guess4) == givenHash) {cout << "match, password is: " << guess4 << endl; goto _exit;}
                    count++;
                    if(aprox_max_word_len == 4) continue;

                    for(int m = 0; m < charOptionSize; m++)
                    {
                        string guess5 = guess4 + charOptions[m];
                        cout << guess5 << endl;
                        if(md5(guess5) == givenHash) {cout << "match, password is: " << guess5 << endl; goto _exit;}
                        count++;
                        if(aprox_max_word_len == 5) continue;

                        for(int n = 0; n < charOptionSize; n++)
                        {
                            string guess6 = guess5 + charOptions[n];
                            cout << guess6 << endl;
                            if(md5(guess6) == givenHash) {cout << "match, password is: " << guess6 << endl; goto _exit;}
                            count++;
                        }
                    }
                }
            }
        }
    }
_exit:

    time_point<Clock> end = Clock::now();
    milliseconds diff = duration_cast<milliseconds>(end - start);
    std::cout << diff.count() << "ms" << std::endl;
    cout << "Count "<<count<<endl;
    return 0;
}
