#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using std::string;
using std::vector;
using std::cin;
using std::unordered_map;
struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    unordered_map<int,string> map; 
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            map[queries[i].number] = queries[i].name;
        } else if (queries[i].type == "del") {
            if(map.find(queries[i].number)!=map.end())
                map.erase(map.find(queries[i].number));
        } else {
            if(map.find(queries[i].number)!=map.end())
            {
                result.push_back(map[queries[i].number]);
            }
            else
            {
                result.push_back("not found");
            }
            
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
