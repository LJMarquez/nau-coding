#include <iostream>
#include <cstdlib>
#include <cstring>

#define CHARACTERS 256

bool decode(const char *scrambled_message, const char *reference_message)
{
    // initialize an array to count character occurrences, set all counts to 0
    int char_count[256] = {0};
    // TODO

    // count characters in the scrambled message
        // traverse the scrambled message
    for(int i = 0; i < (int)strlen(scrambled_message); i++)
    {
        char_count[(int)scrambled_message[i]]++;
    }

    // TODO

    // subtract counts using the reference message
        // traverse the reference message
    for(int i = 0; i < (int)strlen(reference_message); i++)
    {
        char_count[(int)reference_message[i]]--;
    }

    // TODO

    // check if all counts are zero
        // traverse the array
    for(int i = 0; i < CHARACTERS; i++)
    {
        if(char_count[i] != 0)
        {
            return false;
        }
    }

    // TODO

    // if the loop doesn't return, the message is an anagram
    return true;
}

int main()
{
    // int array[256] = {0};
    // char str[256] = "fadskjhgrefrhlgjdsfhvbleirufwergbej";
    // std::cout << "Hello, World!" << std::endl;
    // array[(int)str[0]]++;
    // std::cout << str[0] << std::endl;
    // for(int i = 0; i < 26; i++)
    // {
    //     std::cout << array[i] << std::endl;
    // }

    std::cout << "Testing decode function..." << std::endl;
    const char *scrambled_message = "listen";
    const char *reference_message = "silent";
    if(decode(scrambled_message, reference_message))
    {
        std::cout << "The messages are anagrams." << std::endl;
    }
    else
    {
        std::cout << "The messages are not anagrams." << std::endl;
    }

    return 0;
}