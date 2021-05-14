#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("exe.txt", ios::in);
    if (fin.fail())
    {
        cout << "\nFile opening failed\nMaybe No file named : exe.txt";
        return 0;
    }

    string str = "";
    while (!fin.eof())
    {
        char x = fin.get();
        str += x;
    }
    fin.close();

    vector<string> links;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'h')
        {
            if (str.substr(i, 6) == "href=\"")
            {
                // here is a link
                i += 6;
                string link = "";
                bool dot = false;
                while (str[i] != '\"')
                {
                    if (str[i] == '.')
                        dot = true;
                    link += str[i];
                    i++;
                }
                if (dot && *prev(link.end()) != '/')
                    links.push_back("https://archive.thehated6.workers.dev" + link);
            }
        }
    }

    system("echo \"\" > list.txt ");

    for (int i = 0; i < links.size(); i++)
    {
        string temp = "echo \"" + links[i] + "\" >> list.txt";
        system(temp.c_str());
    }

    system("cat list.txt | sed \"s/?a=view//g\" | sed \"s/ /%20/g\" | sort -u > list");
    system("rm list.txt");

    return 0;
}