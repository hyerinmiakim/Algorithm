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
int main() {
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

int main()
{
  solution1();
  solution2();
  return 0; 
}