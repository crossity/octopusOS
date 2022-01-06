#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdio.h>
#include <filesystem>

namespace fs = std::__fs::filesystem;

using namespace std;
void textEditor(string userName);
void app(string WayToFile, string userName);
bool work = true;

string input;
string name;
string fastString;

int main()
{
    cout << "\033c";
    cout << "Please enter user name: ";
    getline(cin, name);
    cout << "\033c";
    cout << "Hello " << name << endl << endl;
	while (work)
	{
        cout << name << " %:";
		getline(cin, input);
		if (input == "-edit")
        {
            cout << "\033c";
			textEditor(name);
            cout << "\033c";
        }
        else if (input == "-run")
        {
            string path = "/Users/savvapos/Desktop/My own operation system/"  + name + "/";
            for (const auto & entry : fs::directory_iterator(path))
            {
                string file_name = entry.path();
                if (file_name != "/Users/savvapos/Desktop/My own operation system/" + name + "/.DS_Store")
                {
                    for (int o = 49 + name.size(); o < file_name.size(); o++)
                        cout << file_name[o];
                    cout << endl;
                }         
            }
            cout << name << " please enter application name: ";
            getline(cin, input);
            app(input, name);
            cout << endl;
        }
        else if (input == "-cls")
            cout << "\033c";
        else if (input == "-list")
        {
            string path = "/Users/savvapos/Desktop/My own operation system/" + name + "/";
            for (const auto & entry : fs::directory_iterator(path))
            {
                string file_name = entry.path();
                if (file_name != "/Users/savvapos/Desktop/My own operation system/" + name + "/.DS_Store")
                {
                    for (int o = 49 + name.size(); o < file_name.size(); o++)
                        cout << file_name[o];
                    cout << endl;
                }         
            }
        }
        else if (input == "-esc")
            work = false;
        else if (input == "-delete")
        {
            while (input != "-close")
            {
                string path = "/Users/savvapos/Desktop/My own operation system/" + name + "/";
                for (const auto & entry : fs::directory_iterator(path))
                {
                    string file_name = entry.path();
                    if (file_name != "/Users/savvapos/Desktop/My own operation system/" + name + "/.DS_Store")
                    {
                        for (int o = 49 + name.size(); o < file_name.size(); o++)
                            cout << file_name[o];
                        cout << endl;
                    }         
                }
                getline(cin, input);
                if (input != "-close")
                {
                    string fileName = "/Users/savvapos/Desktop/My own operation system/" + name + "/" + input;
                    const char * rem_file = fileName.c_str();
                    int state = remove(rem_file);
                    if (state == 0)
                        cout << "\033c" << "deleted successful"<< endl << endl << endl;
                    else 
                        cout << "\033c" << "file not deleted!" << endl << endl << endl;
                }
            }
        }
        else if (input == "input ?")
        {
            cout << "0  1  2  3  4  5  6  7  8  9  _  -  +  =  !  @" << endl; 
            cout << "0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15" << endl << endl;
            cout << "#  $  %  ^  &  *  (  )  {  }  [  ]  <  >  /  :" << endl;
            cout << "16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31" << endl << endl;
            cout << ";  ?  ~  q  w  e  r  t  y  u  i  o  p  a  s  d" << endl;
            cout << "32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47" << endl << endl;
            cout << "f  g  h  j  k  l  z  x  c  v  b  n  m" << endl;
            cout << "48 49 50 51 52 53 54 55 56 57 58 59 60" << endl;
        }
        else if (input == "buf<")
            getline(cin, fastString);
        else if (input == "buf>")
            cout << fastString << endl;
        else if (input == "-logout")
        {
            cout << "\033c";
            cout << "Please enter user name: ";
            getline(cin, name);
            cout << "\033c";
            cout << "Hello " << name << endl << endl;
        }
		else 
			cout << "ERROR: no command " << input << endl;
	}
	return 0;
}

