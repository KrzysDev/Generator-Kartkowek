#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

 vector<string> irregularVerbs = {
    "sein",       // być
    "haben",      // mieć
    "werden",     // stawać się
    "gehen",      // iść
    "kommen",     // przychodzić
    "nehmen",     // brać
    "sehen",      // widzieć
    "geben",      // dawać
    "finden",     // znajdować
    "bleiben",    // zostawać
    "fahren",     // jechać
    "essen",      // jeść
    "lesen",      // czytać
    "schlafen",   // spać
    "laufen",     // biegać
    "tragen",     // nosić
    "sprechen",   // mówić
    "treffen",    // spotykać
    "vergessen",  // zapominać
    "beginnen",   // zaczynać
    "bitten",     // prosić
    "halten",     // trzymać
    "lassen",     // pozwalać
    "laufen",     // biegać
    "rufen",      // wołać
    "schwimmen",  // pływać
    "singen",     // śpiewać
    "springen",   // skakać
    "steigen",    // wspinać się
    "sterben",    // umierać
    "tragen",     // nosić
    "treten",     // kopać
    "vergessen",  // zapominać
    "verlieren",  // tracić
    "waschen",    // myć
    "ziehen",     // ciągnąć
    "backen",     // piec
    "befehlen",   // rozkazywać
    "beginnen",   // zaczynać
    "beißen",     // gryźć
    "binden",     // wiązać
    "blasen",     // dmuchać
    "brechen",    // łamać
    "empfehlen",  // polecać
    "fangen",     // łapać
    "fliegen",    // latać
    "gießen",     // podlewać
    "graben",     // kopać
    "halten",     // trzymać
    "heben",      // podnosić
    "klingen",    // brzmieć
    "laden",      // ładować, zapraszać
    "lassen",     // pozwalać
    "laufen",     // biegać
    "leiden",     // cierpieć
    "leihen",     // pożyczać
    "lesen",      // czytać
    "liegen",     // leżeć
    "messen",     // mierzyć
    "nehmen",     // brać
    "nennen",     // nazywać
    "reiten",     // jeździć konno
    "rufen",      // wołać
    "scheiden",   // rozdzielać, rozwodzić się
    "scheinen",   // świecić, wydawać się
    "schieben",   // pchać
    "schießen",   // strzelać
    "schlafen",   // spać
    "schlagen",   // bić
    "schließen",  // zamykać
    "schneiden",  // ciąć
    "schreiben",  // pisać
    "schreien",   // krzyczeć
    "schwimmen",  // pływać
    "sehen",      // widzieć
    "sein",       // być
    "singen",     // śpiewać
    "sitzen",     // siedzieć
    "sprechen",   // mówić
    "springen",   // skakać
    "stehen",     // stać
    "stehlen",    // kraść
    "steigen",    // wspinać się
    "sterben",    // umierać
    "tragen",     // nosić
    "treffen",    // spotykać
    "treiben",    // pędzić
    "treten",     // kopać
    "trinken",    // pić
    "tun",        // robić
    "vergessen",  // zapominać
    "verlieren",  // tracić
    "waschen",    // myć
    "werden",     // stawać się
    "werfen",     // rzucać
    "ziehen",     // ciągnąć
    "zwingen"     // zmuszać
};

void CreateFile(string fileName) {
    ofstream file(fileName);
}

void WriteToRTF(const std::string& fileName, unordered_set<string>& v) {
   ofstream file(fileName);

    file << "{\\rtf1\\ansi\\deff0\n";
    file << "{\\fonttbl{\\f0 Arial;}}\n";
    file << "\\f0\\fs24\n";

    file << "Imie ___________ Nazwisko _________ Klasa ____ Data ______ Pkt ____ / 10" << "\\par\n";
    file << "Zadanie: " << "\\par\n";
    file << "Odmien podane czasowniki w czasach kolejno: Prasens, Prateritum i Perfekt" << "\\par\n";

    for (const auto& element : v) {
        file << element << "\\par\n";
    }

    file << "}\n";
    file.close();
}

void GenerateGroup(string fileName, char groupName) {
    CreateFile(fileName + "grupa " + groupName + ".rtf");
    
    int randomIndex = 0;
    int previousIndex = -1;

    unordered_set<string> verbs;

    for (int i = 0; i < 10; i++) {
        do
        {
            randomIndex = rand() % irregularVerbs.size();
        }
        while(randomIndex == previousIndex || verbs.find(irregularVerbs[randomIndex]) != verbs.end());
        
        verbs.insert(irregularVerbs[randomIndex]);
    }

    WriteToRTF(fileName + "grupa " + groupName + ".rtf", verbs);
}

void MakeAllGroups(string quizName, int count) {
    char groupName = 'A';
    for(int i = 0; i < count; i++) {
        GenerateGroup(quizName, groupName);
        groupName++;
    }
}

int main() {
    srand(time(NULL));

    string name;

    int groupsAmount;

    cout << "jak nazywa sie kartkowa?(np. czasowniki nieregularne)" << endl;

    getline(cin, name);

    cout << "ile ma byc grup? (np. 5 lub 10) (Uwaga! Wiecej niz 26 nie jest polecane, poniewaz nie ma wiecej liter (w alfabecie lacinskim) XD)" << endl;

    cin >> groupsAmount;

    cout<<"generuje kartkowki...." << endl;

    MakeAllGroups(name, groupsAmount);

    cout<<"zrobione!"<<endl;

    return 0;
}
