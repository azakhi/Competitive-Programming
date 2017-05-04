#include <iostream>
using namespace std;

class node {
public:
	long long tot;
	long long ext = 0LL;
	long long size;

	node* next;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n;
	cin >> s;

	node* ltop = NULL;
	int num;
	if (s > 1) {
		cin >> num;
		ltop = new node;
		ltop->tot = num;
		ltop->ext = 0;
		ltop->size = 1;
		ltop->next = NULL;
	}
	for (int i = 2; i < s; i++) {
		cin >> num;

		if (num <= ((float)ltop->tot / ltop->size)) {
			ltop->ext += ltop->tot;
			ltop->tot += num;
			ltop->size++;
		}
		else {
			node* ntop = new node;
			ntop->tot = num;
			ntop->ext = 0;
			ntop->size = 1;
			ntop->next = ltop;
			ltop = ntop;
		}
	}

	long long total = 0LL;
	cin >> num;
	total += num;

	node* rtop = NULL;
	node* rtail = NULL;
	if (n > s) {
		cin >> num;
		rtop = new node;
		rtop->tot = num;
		rtop->ext = 0;
		rtop->size = 1;
		rtop->next = NULL;
		rtail = rtop;
	}
	for (int i = (s + 1); i < n; i++) {
		cin >> num;

		if (num > ((float)(rtail->tot - 1) / rtail->size)) {
			rtail->ext += rtail->size * num;
			rtail->tot += num;
			rtail->size++;
		}
		else {
			node* ntail = new node;
			ntail->tot = num;
			ntail->ext = 0;
			ntail->size = 1;
			ntail->next = NULL;
			rtail->next = ntail;
			rtail = ntail;
		}
	}
	
	bool merg = true;
	while (merg) {
		merg = false;
		if (ltop != NULL) {
			node* cur = ltop;
			while (cur->next != NULL) {
				float curAvg = (float)cur->tot / cur->size;
				float nextAvg = (float)cur->next->tot / cur->next->size;
				if (curAvg <= nextAvg) {
					cur->ext += cur->size * cur->next->tot + cur->next->ext;
					cur->tot += cur->next->tot;
					cur->size += cur->next->size;
					cur->next = cur->next->next;

					merg = true;
				}
				else {
					cur = cur->next;
				}
			}
		}
	}
	
	merg = true;
	while (merg) {
		merg = false;

		if (rtop != NULL) {
			node* cur = rtop;
			while (cur->next != NULL) {
				float curAvg = (float)cur->tot / cur->size;
				float nextAvg = (float)cur->next->tot / cur->next->size;
				if (curAvg <= nextAvg) {
					cur->ext += cur->size * cur->next->tot + cur->next->ext;
					cur->tot += cur->next->tot;
					cur->size += cur->next->size;
					cur->next = cur->next->next;

					merg = true;
				}
				else {
					cur = cur->next;
				}
			}
		}
	}
	
	int day = 2;
	while (ltop != NULL || rtop != NULL) {
		if (ltop == NULL) {
			while (rtop != NULL) {
				total += day * rtop->tot + rtop->ext;
				day += rtop->size;
				rtop = rtop->next;
			}
		}
		else if (rtop == NULL) {
			while (ltop != NULL) {
				total += day * ltop->tot + ltop->ext;
				day += ltop->size;
				ltop = ltop->next;
			}
		}
		else {
			long long lh = (long long)ltop->tot * rtop->size;
			long long rh = (long long)rtop->tot * ltop->size;

			if (lh > rh) {
				total += day * ltop->tot + ltop->ext;
				day += ltop->size;
				ltop = ltop->next;
			}
			else {
				total += day * rtop->tot + rtop->ext;
				day += rtop->size;
				rtop = rtop->next;
			}
		}
	}
	
	cout << total << endl;
	return 0;
}