#include "SrcMain.h"
#include <iostream>
#include <fstream>
#include "sha1.h"
#include "HashTable.hpp"
#include <vector>
#include <algorithm>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <functional>
#include <tbb/parallel_invoke.h>

// Helper function declaration - not used
//template <typename T>
//void Helper(std::vector<std::string>& crackArr, std::vector<std::string>& words, HashTable<T>& indexTable, size_t size, size_t a, size_t b);

void ProcessCommandArgs(int argc, const char* argv[])
{
	std::string cmd = argv[1];
	if (cmd == "dictionary") {
		// create HashTable
		size_t capacity = atoll(argv[2]);
		HashTable<std::string> table(capacity);
		// Open dictionary file
		std::ifstream dictionary(argv[3]);
		if (dictionary.is_open()) {
			unsigned char hash[20];
			std::string row, hexStr;
			hexStr.resize(40);
			while (!dictionary.eof()) {
				std::getline(dictionary, row);
				sha1::Calc(row.c_str(), row.length(), hash);
				sha1::ToHexString(hash, &hexStr[0]);
				table.Insert(hexStr, row);
			}
			dictionary.close();
		}
		else {
			std::cout << "failed to open dictionary file" << std::endl;
		}
		std::ifstream passwords(argv[4]);
		std::ofstream output("solved.txt");
		if (passwords.is_open() && output.is_open()) {
			std::string row;
			std::string* word;
			while (!passwords.eof()) {
				std::getline(passwords, row);
				word = table.Find(row);
				if (word != nullptr) {
					output << row << ',' << *word << "\n";
				}
			}
			passwords.close();
			output.close();
		}
	}
	else if (cmd == "phrases") {
		size_t capacity = atoll(argv[2]);
		HashTable<int> indexTable(capacity);
		std::vector<std::string> words;
		std::string row;
		std::ifstream dictionary(argv[3]);
		if (dictionary.is_open()) {
			while (!dictionary.eof()) {
				std::getline(dictionary, row);
				words.emplace_back(row);
			}
			dictionary.close();
		}
		else {
			std::cout << "Could not open dictionary file" << std::endl;
		}
		std::vector<std::string> passwords;
		int count = 0;
		std::ifstream pwFile(argv[4]);
		if (pwFile.is_open()) {
			while (!pwFile.eof()) {
				std::getline(pwFile, row);
				passwords.emplace_back(row);
				indexTable.Insert(row, count++);
			}
			pwFile.close();
		}

		// *INDEX ARITHMETICS*
		// Make one-to-one correspondence from i (0 <= i < size^4) to a four-word phrase
		size_t size = words.size();
		size_t size2 = size * size;
		size_t size3 = size2 * size;
		size_t size4 = size3 * size;
		std::vector<std::string> crackArr(count);
		tbb::parallel_for(tbb::blocked_range<size_t>(0, size4),
			[&](const tbb::blocked_range<size_t>& r) {
			unsigned char hash[20];
			int* pos;
			std::string str, hexStr;
			hexStr.resize(40);
			size_t i = r.begin();
			size_t end = r.end() + 1;
			// caculate each index from i
			size_t x0 = i % size;
			size_t x1 = (i % size2) / size;
			size_t x2 = (i % size3) / size2;
			size_t x3 = i / (size3);
			while(++i != end) {
				str += words[x3];
				str += words[x2];
				str += words[x1];
				str += words[x0];
				sha1::Calc(str.c_str(), str.length(), hash);
				sha1::ToHexString(hash, &hexStr[0]);
				// check if this phrase is a password
				if ((pos = indexTable.Find(hexStr)) != nullptr) {
					// put string into the array at the correct position
					crackArr[*pos] = std::move(str);
				}
				str.clear();
				// index recalculation
				if (++x0 == size) {
					x0 = 0;
					if (++x1 == size) {
						x1 = 0;
						if (++x2 == size) {
							x2 = 0;
							++x3;
						}
					}
				}
			}
		});
	/*
		// Another way using parallel_invoke with helper function
		tbb::parallel_invoke(
			[&] { Helper<int>(crackArr, words, indexTable, size, 0, x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, x, 2 * x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, 2 * x, 3 * x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, 3 * x, 4 * x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, 4 * x, 5 * x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, 5 * x, 6 * x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, 6 * x, 7 * x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, 7 * x, 8 * x); },
			[&] { Helper<int>(crackArr, words, indexTable, size, 8 * x, size4); }
		);
		*/
		// write to output file
		std::ofstream out("solved.txt");
		if (out.is_open()) {
			for (size_t i = 0; i < count; ++i) {
				out << passwords[i] << ',' << crackArr[i] << '\n';
			}
			out.close();
		}
		return;
	}
}

/*
template <typename T>
void Helper(std::vector<std::string>& crackArr, std::vector<std::string>& words, HashTable<T>& indexTable, size_t size, size_t a, size_t b) {
	unsigned char hash[20];
	int* pos;
	std::string str, hexStr;
	size_t size2 = size * size;
	size_t size3 = size2 * size;
	hexStr.resize(40);
	for (size_t i = a; i != b; ++i) {
		str = words[i / size3].append(words[(i%size3) / size2]).append(words[(i%size2) / size]).append(words[i%size]);
		sha1::Calc(str.c_str(), str.length(), hash);
		sha1::ToHexString(hash, &hexStr[0]);
		if ((pos = indexTable.Find(hexStr)) != nullptr) {
			crackArr[*pos] = std::move(str);
		}
	}
}
*/