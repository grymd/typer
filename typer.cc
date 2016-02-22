/**
 * Simple tool to help to learn new keyboard loyout.  It generates string then
 * whaits for user input.  Input is compared to generated string.
 *
 * ca - list of chracters to learn
 * STR_LEN - excersize length
 * SET_LEN - number of characters to group into one set
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

static const string ca("uidh");

#define STR_LEN 40
#define SET_LEN 4

#define CHAR_COUNT (SET_LEN + 1)
#define SET_COUNT ((STR_LEN + 1) / CHAR_COUNT)

static void genset(char *set, const string *s, int n) {
	while (n--) set[n] = (*s)[rand() % s->size()];
}

static void genstr(char *str) {
	for (int i = 0; i < SET_COUNT;) {
		genset(str + i * CHAR_COUNT, &ca, SET_LEN);
		i++;
		if (i < SET_COUNT)
			str[i * CHAR_COUNT - 1] = ' ';
		else
			str[i * CHAR_COUNT - 1] = '\0';
	}
}

int main() {
	char set[STR_LEN + 1];
	string s;

	srand(time(NULL));

	for (;;) {
		genstr(set);
		cout << set << endl;
		getline(cin, s);
		int i = s.compare(set);
		if (i) {
			cout << "FAILED\n\n";
		} else
			cout << "PASSED. CONGRATS!\n\n";
	}

	return 0;
}
