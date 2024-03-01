#pragma once
#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <fstream>
#include <iostream> // For cout
#include <sstream>  // For stringstream
#include <vector>
#include <string>

using namespace std;

// Function to load data from the CSV file into memory
vector<vector<string>> loadCSV(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open " << filename << endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}
#endif // FILE_HANDLING_H
// void saveCSV(string filename,  vector<vector<string>> data) {
//     cout << "Saving data to " << filename << endl;
//     ofstream file(filename);
//     for (const auto& row : data) {
//         for (const auto& field : row) {
//             file << field << ",";
//         }
//         file << "\n";
//     }
//     file.close();
// }
string vectorToStringWithSpaces(const vector<string>& vec) {
    stringstream ss;
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i != vec.size() - 1) {
            ss << " "; // Add space after every element except the last one
        }
    }
    return ss.str();
}

void saveCSV(string filename,  vector<vector<string>> data) {
    cout << "Saving data to " << filename << endl;
    ofstream file(filename);
    for (const auto& row : data) {
        for (const auto& field : row) {
            file << field << ",";
        }
        file << "\n";
    }
    file.close();
}
string deleteWord(const string& mainWord, const string& wordToDelete) {
    // Create a stringstream to split the main word into words
    stringstream ss(mainWord);
    string word;
    string modifiedWord;

    // Iterate through each word in the main word
    while (ss >> word) {
        // If the word is not the word to delete, add it to the modified word
        if (word != wordToDelete) {
            modifiedWord += word + " ";
        }
    }

    // Remove trailing space if any
    if (!modifiedWord.empty()) {
        modifiedWord.pop_back();
    }

    return modifiedWord;
}