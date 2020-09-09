#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::ofstream out;          
    out.open("hello.txt"); 
    if (!out) {
        std::cout << "Cannot open file.\n";
        return 1;
    }

    if (out.is_open())
    {
            std::cout << "Enter the word:\n";
            std::cin.ignore();
            std::string line;
        while ((getline(std::cin, line)) && !line.empty())
        {
                out << line;
        }
    }

    return 0;
}