void textEditor(string userName)
{
	int string_on = 0; // variable of string that user on
	bool run = true;
	string input;
	string dir;
	char sep = ' ';
	int x = 0;

    vector<string> buffer; // memory of editor
    
    buffer.resize(8);
    
    cout << "file to work wtih: ";
    getline(cin, dir);
    
    cout << "type of reading o/r : ";
    cin >> input;
    
    if (input == "o")
    {
        ifstream startfile("/Users/savvapos/Desktop/My own operation system/" + userName + "/"+ dir);
        string line;
        int i = 0;
        while (getline(startfile, line))
        {
            buffer[i] = line;
            i++;
            buffer.resize(buffer.size() + 1);
        }
        startfile.close();
    }
    
    ofstream file(dir);
    
    if (file.is_open())
        cout << "file is open!";
    
    while (run)
    {

        cout << "\x1b[35m" << "        ###" << endl;
        cout << "      #    #" << endl;
        cout << "     #  #  #" << endl;
        cout << "     #   ##" << endl;
        cout << "     #" << endl;
        cout << "      #" << endl;
        cout << "        #" << endl << endl;
        cout << "(.-.)" << "\x1b[0m" << endl << endl;
        for (int i = x; i < x + 8; i++)
        {
            if (i > 9 && i < 100)
                cout << "\x1b[31m" << i << " | " << "\x1b[0m";
            else if (i > 99 && i < 1000)
                cout << "\x1b[31m" << i << "| " << "\x1b[0m";
            else if (i > 999)
                cout << "\x1b[31m" << i << "|" << "\x1b[0m";
            else
                cout << "\x1b[31m" << i << "  | " << "\x1b[0m";
            for (int wr = 0; wr < buffer[i].size(); wr++)
            {
            	string wrd;
            	while (buffer[i][wr] != ' ' && wr < buffer[i].size())
            	{
            		wrd += buffer[i][wr];
            		wr++;
            	}
            	if (wrd == "mem" || wrd == "num" || wrd == "char" || wrd == "\\n" || wrd == "\\s")
            		cout << "\x1b[35m";
            	else if (wrd == ":=" || wrd == ":+" || wrd == ":-" || wrd == ":*" || wrd == ":/" || wrd == ":%" || wrd == ":sqrt" || wrd == "<<" || wrd == "<" || wrd == ">" || wrd == "<=" || wrd == ">=" || wrd == "==" || wrd == "?")
            		cout << "\x1b[36m";
            	else if (wrd == "printW" || wrd == "move" || wrd == "@" || wrd == "&")
            		cout << "\x1b[31m";
            	else if (wrd == "print" || wrd == "~")
            		cout << "\x1b[32m";
            	cout << wrd << "\x1b[0m";
                if (wr < buffer[i].size())
                    cout << " ";
            }

            if (string_on == i)
                cout << "\x1b[37m" << "#" << "\x1b[0m" << endl;
            else
                cout << endl;
        }

        cout << "\x1b[31m" << "-------------------------------------------------------------" << "\x1b[0m" << endl;

        getline(cin, input);
        
        if (input == "-c")
        {
            buffer.erase(buffer.begin() + string_on - 1);
            if (string_on != 0)
                string_on--;
            buffer.resize(buffer.size() + 1);
        }
        
        if (input == "-s")
        {
            string_on++;
            if (string_on >= x + 8)
            {
                x++;
                buffer.resize(buffer.size() + 1);
            }
        }
        
        if (input == "-w" && string_on > 0)
        {
            string_on -= 1;
            if (string_on < x)
                x--;
        }

        if (input == "-e")
        {
            buffer.resize(buffer.size() + 1);
            buffer.emplace(buffer.begin() + string_on, (string)"");
            string_on++;
            if (string_on >= x + 8)
            {
                x++;
            }
        }

        if (input == "-b")
        {
            buffer[string_on].pop_back();
        }

        if (input == "-d")
        {
            int in;
            cin >> in;
            cout << in << "," << buffer.size() << endl;
            while (buffer.size() < in)
                buffer.resize(buffer.size() + 1);
            if (in >= 0)
            {
                string_on = in;
                x = in;
            }
        }
        if (input ==  "-close")
            run = false;
        if (input == "buf<")
        {
            getline(cin, fastString);
            input = "";
        }
        if (input == "buf>")
        {
            input = "";
            cout << fastString;
            getchar();
        }

        if (input.size() > 0 && input != "-c" && input != "-s" && input != "-w" && input != "-e" && input != "-b" && input != "-d" && input != "-close")
        {
            buffer[string_on] += input;
        }

        cout << "\033c";
    }
    
    ofstream File("/Users/savvapos/Desktop/My own operation system/" + userName + "/" + dir);

    for (int i = (int)buffer.size() - 1; buffer[i] == ""; i--)
        buffer.pop_back();
    
    for (int i = 0; i < buffer.size(); i++)
        File << buffer[i] << endl;
    
    file.close();
    File.close();
}

