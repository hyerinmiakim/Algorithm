/* [구름 level 2] 소수 판별 (복잡도: O(√n)) */
#include <iostream>
using namespace std;
bool isprime(int n) {
	for(int i = 2; i*i < n; i++)
		if(n % i == 0)	return false;
	return true;
}
int solution1() {
	char input[100];
	string output;
	cin >> input;
	if (isprime(stoi(input)))	output = "True";
	else output = "False";
	
	cout << output<<endl;
	
	return 0;
}

/* [구름 level 2] 빙글빙글1 */
#include <iostream>
using namespace std;
char check[100][100];
int solution2() {
	char input[100];
	int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	cin >> input;
	int N = stoi(input);
	int n = N-1;
	int cx = 0, cy = 0;
	check[cx][cy] = 1;

	for(int i = 0; i < N; i++) {
		int cnt = 0;
		while(cnt < n) {
			if(cx + way[i%4][1] < N)
				cx = cx + way[i%4][1];
			if (cy + way[i%4][0] < N)
				cy = cy + way[i%4][0];
			if(check[cy][cx] == 1)
				break;
			check[cy][cx] = 1;
			cnt++;
		}
		if(i > 0 && i % 2 == 0)
			n = n-2;
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(check[j][i])	
				cout << "# ";
			else
				cout << ". ";
		}
		cout << endl;
	}
	
	return 0;
}

/* [구름 level 2] 문자열 뒤집기 (O(N/2)) */
#include <iostream>
#include <cstring>
using namespace std;
int solution3() {
	char input[100];
	cin >> input;

	int right = strlen(input) - 1;
	for(int i = 0; i < strlen(input) / 2; i++) {
		char left = input[i];
		input[i] = input[right];
		input[right] = left;
		right = right-1;
	}
	cout << input;
	
	return 0;
}

/* [구름 level 2] 홀수 놀이 */
int solution4() {
	char input[100];
	cin >> input;
	int n = stoi(input);
	int num = (2 * ((n*n)-1)) + 1;
	num = num + (num-2) + (num-4);
	cout << num << '\n';
	return 0;
}

/* [구름 level 2] 재정 위기 */
#include <iostream>
#include <vector>
#include <algorithm>
int solution5() {
	vector<int> vec;
	string s, str;
	for(int i = 0; i < 3; i++) {
		cin >> str;
		vec.push_back(stoi(str));
	}
	sort(vec.begin(), vec.end());
	vec.pop_back();
	cout << vec.back();
	return 0;
}

/* [구름 시험] 뱀이 지나간 자리*/
#include <iostream>
using namespace std;
int check[101][101];
int test1() {
	int n,m;
	cin >> n >> m;
	int flag = 1;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j < m; j++) {
			if(i%2 == 1) {
				check[i][flag*(m-1)] = 1;
				flag = !flag;
				break;
			}
			else
				check[i][j] = 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) {
			if(check[i][j])
				cout << '#';
			else
				cout << '.';
		}
		cout << '\n';
	}
	return 0;
}
/* [구름 시험2] 거울 */
#include <iostream>
#include <vector>
using namespace std;
char arr[] = {'b','d','i','l','m','n','o','p','q','s','z','u','v','w','x'};
bool IsMirror(string str) {
	int len = str.length();
	for(int i = 0; i < len; ++i) {
		bool flag = false;
		for(int j = 0; j < 15; ++j) {
			if(str[i] == arr[j])	{
				flag = true;
				break;
			}
		}
		if(!flag)
			return false;

		if(str[i] == 'b') {
			if(str[len -1 - i] != 'd')	return false;
		}
		else if (str[i] == 'd') {
			if(str[len -1 -i] != 'b')	return false;
		}
		else if(str[i] == 's') {
			if(str[len -1 -i] != 'z') return false;
		}
		else if(str[i] == 'z') {
			if(str[len -1 -i] != 's')	return false;
		}
		else if(str[i] == 'p') {
			if(str[len -1 -i] != 'q')	return false;
		}
		else if(str[i] == 'q') {
			if(str[len -1 -i] != 'p')	return false;
		}
	}
	return true;
}
int test2() {
	int n;
	cin >> n;
	for(int i=0;i<n; i++) {
		string str;
		cin >> str;
		if (IsMirror(str)) cout << "Mirror" <<'\n';
		else	cout << "Normal" << '\n';
	}
	return 0;
}
/* [구름 시험3] 의좋은 형제 */
#include <iostream>
using namespace std;
int test3() {
	int a, b, n;
	cin >> a >> b >> n;
	for(int i = 0; i <n; i++) {
		int half = (i % 2 == 0) ? a : b;
		if(half % 2 == 0) half = half/2;
		else half = (half/2) + 1;

		if(i%2==0) {
			a = a-half;
			b = b + half;
		}
		else if (i%2 == 1) {
			a = a+half;
			b = b-half;
		}
	}
	cout << a << " " << b << "\n";
	return 0;
}
/* [구름 시험4] 앵무새 꼬꼬 */
#include <iostream>
#include <string>
using namespace std;
int test4() {
	int n;
	string str = "";
	cin >> n;
	getline(cin, str);
	for(int i = 0; i < n; i++) {
		getline(cin, str);
		string answer = "";
		for(char c : str) {
			char tc = tolower(c);
			if(tc == 'a' || tc == 'e' || tc == 'i' || tc == 'o' || tc == 'u') {
				answer += c;
			}
		}
		if (answer.length() == 0)	cout << "???" << "\n";
		else cout << answer << "\n";
	}
	return 0;
}
int main()
{
  solution1();
  solution2();
	solution3();
  solution4();
	test1();
	test2();
	test3();
	test4();
  return 0; 
}