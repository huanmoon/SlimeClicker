#include <iostream>
#include <cstring>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string cmd;
int cps = 5;
int delay = 100;
bool is_renable = false;
int rcps = 2;
bool is_blockhit_enable = false;
int randomnum = 0;
int chance = 0;
int mincps = 0;
bool is_randomcps_enable = false;
int truecps = 0;

void Clicker();
void GUI();
int Load();

int Load() {
    ifstream infile;
    string file = "./config.txt";
    infile.open(file);
    if (infile.fail()) {
        cout << "config load failed!" << endl;
        /*Sleep(1000);
        cout << "exit in 2 seconds." << endl;
        Sleep(1000);
        cout << "exit in 1 seconds." << endl;
        Sleep(1000);*/
        return 1;
    }
    int reader;
    infile >> reader;
    cout << reader << endl;
    cps = reader;
    cout << "cps load succefully!" << endl;

    infile >> reader;
    cout << reader << endl;
    delay = reader;
    cout << "click delay load succefully!" << endl;

    infile >> reader;
    cout << reader << endl;
    is_renable = reader;
    cout << "is_right_click_enable load succefully!" << endl;

    infile >> reader;
    cout << reader << endl;
    rcps = reader;
    cout << "rightclick cps load succefully!" << endl;

    infile >> reader;
    cout << reader << endl;
    is_blockhit_enable = reader;
    cout << "is_blockhit_enable load succefully!" << endl;

    infile >> reader;
    cout << reader << endl;
    chance = reader;
    cout << "blockhit chance load succefully!" << endl;

    infile >> reader;
    cout << reader << endl;
    is_randomcps_enable = reader;
    cout << "is_randomcps_enable load succefully!" << endl;
    
    infile >> reader;
    cout << reader << endl;
    mincps = reader;
    cout << "mincps load succefully!" << endl;

    infile.close();
}

void Clicker() {
    POINT cursorPos;
    int x;
    int y;
    bool is_enable = false;
    while (1) {
        GetCursorPos(&cursorPos);
        x = cursorPos.x;
        y = cursorPos.y;
        if (is_enable) {
            if (is_randomcps_enable == true) {
                truecps = rand() % cps-mincps+1;
            }
            else {
                truecps = cps;
            }
            for (int i = 0; i <= truecps; i++) {
                mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
                if (is_blockhit_enable == true) {
                    //blockhit
                    randomnum = rand() % 101;
                    if (randomnum <= chance) {
                        mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
                        mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
                    }
                }
                Sleep(delay);
            }
        }
        if (GetKeyState(VK_LBUTTON) & 0x800) {
            is_enable = true;
            cout << "clicker enable" << endl;
        }
        else {
            is_enable = false;
            cout << "clicker disable" << endl;
        }

        if(GetKeyState(VK_RBUTTON) & 0x800 && is_renable){
            for (int i = 0; i <= rcps; i++) {
                mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
                mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
                Sleep(delay);
            }
        }

        if (GetKeyState(VK_CONTROL) & 0x800) {
            cout << "clicking stop!" << endl;
            system("cls");
            GUI();
        }

        if (GetKeyState(VK_MBUTTON) & 0x800){
            while (1) {
                cout << "clicking pause!" << endl;
                if (GetKeyState(VK_CONTROL) & 0x800) {
                    system("cls");
                    GUI();
                }
                if (GetKeyState(VK_SHIFT) & 0x800) {
                    cout << "clicking countinue!" << endl;
                    break;
                }
            }
        }
    }
}

void GUI() {
    cout << "SlimeClickerV0.7" << endl;
    cout << "Thx for using SlimeClicker!"<<endl;
    cout << "This is just beta version,so there r a lot of bugs and problems." << endl;
    cout << "Enter 'help' to get help if u don't know how to use SlimeClicker." << endl;
    while (1) {
        cin >> cmd;
        if (cmd == "genshin") {
            cout << "wochao,yuan!";
        }
        else if (cmd == "help") {
            cout << "U can use these commands in V0.7:" << endl;
            cout << "settings:to set SlimeClicker" << endl;
            cout << "save:to save ur config" << endl;
            cout << "load:to load ur config" << endl;
            cout << "start:to start clicking(when u r clicking use MBUTTON,u can use SHIFT to continue and use CONTROL to stop clicking)" << endl;
            cout << "about:to c the information about SlimeClicker" << endl;
            cout << "exit:to exit SlimeClicker" << endl;
            //cout << "blockhit:to enable the blockhit feature" << endl;
        }
        else if (cmd == "settings" || cmd == "setting") {
            cout << "enter ur cps:" << endl;
            cin >> cps;
            cout << "do u want to enable random cps?(Y/N)" << endl;
            cin >> cmd;
            if (cmd == "Y" || cmd == "y") {
                cout << "enter ur mincps:" << endl;
                cin >> mincps;
                if (mincps > cps) {
                    cout << "error:ur mincps can't > ur cps" << endl;
                    is_randomcps_enable = false;
                }
                else {
                    is_randomcps_enable = true;
                }
            }
            else {
                is_randomcps_enable = false;
            }
            cout << "enter click delay(ms):" << endl;
            cin >> delay;
            cout << "do u want to use right click?(Y/N)" << endl;
            cin >> cmd;
            if (cmd == "Y" || cmd == "y") {
                is_renable = true;
                cout << "enter ur right click cps:" << endl;
                cin >> rcps;
            }
            else {
                is_renable = false;
            }
            cout << "do u want to enable the blockhit feature?(Y/N)" << endl;
            cin >> cmd;
            if (cmd == "Y" || cmd == "y") {
                is_blockhit_enable = true;
                cout << "blockhit chance?(%):" << endl;
                cin >> chance;
                cout << "blockhit enbale!" << endl;
            }
            else {
                is_blockhit_enable = false;
            }
            cout << "set succefully!" << endl;
        }
        else if (cmd == "about") {
            cout << "SlimeClicker is an autoclicker that made by huanmoon007(his bilibili:https://space.bilibili.com/515396318)." << endl;
        }
        else if (cmd == "exit") {
            cout << "r u sure to exit?(Y/N)=(" << endl;
            cin >> cmd;
            if (cmd == "Y" || cmd == "y") {
                cout << "OK,cya!" << endl;
                exit(0);
            }
        }
        else if (cmd == "click" || cmd == "start") {
            Clicker();
        }
        else if (cmd == "save") {
            ofstream outfile;
            string file = "./config.txt";
            outfile.open(file, ios::trunc | ios::out);
            outfile << cps << endl << delay << endl << is_renable << endl << rcps << endl << is_blockhit_enable <<endl << chance << endl <<is_randomcps_enable << endl << mincps << endl;
            outfile.close();
            cout << "config save succefully!" << endl;
        }
        else if (cmd == "load") {
            Load();
        }
        else {
            cout << "Command error!" << endl;
        }
    }
}

int main(){
    srand(time(0));
    GUI();

    return 0;
}