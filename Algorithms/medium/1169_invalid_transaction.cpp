/**
    1169. Invalid Transactions
A transaction is possibly invalid if:
- the amount exceeds $1000, or;
- if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.

Example 1:
Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.

Example 2:
Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]

Example 3:
Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]

Constraints:
transactions.length <= 1000
Each transactions[i] takes the form "{name},{time},{amount},{city}"
Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
Each {time} consist of digits, and represent an integer between 0 and 1000.
Each {amount} consist of digits, and represent an integer between 0 and 2000.

Algo:
Transaction
    name
    time
    amount
    city
parse to transactions
make user dict:
    dict[user]->[idx]
    sort(dict[user])
bad_idx = filterByAmount(transactions)
for _,t_idx in dict:
    for idx in t_idx:
        if tr(idx).time - tr(prev_idx).time <= 60:
            bad_idx += idx
            bad_idx += prev_idx
sort(bad_idx)
unique(bad_idx)
*/

class Solution {
    struct Transaction {
        string_view name;
        int time = 0;
        int amount = 0;
        string_view city;
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions_str) {
        auto transactions = parseTransactions(transactions_str);
        vector<int> invalid_idx;
        filterByAmount(transactions, invalid_idx);
        auto dict = makeUserDict(transactions);
        for (const auto& [_, t_idx] : dict) {
            for (size_t i = 1; i < t_idx.size(); ++i) {
                int idx = t_idx[i];
                for (size_t j = 0; j < i; ++j) {
                    int prev_idx = t_idx[j];
                    if (abs(transactions[idx].time - transactions[prev_idx].time) <= 60 &&
                        transactions[idx].city != transactions[prev_idx].city
                    ) {
                        invalid_idx.push_back(prev_idx);
                        invalid_idx.push_back(idx);
                    }
                }
            }
        }        
        sort(invalid_idx.begin(), invalid_idx.end());
        invalid_idx.erase(unique(invalid_idx.begin(), invalid_idx.end()), invalid_idx.end());
        return formBadResult(invalid_idx, transactions_str);
    }
    
private:
    vector<Transaction> parseTransactions(vector<string>& transactions_str) {
        vector<Transaction> res(transactions_str.size());
        for (size_t i = 0; i < transactions_str.size(); ++i) {
            res[i] = parseTransaction(transactions_str[i]);
        }
        return res;
    }
    
    Transaction parseTransaction(string_view str) {
        // "alice,20,800,mtv"
        Transaction t;
        // name
        auto pos = str.find(',');
        t.name = str.substr(0, pos);
        str.remove_prefix(pos+1);
        // time
        pos = str.find(',');
        from_chars(str.data(), str.data()+pos, t.time);
        str.remove_prefix(pos+1);
        // amount
        pos = str.find(',');
        from_chars(str.data(), str.data()+pos, t.amount);
        str.remove_prefix(pos+1);
        // city
        t.city = str;
        return t;
    }
    
    void filterByAmount(const vector<Transaction>& transactions, vector<int>& invalid_idx) {
        for (size_t i = 0; i < transactions.size(); ++i) {
            if (transactions[i].amount > 1000) {
                invalid_idx.push_back(i);
            }
        }
    }
    
    unordered_map<string_view, vector<int>> makeUserDict(const vector<Transaction>& transactions) {
        unordered_map<string_view, vector<int>> dict;
        for (size_t i = 0; i < transactions.size(); ++i) {
            dict[transactions[i].name].push_back(i);
        }
        for (auto& [_, idxs] : dict) {
            sort(idxs.begin(), idxs.end(), [&transactions](auto l, auto r){
                return transactions[l].time < transactions[r].time;
            });
        }
        return dict;
    }
    
    vector<string> formBadResult(const vector<int>& idxs, const vector<string>& transactions_str) {
        vector<string> res;
        res.reserve(idxs.size());
        for (int i : idxs) {
            res.push_back(transactions_str[i]);
        }
        return res;
    }
};