#include <iostream>
#include <fstream>
#include <vector>
#include<math.h>
#include <fstream>
#include <map>
#include <sstream>
#include <windows.h>
#include "rlutil.h"
#include <conio.h>
using namespace std;
void ClearScreen(int x, int y)
{
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
unsigned long long int hexToDec(char hexa)
{
    unsigned long long int dec = 0;
    switch (hexa)
    {
    case '0':
        dec = 0;
        break;
    case '1':
        dec = 1;
        break;
    case '2':
        dec = 2;
        break;
    case '3':
        dec = 3;
        break;
    case '4':
        dec = 4;
        break;
    case '5':
        dec = 5;
        break;
    case '6':
        dec = 6;
        break;
    case '7':
        dec = 7;
        break;
    case '8':
        dec = 8;
        break;
    case '9':
        dec = 9;
        break;
    case 'A':
        dec = 10;
        break;
    case 'B':
        dec = 11;
        break;
    case 'C':
        dec = 12;
        break;
    case 'D':
        dec = 13;
        break;
    case 'E':
        dec = 14;
        break;
    case 'F':
        dec = 15;
        break;
    }
    return dec;
}
string convertToBinaryFromHexa(string hexa) {
    int i = 0;
    string ats;
    while (hexa[i]) {
        switch (hexa[i]) {
        case '0':
            ats += "0000";
            break;
        case '1':
            ats += "0001";
            break;
        case '2':
            ats += "0010";
            break;
        case '3':
            ats += "0011";
            break;
        case '4':
            ats += "0100";
            break;
        case '5':
            ats += "0101";
            break;
        case '6':
            ats += "0110";
            break;
        case '7':
            ats += "0111";
            break;
        case '8':
            ats += "1000";
            break;
        case '9':
            ats += "1001";
            break;
        case 'A':
        case 'a':
            ats += "1010";
            break;
        case 'B':
        case 'b':
            ats += "1011";
            break;
        case 'C':
        case 'c':
            ats += "1100";
            break;
        case 'D':
        case 'd':
            ats += "1101";
            break;
        case 'E':
        case 'e':
            ats += "1110";
            break;
        case 'F':
        case 'f':
            ats += "1111";
            break;
        default:
            ats += "";
        }
        i++;

    }
    return ats;
}
string UTF8(string dvejetaine)
{
    string bitai[4];
    int bituSkaicius = 0;
    for (int i = 0; i < 4; i++) {
        bitai[i] = "";
    }
    if (dvejetaine.length() < 8) {
        while (dvejetaine.length() <= 7) {
            dvejetaine.insert(0, "0");
        }
        dvejetaine.insert(0, "0");
        bituSkaicius = 1;
    }

    else if (dvejetaine.length() < 12) {
        bitai[0].append("110");
        bitai[1].append("10");
        int i = 0;
        while (dvejetaine.length() < 11) {
            dvejetaine.insert(0, "0");
        }
        while (bitai[0].length() <= 7) {
            bitai[0].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[1].length() <= 7) {
            bitai[1].push_back(dvejetaine[i]);
            i++;
        }
        bituSkaicius = 2;
    }
    else if (dvejetaine.length() < 17) {
        bitai[0].append("1110");
        bitai[1].append("10");
        bitai[2].append("10");
        int i = 0;
        while (dvejetaine.length() < 16) {
            dvejetaine.insert(0, "0");
        }
        while (bitai[0].length() <= 7) {
            bitai[0].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[1].length() <= 7) {
            bitai[1].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[2].length() <= 7) {
            bitai[2].push_back(dvejetaine[i]);
            i++;
        }
        bituSkaicius = 3;
    }
    else {
        bitai[0].append("11110");
        bitai[1].append("10");
        bitai[2].append("10");
        bitai[3].append("10");
        int i = 0;
        while (dvejetaine.length() < 21) {
            dvejetaine.insert(0, "0");
        }
        while (bitai[0].length() <= 7) {
            bitai[0].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[1].length() <= 7) {
            bitai[1].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[2].length() <= 7) {
            bitai[2].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[3].length() <= 7) {
            bitai[3].push_back(dvejetaine[i]);
            i++;
        }
        bituSkaicius = 4;
    }
    string ats;
    ats.append(bitai[0]);
    ats.append(bitai[1]);
    ats.append(bitai[2]);
    ats.append(bitai[3]);
    // cout << ats << endl;
    return ats;
}
unsigned long long int binaryToDecimal(string binary) {
    unsigned long long int value = 0;
    int indexCounter = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {

        if (binary[i] == '1') {
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    return value;
}
string decimalToHexa(unsigned long long int number) {
    stringstream stream;
    stream << uppercase << hex << number;
    string atsakymas = stream.str();

    return atsakymas;
}
string tekstinisFailas() {
    char x;
    string cpReiksme;
    int indeksas;
    string sesioliktaine;
    ifstream intel("386intel.txt");
    ofstream ats("konvertuota.txt");
    ifstream cpLentele("CP437.txt");
    map <int, string>cp;
    while (!cpLentele.eof())
    {
        cpLentele >> cpReiksme >> indeksas;
        cp[indeksas] = cpReiksme;
    }
    int it = 0;
    while (intel.get(x))
    {
        int test = (x & 0xff);
        if ((test > 127 || (test < 31 && test > 1)) && test != 10)
        {


  string dvejetaine = convertToBinaryFromHexa(cp[test]);
   while (dvejetaine[0] == '0') {
   dvejetaine.erase(dvejetaine.begin());
      }
    dvejetaine = UTF8(dvejetaine);
    sesioliktaine = decimalToHexa(binaryToDecimal(dvejetaine));
    while (sesioliktaine.length() < 4)
        {
          sesioliktaine.insert(0, "0");
     }
  for (int i = 0; i < sesioliktaine.size(); i += 2) {
          int a = hexToDec(sesioliktaine[i]) * 16;
          int b = hexToDec(sesioliktaine[i + 1]);
   ats << (unsigned char)(a + b);
                
            }
        }
        else
        {
    ats << x;
        }


    }
    return "Darbas Pabaigtas";
}

void utf8Pirmam(string sesioliktaine) {
    ofstream xd("ats.txt");
    string dvejetaine = convertToBinaryFromHexa(sesioliktaine);
    string bitai[4];
    int bituSkaicius = 0;
    for (int i = 0; i < 4; i++) {
        bitai[i] = "";
    }
    if (dvejetaine.length() < 8) {
        while (dvejetaine.length() <= 7) {
            dvejetaine.insert(0, "0");
        }
        dvejetaine.insert(0, "0");
        bituSkaicius = 1;
    }

    else if (dvejetaine.length() < 12) {
        bitai[0].append("110");
        bitai[1].append("10");
        int i = 0;
        while (dvejetaine.length() < 11) {
            dvejetaine.insert(0, "0");
        }
        while (bitai[0].length() <= 7) {
            bitai[0].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[1].length() <= 7) {
            bitai[1].push_back(dvejetaine[i]);
            i++;
        }
        bituSkaicius = 2;
    }
    else if (dvejetaine.length() < 17) {
        bitai[0].append("1110");
        bitai[1].append("10");
        bitai[2].append("10");
        int i = 0;
        while (dvejetaine.length() < 16) {
            dvejetaine.insert(0, "0");
        }
        while (bitai[0].length() <= 7) {
            bitai[0].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[1].length() <= 7) {
            bitai[1].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[2].length() <= 7) {
            bitai[2].push_back(dvejetaine[i]);
            i++;
        }
        bituSkaicius = 3;
    }
    else {
        bitai[0].append("11110");
        bitai[1].append("10");
        bitai[2].append("10");
        bitai[3].append("10");
        int i = 0;
        while (dvejetaine.length() < 21) {
            dvejetaine.insert(0, "0");
        }
        while (bitai[0].length() <= 7) {
            bitai[0].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[1].length() <= 7) {
            bitai[1].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[2].length() <= 7) {
            bitai[2].push_back(dvejetaine[i]);
            i++;
        }
        while (bitai[3].length() <= 7) {
            bitai[3].push_back(dvejetaine[i]);
            i++;
        }
        bituSkaicius = 4;
    }

    int desimtaines[4] = { 0 };
    string sesioliktaines[4] = { "0" };
    for (int i = 0; i < bituSkaicius; i++) {
        desimtaines[i] = binaryToDecimal(bitai[i]);
        sesioliktaines[i] = decimalToHexa(desimtaines[i]);
    }
    string utf8Hexa = "UTF-8: ";

    unsigned char charoBitai[4] = { 0 };
    for (int i = 0; i < bituSkaicius; i++) {
        utf8Hexa.append(sesioliktaines[i]);
        charoBitai[i] = desimtaines[i];

    }
    cout << utf8Hexa << endl;
    cout << "Char: ";
    for (int i = 0; i < bituSkaicius; i++) {
        cout << charoBitai[i];
        xd << charoBitai[i];
    }
}

string Unikodas(string sesioliktainis) {
    while (sesioliktainis.size() < 4) {
        sesioliktainis.insert(0, "0");
    }
    return sesioliktainis;
}
string konvertavimas() {
    SetConsoleOutputCP(CP_UTF8);
    unsigned char a[4];
    int desimtainis;
    cout << "iveskite desimtaini skaiciu: ";
    cin >> desimtainis;
    cout << endl;
    stringstream stream;
    stream << uppercase << hex << desimtainis;
    string sesioliktainis = stream.str();
    cout << "Unicode: U+" << Unikodas(sesioliktainis) << endl;
    utf8Pirmam(sesioliktainis);
    cout << endl;
    return "darbas baigtas";
}
int main()
{
    rlutil::setColor(rlutil::GREEN);
    int dabartinis=0;
    char a;
    while (1) {
        ClearScreen(25, 7);
        rlutil::setColor(rlutil::GREEN);
        cout << "kuria uzduoti noresit atlikti? " << endl;
        
        ClearScreen(25, 12);
        if (dabartinis == 0) {
            rlutil::setColor(rlutil::RED);
        }
        else {
            rlutil::setColor(rlutil::GREEN);
        }
        cout << "desimtainio skaiciaus konvertavimas" << endl;
        ClearScreen(25, 13);
        if(dabartinis==1){
            rlutil::setColor(rlutil::RED);
        }
        else 
        rlutil::setColor(rlutil::GREEN);
        cout << "tekstinio failo konvertavimas" << endl;
        if (dabartinis == 2) {
            rlutil::setColor(rlutil::RED);
        }
        else 
            rlutil::setColor(rlutil::GREEN);
        ClearScreen(25, 14);
        cout << "iseiti is programos" << endl;
        a = _getch();
        if (a == 's') {
            if (dabartinis != 2) {
                dabartinis++;
            }
        }
        if (a == 'w') {
            if (dabartinis != 0) {
                dabartinis--;
            }
        }
        if (a == 'e') {
            if (dabartinis == 0) {
                rlutil::setColor(rlutil::GREY);
                system("cls");
                cout << konvertavimas() << endl;
                cout << "paspauskite betkoki mygtuka" << endl;
                getch();
                system("cls");
            }
            else if (dabartinis == 1) {
                rlutil::setColor(rlutil::GREY);
                system("cls");
                cout << tekstinisFailas() << endl;
                cout << "paspauskite betkoki mygtuka" << endl;
                getch();
                system("cls");
            }
            else if (dabartinis == 2) {
                rlutil::setColor(rlutil::GREEN);
                return 0;
            }
            else
            cout << "pradzia" << endl;
        }
  
    }
}

