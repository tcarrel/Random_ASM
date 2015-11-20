#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

struct command {
    string cmd;
    int arg_qty;
};

int main( int argc, char* argv[] )
{
    if( argc != 2 )
    {
        cerr << "Correct syntax: " << argv[0] << " (number)\n" <<
            "   (number) is the number of lines of code to generate.\n" << endl;
        return 1;
    }

    srand(time(NULL));

    vector<command> commands;

    commands.push_back({"NOP", 0});
    commands.push_back({"LDR", 3});
    commands.push_back({"STR", 3});
    commands.push_back({"ADDS", 3});
    commands.push_back({"SUBS", 3});
    commands.push_back({"ANDS", 2});
//    commands.push_back({"ASRS", 2});
//    commands.push_back({"BICS", 2});
    commands.push_back({"EORS", 2});
//    commands.push_back({"LSLS", 2});
//    commands.push_back({"LSRS", 2});
    commands.push_back({"MVNS", 2});
//    commands.push_back({"ORRS", 2});
//    commands.push_back({"RORS", 2});
    
    int lines = atoi(argv[1]);
    if( lines < 1 )
    {
        cerr << "Cannot inteperet number, should be greater than 0,\n" <<
            "  larger is better, but more than a few 100 is not recommended." << endl;
        return 1;
    }

    for( int i = 0; i < lines; i++ )
    {
        unsigned cmd = rand() % (commands.size() + 5);

        if( cmd >= commands.size() )
        {
            cmd = cmd % 4 + 1;
        }

        cout << commands[cmd].cmd << " ";
        int num_cmd = commands[cmd].arg_qty;
        for( int j = 1; j <= num_cmd; j++ )
        {
            unsigned reg = rand() % 3;
            string arg = "r";
            arg += ((char) reg + 0x30);

            if( (cmd == 1 || cmd == 2 ) && ( j == 2 ) )
                    cout << "[";

            unsigned is_imm = (rand() % 2);
            if( (cmd == 1 || cmd == 2) && j == 3 )
                is_imm = 1;
            if( ((1 <= cmd && cmd < 4) && (j == num_cmd) && is_imm) )
            {
                arg = "#";
                arg += (rand() % 100) % 2 ? "0" : "4";
            }
            cout << arg;

            if( j != num_cmd )
            {
                cout << ", ";
            }
            else
            {
                if( cmd == 1 || cmd == 2 )
                    cout << "]";
            }
        }
        cout << endl;
    }

    return 0;
}
