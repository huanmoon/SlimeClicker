#include <iostream>
#include <cstring>
#include <Windows.h>
#include <fstream>
using namespace std;

string cmd;
int cps = 5;
int delay = 100;
bool is_renable = false;
int rcps = 2;

void Clicker();
void GUI();

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
            for (int i = 0; i <= cps; i++) {
                mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
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
                if (GetKeyState(VK_SHIFT) & 0x800) {
                    cout << "clicking countinue!" << endl;
                    break;
                }
            }
        }
    }
}

void GUI() {
    cout << "SlimeClickerV0.5" << endl;
    cout << "Thx for using SlimeClicker!"<<endl;
    cout << "This is just beta version,so there r a lot of bugs and problems." << endl;
    cout << "Enter 'help' to get help if u don't know how to use SlimeClicker." << endl;
    while (1) {
        cin >> cmd;
        if (cmd == "genshin") {
            cout << "wochao,yuan!";
        }
        if (cmd == "help") {
            cout << "U can use these commands in V0.5:" << endl;
            cout << "settings:to set SlimeClicker" << endl;
            cout << "save:to save ur config" << endl;
            cout << "load:to load ur config" << endl;
            cout << "start:to start clicking(when u r clicking use MBUTTON,u can use SHIFT to continue and use CONTROL to stop clicking)" << endl;
            cout << "about:to c the information about SlimeClicker" << endl;
            cout << "exit:to exit SlimeClicker" << endl;
        }
        if (cmd == "settings") {
            cout << "enter ur cps:" << endl;
            cin >> cps;
            cout << "enter click delay(ms):" << endl;
            cin >> delay;
            cout << "if u want to use right click?(Y/N)" << endl;
            cin >> cmd;
            if (cmd == "Y") {
                is_renable = true;
                cout << "enter ur right click cps:" << endl;
                cin >> rcps;
            }
            else {
                is_renable = false;
            }
            cout << "set succefully!" << endl;
        }
        if (cmd == "about") {
            cout << "SlimeClicker is an autoclicker that made by huanmoon007(his bilibili:https://space.bilibili.com/515396318)." << endl;
        }
        if (cmd == "exit") {
            cout << "r u sure to exit?(Y/N)=(" << endl;
            cin >> cmd;
            if (cmd == "Y") {
                cout << "OK,cya!" << endl;
                exit(0);
            }
        }
        if (cmd == "click" || cmd == "start") {
            Clicker();
        }
        if (cmd == "save") {
            ofstream outfile;
            string file = "./config.txt";
            outfile.open(file, ios::trunc | ios::out);
            outfile << cps << endl << delay << endl << is_renable << endl << rcps << endl;
            outfile.close();
            cout << "save succefully!" << endl;
        }
        if (cmd == "load") {
            ifstream infile;
            string file = "./config.txt";
            infile.open(file);
            if (infile.fail()) {
                cout << "load failed!";
            }
            int reader;
            infile >> reader;
            cout << reader <<endl;
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

            infile.close();
        }
    }
}

int main(){
    GUI();

    return 0;
}