#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include <utility>
#include "data.h"
#include "approximation.h"
namespace fs = std::filesystem;
using namespace std;

/**
 * @brief Allows user to go back to select a fileset and invokes functions to extract data from the files.
 *
 * This function provides an interface for the user to select a fileset from the available ones, interprets the choice and invokes the functions to read and extract data from the files.
 *
 * @return pair<pair<vector<int>,vector<int>>,int> Pair containing a pair containing vectors with the profits and the weights of the pallets in the file and the truck´s weight capacity.
 * @note Time Complexity: O(n), where n is the number of pallets in the respective file.
 * @note Space Complexity: O(n), where n is the number of pallets in the respective file.
 */
pair<pair<vector<int>,vector<int>>,int> dataSets()
{
    pair<vector<int>,vector<int>> palletData;
    int truckCapacity;
    vector<string> availableFiles;
    string path = SOURCE_DIR;
    map<string, pair<string, string>> fileGroups;
    regex pattern(R"((Pallets|TruckAndPallets)_(\d+)\.csv)");
    smatch match;
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
                    fileGroups[suffix].first = filename;
                else if (prefix == "TruckAndPallets")
                    fileGroups[suffix].second = filename;
            }
        }
    }
    vector<string> matchedKeys;
    for (const auto& [key, files] : fileGroups)
    {
        if (!files.first.empty() && !files.second.empty())
            matchedKeys.push_back(key);
    }
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
    while (true)
    {
        int option = 0;
        cout << "WRITE THE NUMBER OF THE DESIRED FILE PAIR: ";
        cin >> option;

        if (option == static_cast<int>(availableFilesSize) + 1)
        {
            cout << "THANKS FOR YOUR VISIT\n";
            exit(0);
        }
        else if (option < 1 || option > static_cast<int>(availableFilesSize))
        {
            cout << "WRITE AN EXISTING FILE PAIR'S NUMBER\n";
        }
        else
        {
            const auto& files = fileGroups[matchedKeys[option - 1]];
            cout << "GONNA PROCESS FILES: " << files.first << " AND " << files.second << endl;
            palletData = extractPalletValues(string(SOURCE_DIR) + "/"+files.first);
            truckCapacity = extractTruckCapacity(string(SOURCE_DIR) + "/"+files.second);
            break;
        }
    }
    return make_pair(palletData, truckCapacity);
}

/**
 * @brief Shows to the user his options when starting the program and interprets the choice.
 *
 * This function provides an interface for the user to select a data file or exit the program, when starting it.
 *
 * @note Time Complexity: O(n), where n is the number of pallets (derived from data extraction functions).
 * @note Space Complexity: O(n), where n is the number of pallets (derived from data extraction functions).
 */
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

/**
 * @brief Allows user to go back to file selection menu after executing an algorithmic approach.
 *
 * This function provides an interface for the user to go back to selecting a file set and an algorithmic approach, after already performing one.
 *
 * @note Time Complexity: O(n), due to functions invoked from algorithmic approaches.
 * @note Space Complexity: O(n), due to functions invoked from algorithmic approaches.
 */
void goBack();

/**
 * @brief Allows user to go back to choose an algorithmic option to solve the problem.
 *
 * This function provides an interface (menu) for the user to select an approach to find the solution for the problem.
 *
 * @note Time Complexity: O(n log n), due to functions invoked from algorithmic approaches.
 * @note Space Complexity: O(n), due to functions invoked from algorithmic approaches.
 */
void displayAlgorithmicOptions(const pair<pair<vector<int>,vector<int>>,int>& values)
{
    cout<<"\n--- ALGORITHMIC FUNCTIONS ---\n";
    cout<<"1. BRUTE-FORCE APPROACH\n";
    cout<<"2. DYNAMIC PROGRAMMING APPROACH\n";
    cout<<"3. APPROXIMATION(GREEDY) APPROACH\n";
    cout<<"4. INTEGER LINEAR PROGRAMMING APPROACH\n";
    cout<<"5. GO BACK TO FILE SELECTION\n";
    cout<<"6. EXIT\n";
    while (true)
    {
        int algorithmicOption=0;
        cout<<"WRITE THE NUMBER OF THE DESIRED OPTION: ";
        cin>>algorithmicOption;
        switch (algorithmicOption)
        {
        case 1:
            {
                bruteForce(values.first.second, values.first.first, values.second);
                goBack();
            }
        case 2:
            {
                mainApprox(values.first.second, values.first.first, values.second);
                goBack();
            }
        case 3:
            {
                mainApprox(values.first.second, values.first.first, values.second);
                goBack();
            }
        case 4:
            break;
        case 5:
            {
                auto newValues = dataSets();
                displayAlgorithmicOptions(newValues);
            }
        case 6:
            cout<<"THANKS FOR YOUR VISIT\n";
            exit(0);
        default:
            cout<<"INVALID OPTION\n";
        }
    }
}

/**
 * @brief Allows user to go back to file selection menu after executing an algorithmic approach.
 *
 * This function provides an interface for the user to go back to selecting a file set and an algorithmic approach, after already performing one.
 *
 * @note Time Complexity: O(n), due to functions invoked from algorithmic approaches.
 * @note Space Complexity: O(n), due to functions invoked from algorithmic approaches.
 */
void goBack()
{
    string yes_no;
    cout<<"\nPROCESS ANOTHER FILE?(Y/n): ";
    cin>>yes_no;
    if (yes_no == "Y" || yes_no=="y")
    {
        auto newValues = dataSets();
        if (!newValues.first.first.empty())
        {
            displayAlgorithmicOptions(newValues);
        }
    }
    else if (yes_no=="N" || yes_no=="n")
    {
        exit(0);
    }
}

int main() {
    pair<pair<vector<int>,vector<int>>,int> values=menu();
    if (!values.first.first.empty()){
        displayAlgorithmicOptions(values);
    }
    return 0;
}