void app(string WayToFile, string userName)
{
    vector<string> words;
    string letters = "0123456789_-+=!@#$%^&*(){}[]<>/:;?~qwertyuiopasdfghjklzxcvbnm";

    vector<float> fastMemory = {0.0f};
    vector<float> stack = {0.0f};
    vector<string> links_names;
    vector<int> links;

    ifstream file("/Users/savvapos/Desktop/My own operation system/" + userName + "/" + WayToFile);
    if (!file.is_open())
        cout << "ERROR: no such file";
    else
    {
        string word;
        while (file)
        {
            char t;
            file >> noskipws >> t;
            if (t != ' ' && t != '\t' && t != '\n')
            {
                word += t;
            } 
            else 
            {
                words.push_back(word);
                word = "";
            }
        }
        for (int W = 0; words[W] != "@@" && words[W] != "@"; W++)
        {
            // deleting memory element
            if (words[W] == "delete")
            {
                W++;
                if (words[W] == "mem")
                {
                    W++;
                    if (words[W] == ":")
                    {
                        W++;
                        if (words[W] == "mem")
                        {
                            W++;
                            if (words[W] == ":")
                            {
                                W++;
                                fastMemory.erase(fastMemory.begin() + (int)fastMemory[stoi(words[W])]);
                            }
                        }
                        else if (words[W] == "&")
                        {
                            W++;
                            for (int i = 0; i < links_names.size(); i++)
                            {
                                if (links_names[i] == words[W])
                                {
                                    fastMemory.erase(fastMemory.begin() + (int)fastMemory[links[i]]);
                                }
                            }
                        }
                        else
                            fastMemory.erase(fastMemory.begin() + stoi(words[W]));
                    }
                }
            }

            // text
            if (words[W] == "%")
            {
                W++;
                while (words[W] != "%")
                    W++;
            }

            // if loop
            if (words[W] == "?")
            {
                W++;
                if (words[W] == "mem")
                {
                    W++;
                    if (words[W] == ":")
                    {
                        W++;
                        float meaning;
                        float meaning2;
                        string sign;
                        if (words[W] == "mem")
                        {
                            W++;
                            if (words[W] == ":")
                            {
                                W++;
                                meaning = fastMemory[(int)fastMemory[stoi(words[W])]];
                            }
                        }
                        else if (words[W] == "&")
                        {
                            W++;
                            for (int i = 0; i < links_names.size(); i++)
                            {
                                if (links_names[i] == words[W])
                                {
                                    meaning = fastMemory[(int)fastMemory[links[i]]];
                                }
                            }
                        }
                        else
                            meaning = fastMemory[stoi(words[W])];
                        W++;
                        sign = words[W];
                        W++;
                        if (words[W] == "mem")
                        {
                            W++;
                            if (words[W] == ":")
                            {
                                W++;
                                if (words[W] == "mem")
                                {
                                    W++;
                                    if (words[W] == ":")
                                    {
                                        W++;
                                        meaning2 = fastMemory[(int)fastMemory[stoi(words[W])]];
                                    }
                                }
                                else if (words[W] == "&")
                                {
                                    W++;
                                    for (int i = 0; i < links_names.size(); i++)
                                    {
                                        if (links_names[i] == words[W])
                                        {
                                            meaning2 = fastMemory[(int)fastMemory[links[i]]];
                                            break;
                                        }
                                    }
                                }
                                else 
                                    meaning2 = fastMemory[stof(words[W])];
                            }
                        }
                        else if (words[W] == "&")
                        {
                            W++;
                            for (int i = 0; i < links_names.size(); i++)
                            {
                                if (links_names[i] == words[W])
                                {
                                    meaning2 = fastMemory[links[i]];
                                    break;
                                }
                            }
                        }
                        else
                            meaning2 = stof(words[W]);
                        W++;
                        if (sign == "==")
                        {
                            if (meaning == meaning2)
                            {
                                W += 1;
                            }
                            else
                            {
                                int brackets = 1;
                                W += 1;
                                while (brackets != 0)
                                {
                                    W++;
                                    if (words[W] == "{")
                                        brackets++;
                                    if (words[W] == "}")
                                        brackets--;
                                }
                            }
                        }
                        if (sign == ">")
                        {
                            if (meaning > meaning2)
                            {
                                W += 1;
                            }
                            else
                            {
                                int brackets = 1;
                                W += 1;
                                while (brackets != 0)
                                {
                                    W++;
                                    if (words[W] == "{")
                                        brackets++;
                                    if (words[W] == "}")
                                        brackets--;
                                }
                            }
                        }
                        if (sign == "<")
                        {
                            if (meaning < meaning2)
                            {
                                W += 1;
                            }
                            else
                            {
                                int brackets = 1;
                                W += 1;
                                while (brackets != 0)
                                {
                                    W++;
                                    if (words[W] == "{")
                                        brackets++;
                                    if (words[W] == "}")
                                        brackets--;
                                }
                            }
                        }
                        if (sign == ">=")
                        {
                            if (meaning >= meaning2)
                            {
                                W += 1;
                            }
                            else
                            {
                                int brackets = 1;
                                W += 1;
                                while (brackets != 0)
                                {
                                    W++;
                                    if (words[W] == "{")
                                        brackets++;
                                    if (words[W] == "}")
                                        brackets--;
                                }
                            }
                        }
                        if (sign == "<=")
                        {
                            if (meaning <= meaning2)
                            {
                                W += 1;
                            }
                            else
                            {
                                int brackets = 1;
                                W += 1;
                                while (brackets != 0)
                                {
                                    W++;
                                    if (words[W] == "{")
                                        brackets++;
                                    if (words[W] == "}")
                                        brackets--;
                                }
                            }
                        }
                        if (sign == "!=")
                        {
                            if (meaning != meaning2)
                            {
                                W += 1;
                            }
                            else
                            {
                                int brackets = 1;
                                W += 1;
                                while (brackets != 0)
                                {
                                    W++;
                                    if (words[W] == "{")
                                        brackets++;
                                    if (words[W] == "}")
                                        brackets--;
                                }
                            }
                        }
                    }
                }
                else if (words[W] == "&")
                {
                    W++;
                    float meaning;
                    float meaning2;
                    string sign;
                    for (int i = 0; i < links_names.size(); i++)
                    {
                        if (links_names[i] == words[W])
                        {
                            meaning = fastMemory[links[i]];
                            break;
                        }
                    }
                    W++;
                    sign = words[W];
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            if (words[W] == "mem")
                            {
                                W++;
                                if (words[W] == ":")
                                {
                                    W++;
                                    meaning2 = fastMemory[(int)fastMemory[stoi(words[W])]];
                                }
                            }
                            else if (words[W] == "&")
                            {
                                W++;
                                for (int i = 0; i < links_names.size(); i++)
                                {
                                    if (links_names[i] == words[W])
                                    {
                                        meaning2 = fastMemory[(int)fastMemory[links[i]]];
                                        break;
                                    }
                                }
                            }
                            else 
                                meaning2 = fastMemory[stof(words[W])];
                        }
                    }
                    else if (words[W] == "&")
                    {
                        W++;
                        for (int i = 0; i < links_names.size(); i++)
                        {
                            if (links_names[i] == words[W])
                            {
                                meaning2 = fastMemory[links[i]];
                                break;
                            }
                        }
                    }
                    else
                        meaning2 = stof(words[W]);
                    W++;
                    if (sign == "==")
                    {
                        if (meaning == meaning2)
                        {
                            W += 1;
                        }
                        else
                        {
                            int brackets = 1;
                            W += 1;
                            while (brackets != 0)
                            {
                                W++;
                                if (words[W] == "{")
                                    brackets++;
                                if (words[W] == "}")
                                    brackets--;
                            }
                        }
                    }
                    if (sign == ">")
                    {
                        if (meaning > meaning2)
                        {
                            W += 1;
                        }
                        else
                        {
                            int brackets = 1;
                            W += 1;
                            while (brackets != 0)
                            {
                                W++;
                                if (words[W] == "{")
                                    brackets++;
                                if (words[W] == "}")
                                    brackets--;
                            }
                        }
                    }
                    if (sign == "<")
                    {
                        if (meaning < meaning2)
                        {
                            W += 1;
                        }
                        else
                        {
                            int brackets = 1;
                            W += 1;
                            while (brackets != 0)
                            {
                                W++;
                                if (words[W] == "{")
                                    brackets++;
                                if (words[W] == "}")
                                    brackets--;
                            }
                        }
                    }
                    if (sign == ">=")
                    {
                        if (meaning >= meaning2)
                        {
                            W += 1;
                        }
                        else
                        {
                            int brackets = 1;
                            W += 1;
                            while (brackets != 0)
                            {
                                W++;
                                if (words[W] == "{")
                                    brackets++;
                                if (words[W] == "}")
                                    brackets--;
                            }
                        }
                    }
                    if (sign == "<=")
                    {
                        if (meaning <= meaning2)
                        {
                            W += 1;
                        }
                        else
                        {
                            int brackets = 1;
                            W += 1;
                            while (brackets != 0)
                            {
                                W++;
                                if (words[W] == "{")
                                    brackets++;
                                if (words[W] == "}")
                                    brackets--;
                            }
                        }
                    }
                    if (sign == "!=")
                    {
                        if (meaning != meaning2)
                        {
                            W += 1;
                        }
                        else
                        {
                            int brackets = 1;
                            W += 1;
                            while (brackets != 0)
                            {
                                W++;
                                if (words[W] == "{")
                                    brackets++;
                                if (words[W] == "}")
                                    brackets--;
                            }
                        }
                    }
                }
            }

            // while loop
            if (words[W] == "move")
            {
                W++;
                if (words[W] == "mem")
                {
                	W++;
                    if (words[W] == ":")
                    {
                        W++;
                        W = (int)fastMemory[stoi(words[W])];
                    }
                }
                else if (words[W] == "&")
                {
                    W++;
                    for (int i = 0; i < links_names.size(); i++)
                    {
                        if (links_names[i] == words[W])
                        {
                            W = (int)fastMemory[links[i]];
                            break;
                        }
                    }
                }
                else if (words[W] == "ID")
                {
                	W++;
                	string id = words[W];
                	W--;
                	while (words[W] != id)
                		W--;
                }
                else 
                {
                	W = stoi(words[W]);
                }
            }

            if (words[W] == "print")
            {
                W++; W++;   
                while (words[W] != ")")
                {
                    if (words[W] != "<")
                    {
                        if (words[W] != "\\n" && words[W] != "\\s")
                        {
                            if (words[W] != ">")
                                cout << words[W] << " ";
                        }
                        else 
                            cout << endl;
                        if (words[W] == "\\s")
                            cout << " ";
                        W++;
                    }
                    else
                    {
                        W++;
                        if (words[W] == "mem" && words[W + 1] == ":")
                        {
                            W += 2;
                            if (words[W] == "~")
                            {
                                W++;
                                if (words[W] == "mem")
                                {
                                    W++;
                                    if (words[W] == ":")
                                    {
                                        W++;
                                        cout << letters[(int)fastMemory[(int)fastMemory[stoi(words[W])]]];
                                    }
                                }
                                else 
                                {
                                    cout << letters[(int)fastMemory[stoi(words[W])]];
                                }
                            }
                            else
                            {
                                if (words[W] == "mem")
                                {
                                    W++;
                                    if (words[W] == ":")
                                    {
                                        W++;
                                        cout << fastMemory[(int)fastMemory[stoi(words[W])]];
                                    }
                                }
                                else 
                                {
                                    cout << fastMemory[stoi(words[W])];
                                }
                            }
                        }
                        else if (words[W] == "~")
                        {
                            W++;
                            if (words[W] == "&")
                            {
                                W++;
                                for (int i = 0; i < links_names.size(); i++)
                                {
                                    if (links_names[i] == words[W])
                                        cout << letters[(int)fastMemory[(int)links[i]]];
                                }
                            }
                            W++;
                        }
                        else if (words[W] == "&")
                        {
                            W++;
                            for (int i = 0; i < links_names.size(); i++)
                            {
                                if (links_names[i] == words[W])
                                    cout << fastMemory[(int)links[i]];
                            }
                            W++;
                        }
                    }
                }
            }

            // links
            if (words[W] == "&")
            {
                W++;
                links_names.push_back(words[W]);
                W++;
                if (words[W] == "=")
                {
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            if (words[W] == "mem")
                            {
                                W++;
                                if (words[W] == ":")
                                {
                                    links.push_back((int)fastMemory[stoi(words[W])]);
                                }
                            }
                            else
                                links.push_back(stoi(words[W]));
                        }
                    }
                }
            }

            if (words[W] == "printW")
                cout << W << endl;

            // stack
            if (words[W] == "push")
            {
                W++;
                if (words[W] == "mem")
                {
                    W++;
                    if (words[W] == ":")
                    {
                        W++;
                        if (words[W] == "mem")
                        {
                            W++;
                            if (words[W] == ":")
                            {
                                stack.push_back(fastMemory[(int)fastMemory[stoi(words[W])]]);
                            }
                        }
                        else
                            stack.push_back(fastMemory[stoi(words[W])]);
                    }
                }
                else if (words[W] == "&")
                {
                    W++;
                    for (int i = 0; i < links_names.size(); i++)
                    {
                        if (links_names[i] == words[W])
                        {
                            stack.push_back(fastMemory[links[i]]);
                            break;
                        }
                    }
                }
                else
                    stack.push_back(stoi(words[W]));
            }
            if (words[W] == "pop")
            {
                W++;
                if (words[W] == "mem")
                {
                    W++;
                    if (words[W] == ":")
                    {
                        W++;
                        if (words[W] == "mem")
                        {
                            W++;
                            if (words[W] == ":")
                            {
                                W++;
                                fastMemory[(int)fastMemory[stoi(words[W])]] = stack[stack.size() - 1];
                            }
                        }
                        else
                            fastMemory[stoi(words[W])] = stack[stack.size() - 1];
                        stack.pop_back();
                    }
                }
            }

            // system
            if (words[W] == "sys.cls")
            {
                cout << "\033c";
            }

            if (words[W] == "mem")
            {
                W++;
                if (words[W] == ":=")
                {
                    W++;
                    int place;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                        place = stoi(words[W]);
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            if (words[W] == "mem")
                            {
                                W++;
                                if (words[W] == ":")
                                {
                                    W++;
                                    while (place > fastMemory.size() - 1)
                                        fastMemory.push_back(0.0f);
                                    fastMemory[place] = fastMemory[(int)fastMemory[stoi(words[W])]];
                                }
                            }
                            else
                            {
                                while (place > fastMemory.size() - 1)
                                    fastMemory.push_back(0.0f);
                                fastMemory[place] = fastMemory[stoi(words[W])];
                            }
                        }
                    }
                    else
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        fastMemory[place] = stof(words[W]);
                    }
                }
                if (words[W] == ":+")
                {
                    W++;
                    int place;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                        place = stoi(words[W]);
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            while (place > fastMemory.size() - 1)
                                fastMemory.push_back(0.0f);
                            fastMemory[place] += fastMemory[stoi(words[W])];
                        }
                    }
                    else
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        fastMemory[place] += stof(words[W]);
                    }
                }
                if (words[W] == ":-")
                {
                    W++;
                    int place;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                        place = stoi(words[W]);
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            while (place > fastMemory.size() - 1)
                                fastMemory.push_back(0.0f);
                            fastMemory[place] -= fastMemory[stoi(words[W])];
                        }
                    }
                    else
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        fastMemory[place] -= stof(words[W]);
                    }
                }
                if (words[W] == ":*")
                {
                    W++;
                    int place;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                        place = stoi(words[W]);
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            while (place > fastMemory.size() - 1)
                                fastMemory.push_back(0.0f);
                            fastMemory[place] *= fastMemory[stoi(words[W])];
                        }
                    }
                    else
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        fastMemory[place] *= stof(words[W]);
                    }
                }
                if (words[W] == ":/")
                {
                    W++;
                    int place;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                        place = stoi(words[W]);
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            while (place > fastMemory.size() - 1)
                                fastMemory.push_back(0.0f);
                            fastMemory[place] /= fastMemory[stoi(words[W])];
                        }
                    }
                    else
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        fastMemory[place] /= stof(words[W]);
                    }
                }
                if (words[W] == ":%")
                {
                    W++;
                    int place;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                        place = stoi(words[W]);
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            while (place > fastMemory.size() - 1)
                                fastMemory.push_back(0.0f);
                            fastMemory[place] = (int)fastMemory[place] % (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        fastMemory[place] = (int)fastMemory[place] % (int)stof(words[W]);
                    }
                }
                if (words[W] == ":sqrt")
                {
                    W++;
                    int place;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    else
                        place = stoi(words[W]);
                    W++;
                    if (words[W] == "mem")
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            while (place > fastMemory.size() - 1)
                                fastMemory.push_back(0.0f);
                            fastMemory[place] = sqrt(fastMemory[stoi(words[W])]);
                        }
                    }
                    else
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        fastMemory[place] = sqrt(stof(words[W]));
                    }
                }

                if (words[W] == "<<")
                {
                    W++;
                    int place;
                    if (words[W] != "mem") 
                        place = stoi(words[W]);
                    else 
                    {
                        W++;
                        if (words[W] == ":")
                        {
                            W++;
                            place = (int)fastMemory[stoi(words[W])];
                        }
                    }
                    if (place > fastMemory.size() - 1)
                    {
                        while (place > fastMemory.size() - 1)
                            fastMemory.push_back(0.0f);
                        W++;
                        if (words[W] == "num")
                        {
                            float in;
                            cin >> in;
                            fastMemory[place] = in;
                        }
                        else if (words[W] == "char")
                        {
                            char in;
                            cin >> in;
                            for (int i = 0; i < letters.size(); i++)
                            {
                                if (letters[i] == in)
                                {
                                    fastMemory[place] = i;
                                    break;
                                }
                            }
                        }
                    }
                    else 
                    {
                        W++;
                        if (words[W] == "num")
                        {
                            float in;
                            cin >> in;
                            fastMemory[place] = in;
                        }
                        else
                        {
                            char in;
                            cin >> in;
                            for (int i = 0; i < letters.size(); i++)
                            {
                                if (letters[i] == in)
                                {
                                    fastMemory[place] = i;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << endl;
        for (auto el : fastMemory)
        {
            cout << "|" << el << "|";
        }
    }
}