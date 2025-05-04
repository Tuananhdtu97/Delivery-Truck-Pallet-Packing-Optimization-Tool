#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include <utility>
#include "data.h"
namespace fs = std::filesystem;
using namespace std;

pair<pair<vector<int>,vector<int>>,int> dataSets()
{
    pair<vector<int>,vector<int>> palletData;
    int truckCapacity;
    vector<string> availableFiles;
    string path = SOURCE_DIR;
    map<string, pair<string, string>> fileGroups; // key: x, value: {file1, file2}

    regex pattern(R"((Pallets|TruckAndPallets)_(\d+)\.csv)");
    smatch match;

    // Scan directory for .csv files and group them by their number suffix
    for (const auto& entry : fs::directory_iterator(path))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".csv")
        {
            string filename = entry.path().filename().string();

            if (regex_match(filename, match, pattern))
            {
                string prefix = match[1].str();
                string suffix = match[2].str();

                if (prefix == "Pallets")
                    fileGroups[suffix].first = filename; // Store Pallets file
                else if (prefix == "TruckAndPallets")
                    fileGroups[suffix].second = filename; // Store TruckAndPallets file
            }
        }
    }

    // Prepare list of keys for matched pairs
    vector<string> matchedKeys;
    for (const auto& [key, files] : fileGroups)
    {
        if (!files.first.empty() && !files.second.empty())  // Only complete pairs
            matchedKeys.push_back(key);
    }

    // Display files or exit if no files are available
    size_t availableFilesSize = matchedKeys.size();
    if (availableFilesSize == 0)
    {
        cout << "NO AVAILABLE DATA FILES\n";
        return {};
    }

    cout << "\n--- AVAILABLE DATA FILE PAIRS ---\n";
    for (size_t i = 0; i < availableFilesSize; ++i)
    {
        const auto& files = fileGroups[matchedKeys[i]];
        cout << i + 1 << ". " << files.first << " + " << files.second << endl;
    }
    cout << availableFilesSize + 1 << ". EXIT\n";

    // Handle user input and selection
    while (true)
    {
        int option = 0;
        cout << "WRITE THE NUMBER OF THE DESIRED FILE PAIR: ";
        cin >> option;

        if (option == static_cast<int>(availableFilesSize) + 1)
        {
            cout << "THANKS FOR YOUR VISIT\n";
            exit(0);  // Exit program
        }
        else if (option < 1 || option > static_cast<int>(availableFilesSize))
        {
            cout << "WRITE AN EXISTING FILE PAIR'S NUMBER\n";
        }
        else
        {
            const auto& files = fileGroups[matchedKeys[option - 1]];
            cout << "GONNA PROCESS FILES: " << files.first << " AND " << files.second << endl;
            // Process files here (add your logic for file handling)
            palletData = extractPalletValues(string(SOURCE_DIR) + "/"+files.first);
            truckCapacity = extractTruckCapacity(string(SOURCE_DIR) + "/"+files.second);
            break;  // Exit loop after selection
        }
    }
    return make_pair(palletData, truckCapacity);
}

pair<pair<vector<int>,vector<int>>,int> menu()
{
        cout<<"\n--- MENU ---\n";
        cout<<"1. SELECT DATA FILE\n";
        cout<<"2. EXIT\n";
        while (true){
        int option=0;
        cout<<"WRITE THE NUMBER OF THE DESIRED OPTION: ";
        cin>>option;
        switch (option)
        {
        case 1:
            return dataSets();
        case 2:
            std::cout<<"THANKS FOR YOUR VISIT\n";
            exit(0);
        default:
            std::cout<<"INVALID OPTION\n";
        }
    }
}

void displayAlgorithmicOptions(const pair<pair<vector<int>,vector<int>>,int>& values)
{
    cout<<"\n--- ALGORITHMIC FUNCTIONS ---\n";
    cout<<"1. BRUTE-FORCE APPROACH\n";
    cout<<"2. DYNAMIC PROGRAMMING APPROACH\n";
    cout<<"3. APPROXIMATION(GREEDY) APPROACH\n";
    cout<<"4. INTEGER LINEAR PROGRAMMING APPROACH\n";
    cout<<"5. EXIT\n";
    while (true)
    {
        int option=0;
        cout<<"WRITE THE NUMBER OF THE DESIRED OPTION: ";
        cin>>option;
        switch (option)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            std::cout<<"THANKS FOR YOUR VISIT\n";
            exit(0);
        default:
            std::cout<<"INVALID OPTION\n";
        }
    }
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    pair<pair<vector<int>,vector<int>>,int> values=menu();
    if (!values.first.first.empty()){
        displayAlgorithmicOptions(values);
    }
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}