/**
    721. Accounts Merge
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Example 2:
Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 
Constraints:
1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j] <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.

Algo1: in-place: O(N^2*E*L), TLE
	sort emails for each name
	for i in n-1:
		for j in (i+1, n):
			if set[i] intersect set[j]:
				set[i] = merge(set[i], set[j])
				set[j] remove for O(1)
			else:
				++j
				
Algo2: secondary index: email->[account]: O(N*E*L), O(N*E*L)mem
	fill dict[email]->idx
	was = set()
	for email in si:
		res.push_back({name})
		for i in d[email]:
			for j in acc[i]:
				res.back().push_back(acc[i][j])
				was.insert(acc[i][j])
				
*/

// in-place: TLE
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // sort all accounts emails
		for (auto& account : accounts) {
			sort(account.begin()+1, account.end());
            account.erase(unique(account.begin()+1, account.end()), account.end());
		}
		// for acc_i and acc_j check if email has intersection
		for (size_t i = 0; i+1 < accounts.size(); ) {
            bool was_merge = false;
			for (size_t j = i+1; j < accounts.size(); ) {
				if (isIntersection(accounts[i], accounts[j])) 
				{   // if has:
					// merge acc_j to acc_i
					vector<string> merged;
                    merged.reserve(accounts[i].size() + accounts[j].size()-1);
					merged.push_back(accounts[i][0]);
					set_union(accounts[i].begin()+1, accounts[i].end(), 
							  accounts[j].begin()+1, accounts[j].end(),
							  back_inserter(merged));
					swap(accounts[i], merged);
					// swap(j, last) and pop_back (or only pop_back if was last)
					if (j+1 != accounts.size()) {
						swap(accounts[j], accounts.back());
					}
					accounts.pop_back();
                    was_merge = true;
				} else {
                    ++j;
                }
			}
            if (!was_merge) ++i;
		}
		
		// return res
		return accounts;
    }
    
private:
    bool isIntersection(const vector<string>& lhs, const vector<string>& rhs) {
        size_t i = 1;
        size_t j = 1;
        while (i < lhs.size() && j < rhs.size()) {
            if (lhs[i] == rhs[j]) return true;
            if (lhs[i] < rhs[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(const vector<vector<string>>& accounts) {
        unordered_map<string_view, vector<int>> dict; // dict[email] -> list of account idx
		// fill dict
		for (size_t acc_idx = 0; acc_idx < accounts.size(); ++acc_idx) {
		    const auto& account = accounts[acc_idx];
			for (size_t j = 1; j < account.size(); ++j) {
				dict[account[j]].push_back(acc_idx);
			}
		}
		// fill answer, using bfs in graph
		vector<vector<string>> res;
		unordered_set<string_view> used_emails;
		unordered_set<size_t> used_idx;
		for (const auto& [email, idxes] : dict) {
		    if (used_emails.count(email)) continue;
			res.push_back({accounts[idxes[0]][0]});
			queue<string_view> q;
			q.push(email);
			while (!q.empty()) {
			    auto email = q.front();
			    q.pop();
			    res.back().push_back(string(email));
			    used_emails.insert(email);
			    const auto& indexes = dict[email];
			    for (int idx : indexes) {
			        if (used_idx.count(idx)) continue;
			        const auto& account = accounts[idx];
			        for (size_t i = 1; i < account.size(); ++i) {
			            if (!used_emails.count(account[i])) {
			                q.push(account[i]);
			            }
			        }
			        used_idx.insert(idx);
			    }
			}
		}
		// sort result
		for (auto& account : res) {
			sort(account.begin()+1, account.end());
			account.erase(unique(account.begin()+1, account.end()), account.end());
		}
		return res;
    }
};

[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
[["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
[["Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"],["Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"],["Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"],["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"],["Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"]]
[["David","David0@m.co","David4@m.co","David3@m.co"],["David","David5@m.co","David5@m.co","David0@m.co"],["David","David1@m.co","David4@m.co","David0@m.co"],["David","David0@m.co","David1@m.co","David3@m.co"],["David","David4@m.co","David1@m.co","David3@m.co"]]
[["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]]