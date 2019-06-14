/*
Name: Huynh Duy Quoc
MSSV:18211TT5025
*/
#include<iostream>
using namespace std;
struct Node {
	int nData;
	Node* pNext;
};
struct List {
	Node *pHead, *pTail;
	List()
	{
		pHead = pTail = NULL;
	}
};
Node* getNode(int nX)
{
	Node* p = new Node;
	if (p == NULL)
		exit(1);
	else
	{
		p->nData = nX;
		p->pNext = NULL;
	}
	return p;
}
void addHead(List &L,int nX)
{
	Node* pNew = getNode(nX);
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = pNew;
	}
	else
	{
		pNew->pNext = L.pHead;
		L.pHead = pNew;
	}
}
void input(List &L, int nN)
{
	cout << "Nhap so phan tu trong mang: ";
	cin >> nN;
	for (int i = 0; i < nN; i++)
	{
		int nX;
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> nX;
		addHead(L, nX);
	}
}
void output(List &L)
{
	cout << "++++++++++++++==Linked List==++++++++++++++++" << endl;
	for (Node*p = L.pHead; p != NULL; p = p->pNext)
	{
		cout << " " << p->nData;
	}cout << endl;
}
void sapxep(List &L)
{
	int Max = L.pHead->nData;
	for (Node*p=L.pHead; p != NULL; p = p->pNext)
	{
		for (Node*q = L.pHead; q != NULL; q = q->pNext)
		{
			if (q->nData < p->nData)
			{
				Max = q->nData;
				q->nData = p->nData;
				p->nData = Max;
			}
			swap(q->nData, p->nData);
		}
	}
}

bool ktrasochinhphuong(int nX)
{
	int sqr = sqrt(nX);
	if (sqr*sqr == nX )
	{
		return true;
	}
	else
	{
		return false;
	}

}

int TongCacSoChinhPhuongCoTrongDS(List &L)
{
	int nTong = 0;
	for (Node* p = L.pHead; p != NULL; p = p->pNext)
	{
		if (ktrasochinhphuong(p->nData) == true)
		{
			nTong += p->nData;
		}
	}
	return nTong;
}

void CauG(List &L)
{
	cout << "Nhap phan tu muon them vao cuoi danh sach: ";
	int nX = 0;
	cin >> nX;
	int nKey = 0;
	for (Node*p = L.pHead; p != NULL; p = p->pNext)
	{
		if (nX == p->nData)
			nKey = 5;
		else
			nKey = 0;
	}
	if (nKey == 5)
	{
		cout << nX << " da ton tai trong DS." << endl;
	}
	else if (nKey == 0)
	{
		Node* q = getNode(nX);
		Node* pNew = getNode(nX);
		if (L.pHead = NULL)
		{
			L.pHead = L.pTail = NULL;
		}
		else
		{
			L.pTail->pNext = pNew;
			L.pTail = pNew;
		}
	}
}
void main()
{
	List L;
	int nN = 0;
	int nX = 0;
	input(L, nN);
	output(L);
	sapxep(L);
	output(L);
	cout << "Tong so chinh phuong la: " << TongCacSoChinhPhuongCoTrongDS(L) << endl;
	CauG(L);
	system("pause");
}
