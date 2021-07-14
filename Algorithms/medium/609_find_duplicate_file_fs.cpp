/**
    609. Find Duplicate File in System
Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.
A group of duplicate files consists of at least two files that have the same content.
A single directory info string in the input list has the following format:
"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
"directory_path/file_name.txt"

Example 1:
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]

Example 2:
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]

Constraints:
1 <= paths.length <= 2 * 10^4
1 <= paths[i].length <= 3000
1 <= sum(paths[i].length) <= 5 * 10^5
paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.

Follow up:
Imagine you are given a real file system, how will you search files? DFS or BFS?
If the file content is very large (GB level), how will you modify your solution?
If you can only read the file by 1kb each time, how will you modify your solution?
What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?
How to make sure the duplicated files you find are not false positive?

Algo1: (naive) dict
dict[content] = [file_names]
*/

class Solution {
	struct FileInfo {
		string filename;
		string content;
	};
public:
    vector<vector<string>> findDuplicate(const vector<string>& paths) {
        unordered_map<string, vector<string>> dict; // content -> filenames
		for (const auto& dir_entry : paths) {
			auto [directory, files] = parseDirEntry(dir_entry);
			for (const auto& [fname, content] : files) {
				dict[content].push_back(directory + fname);
			}
		}
		vector<vector<string>> res;
		res.reserve(dict.size());
		for (const auto& [_, fnames] : dict) {
            if (fnames.size() > 1) {
                res.emplace_back();
                for (const auto& fname : fnames) {
                    res.back().push_back(fname);
                }
            }
		}
		return res;
    }
	
private:
	pair<string, vector<FileInfo>> parseDirEntry(string_view dir_entry) {
		size_t pos = dir_entry.find(' ');
		if (pos == string_view::npos) {
			return {string(dir_entry), vector<FileInfo>{}};
		}
		auto directory = normalizeDirectory(dir_entry.substr(0, pos));
		dir_entry.remove_prefix(pos+1);
        vector<FileInfo> file_infos;
		while (!dir_entry.empty()) {
            pos = dir_entry.find(' ');
            string_view file_record = dir_entry.substr(0, pos);
            file_infos.push_back(parseFileEntry(file_record));
            if (pos == string_view::npos) break;
            dir_entry.remove_prefix(pos+1);
        }
        return {directory, file_infos};
	}
    
    FileInfo parseFileEntry(string_view file_record) {
        FileInfo res;
        auto pos = file_record.find('(');
        auto file_name = file_record.substr(0, pos);
        file_record.remove_prefix(pos+1);
        file_record.remove_suffix(1);
        return {string(file_name), string(file_record)};
    }
    
    string normalizeDirectory(string_view directory) {
        if (directory.empty() || directory.back() != '/') {
            return string(directory) + "/";
        } else {
            return string(directory);
        }
    }
};