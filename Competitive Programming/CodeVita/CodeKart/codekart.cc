#include <bits/stdc++.h>
using namespace std;

bool isNumber(string &input) {
    for(int i = 0; i < input.length(); i++) {
        if(isdigit(input[i] == false)) {
            return false;
        }
    }
    return true;
}

bool isValid(string &input) {
    if(input == "SHIRT" || input == "SHOE")
        return true;
    return false;
}

bool isFloat(string &input) {
    try {
        float val = stof(input);
        return true;
    }
    catch (exception &e) {
        return false;
    }
}

void solve() {
    map<string, int> inventory, cart;
    map<string float> price;

    while(1) {
        string input;
        getline(cin, input);
        while(input.length() == 0) {
            getline(cin, input);
        }
        //  first command is END
        if(input == "END")
            break;
        stringstream ss(input);
        vector<string> cmd;
        string temp;
        while(ss >> temp)
            cmd.push_back(temp);
        //  Total size of the given input is less than 3. Atleast for minimum command it is CMD S/SM REMOVE ITEM_NAME which is 4
        if(cmd.size() < 3){
            cout << -1 << "\n";
            continue;
        }
        //  If the command does not begin with CMD
        if(cmd[0] != "CMD") {
            cout << -1 << "\n";
            continue;
        }
        //  If after the CMD command it does not have S or SM
        if(cmd[1] != "S" || cmd[1] != "SM") {
            cout << -1 << "\n";
            continue;
        }
        //  If after CMD and S/SM there is ADD
        if(cmd[2] == "ADD") {
            //  If the total size of the ADD is less 5 words i.e., CMD S/SM ADD NAME AMT which is 5
            if(cmd.size() < 5) {
                cout << -1 << "\n";
                continue;
            }
            //  If the 4th word is not a number or the 3rd word is not a SHIRT or SHOE
            if(!isNumber(cmd[4]) || !isValid(cmd[3])) {
                cout << -1 << "\n";
                continue;
            }
            int amt = stoi(cmd[4]);
            //  If the amount is less than 0
            if(amt <= 0) {
                cout << -1 << "\n";
                continue;
            }
            //  For the SM part
            if(cmd[1] == "SM") {
                //  if the NAME of item is 
                if(inventory.find(cmd[3]) == inventory.end()) {
                    inventory[cmd[3]] = amt;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    cin >> t;
    while(t--) {
        solve();
    }
}
