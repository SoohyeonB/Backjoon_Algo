#include <iostream>
#include <deque>
using namespace std;
int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	deque<int> arr;
	for (int i = 1; i <= n; i++) arr.push_back(i);
	for (int i = 0, pick = 0; i < m; i++) {
		int pivot = 0;
		cin >> pick;
		if (arr.at(pivot) != pick) {
			//위치를 찾는다
			while (arr.at(pivot++) != pick);
			//left, right 중에 작은값 찾음
			int left = pivot - 1;
			int right = arr.size() - pivot + 1;
			if (left < right) {
				for (int i = 0; i < left; i++) {
					arr.push_back(arr.front());
					arr.pop_front();
				}
				cnt += left;
			}
			else {
				for (int i = 0; i < right; i++) {
					arr.push_front(arr.back());
					arr.pop_back();
				}
				cnt += right;
			}
		}
		arr.pop_front();
	}
	cout << cnt << endl;
	return 0;
}