#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "../cursor.h"
#include <iostream>
#include <assert.h>

using namespace std;

const int MaxCard = 48;
const int CardGap = 4;
const int Speed = 1000;
const int PromptSpeed = 2000;

/// <summary>
/// ī���� �Ӽ� ����ü
/// </summary>
struct SCard
{
	char Name[4];
	SCard() { Name[0] = 0; }
	SCard(const char* name) {
		strcpy_s(this->Name, strlen(name) + 1, name);
	}
	int GetNumber() const {
		if (isdigit(Name[0])) return Name[0] - '0';
		if (Name[0] == 'J') return 10; // 10��
		if (Name[0] == 'D') return 11; // 11��
		return 12;					   // 12�� 
	}
	int GetKind() const {
		if (strcmp(Name + 1, "��") == 0) return 0;
		else if (strcmp(Name + 1, "��") == 0) return 1;
		else if (strcmp(Name + 1, "��") == 0) return 2;
		else if (strcmp(Name + 1, "��") == 0) return 3;
		else return 4; // ��
	}
	friend ostream& operator <<(ostream& c, const SCard& C) {
		return c << C.Name;
	}
	bool operator ==(const SCard& other) const {
		return (strcmp(Name, other.Name) == 0);
	}
	bool operator <(const SCard& other) const {
		if (GetNumber() < other.GetNumber()) return true;
		if (GetNumber() > other.GetNumber()) return false;
		if (GetKind() > other.GetKind()) return true;
		return false;
	}
};

/// <summary>
/// ��ü ī�� ��� (48��)
/// </summary>
SCard flowerCard[MaxCard] = {
	"1��", "1��", "1��", "1��", "2��", "2��", "2��", "2��", "3��", "3��", "3��", "3��",
	"4��", "4��", "4��", "4��", "5��", "5��", "5��", "5��", "6��", "6��", "6��", "6��",
	"7��", "7��", "7��", "7��", "8��", "8��", "8��", "8��", "9��", "9��", "9��", "9��",
	"J��", "J��", "J��", "J��", "D��", "D��", "D��", "D��", "B��", "B��", "B��", "B��",
};

/// <summary>
/// ī�� ���� ���� Ŭ����
/// </summary>
class CCardSet {
protected:
	SCard card[MaxCard];
	int num;
	const int sx, sy;
	CCardSet(int x, int y) : sx(x), sy(y) { num = 0; }

public:
	int GetNum() { return num; }
	SCard GetCard(int idx) { return card[idx]; }
	void Reset() {
		for (int i = 0; i < MaxCard; i++) card[i].Name[0] = 0;
		num = 0;
	}

	/// <summary>
	/// ī�� �ϳ��� ��Ͽ� ���� (���� ����)
	/// </summary>
	/// <param name="c">ī�� ����</param>
	void InsertCard(SCard c) {
		int i;
		if (c.Name[0] == 0) return;
		for (i = 0; i < num; i++) if (c < card[i]) break;
		memmove(&card[i + 1], &card[i], sizeof(SCard) * (num - i));
		card[i] = c;
		num++;
	}

	/// <summary>
	/// ī�� �ϳ��� ��Ͽ��� ����
	/// </summary>
	/// <param name="idx">ī���� �ε���</param>
	/// <returns></returns>
	SCard RemoveCard(int idx) {
		assert(idx < num);
		SCard c = card[idx];
		memmove(&card[idx], &card[idx + 1], sizeof(SCard) * (num - idx - 1));
		num--;
		return c;
	}

	/// <summary>
	/// ī��� ���� ���� ã��
	/// </summary>
	/// <param name="c">ã������ ī��</param>
	/// <param name="same">���ڰ� ���� ī���� �ε���</param>
	/// <returns>���� ī���� ���� ����</returns>
	int FindSameCard(SCard c, int* same) {
		int i, n;
		int* p = same;

		for (i = 0, n = 0; i < num; i++) {
			if (card[i].GetNumber() == c.GetNumber()) {
				n++;
				*p++ = i;
			}
		}
		*p = -1; // ������ �ε��� ǥ�� 
		return n;
	}

	/// <summary>
	/// �ش� ī�尡 �ִ��� ���� ����
	/// </summary>
	/// <param name="name">������ ī��</param>
	/// <returns>��ġ�ϴ� ī���� �ε���</returns>
	int FindFirstCard(const char* name) {
		int i;

		for (i = 0; i < num; i++) {
			if (strstr(card[i].Name, name) != NULL) {
				return i;
			}
		}
		return -1;
	}

	/// <summary>
	/// ī�� ��Ͽ��� ���ӵǴ� ������ �ִ밪 (4�� ��� ���� ����, 3�� ��� ��ź/����) 
	/// </summary>
	/// <returns>���ӵǴ� ������ �ִ밪</returns>
	int GetMaxSeries() {
		int i, n, m, old = -1;

		for (i = 0, n = 1, m = 1; i < num; i++) {
			if (old == card[i].GetNumber()) {
				n++;
				m = max(n, m);
			}
			else {
				n = 1;
				old = card[i].GetNumber();
			}
		}
		return m;
	}
};

/// <summary>
/// ī�嵦 Ŭ����
/// </summary>
class CDeck : public CCardSet {
public:
	CDeck(int sx, int sy) : CCardSet(sx, sy) { ; }

	/// <summary>
	/// �� ���� �޼ҵ� 
	/// </summary>
	void Shuffle() {
		int i, n;
		for (i = 0; i < MaxCard; i++) {
			do {
				n = random(MaxCard);
			} while (card[n].Name[0] != NULL);
			card[n] = flowerCard[i];
			num++;
		}
	}

	/// <summary>
	/// �����κ��� ī�� ������ �̴� �޼ҵ�
	/// </summary>
	/// <returns>���� ī���� ��ü</returns>
	SCard Pop() { return RemoveCard(num - 1); }

	bool isEmpty() { return num == 0; }
	bool isNotLast() { return num > 1; }
	void Draw(bool bFlip) {
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? card[num - 1].Name : " ");
	}
};

/// <summary>
/// ���� �÷��̾� Ŭ����
/// </summary>
class CPlayer : public CCardSet {
public: 
	CPlayer(int sx, int sy) : CCardSet(sx, sy) { ; }

	/// <summary>
	/// ���� ���� ǥ��
	/// </summary>
	/// <param name="myTurn">�ڱ� �� ����</param>
	void Draw(bool myTurn) {
		int i, x;
		for (i = 0, x = sx; i < num; i++, x += CardGap) {
			gotoxy(x, sy);
			cout << card[i];
			if (myTurn) {
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

/// <summary>
/// ������ Ŭ���� 
/// </summary>
class CBlanket : public CPlayer {
public:
	CBlanket(int sx, int sy) : CPlayer(sx, sy) { ; }
	void Draw() {
		CPlayer::Draw(false);
	}

	/// <summary>
	/// ���ڰ� ���� ī�尡 2�� ������� ���� ���� �޼ҵ�
	/// </summary>
	/// <param name="same"></param>
	void DrawSelNum(int* same) {  
		int n;
		int* p;
		for (n = 1, p = same; *p != -1; p++, n++) {
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}

	/// <summary>
	/// �� ī��/��ģ ī��� �� ī�带 ��ġ��Ű�� �޼ҵ�
	/// </summary>
	/// <param name="idx">��ġ�ϴ� �� ī���� �ε���</param>
	/// <param name="c">��ġ�ϴ� �� ī��/��ģ ī��</param>
	void DrawTempCard(int idx, SCard c) {
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << c;
	}
};

/// <summary>
/// ���� Ŭ����
/// </summary>
class CPlayerHand : public CCardSet {
private:
	int nGo;

public:
	int oldScore; 
	int bShake; // ����

	CPlayerHand(int x, int y) : CCardSet(x, y) { oldScore = 6; nGo = 0; bShake = false; }
	void Reset() { CCardSet::Reset(); oldScore = 6; nGo = 0; bShake = false; }
	
	int GetGo() { return nGo; }  
	void IncreaseGo() { nGo++; } 

	/// <summary>
	/// ���� �� ���
	/// </summary>
	void Draw() {
		int i, kind;
		int x[4] = { sx, sx, sx, sx }, py = sy + 3;

		for (i = 0; i < num; i++) {
			kind = card[i].GetKind();;
			if (kind >= 3) kind = 3; // ��, ���� 
			if (kind < 3) {
				gotoxy(x[kind], sy + kind);
				x[kind] += CardGap;
			}
			else {
				gotoxy(x[3], py);
				x[3] += CardGap;
				if (x[3] > 75) {
					x[3] = sx;
					py++;
				}
			}
			cout << card[i];
		}
		gotoxy(sx + 23, sy);
		cout << "����:" << CalcScore() << "��, " << nGo << "�� " << (bShake ? "���" : "");
	}    

	/// <summary>
	/// �� n�� ���� (4��, ��, ����, �Ͻ���)
	/// </summary>
	/// <returns> ���ŵ� ���� �� </returns>
	int RemovePee(int n, SCard* pCard) {
		int ns = 0, np = 0, tp;
		int i, idx, peeNum;
		SCard* p = pCard;

		for (i = 0; i < num; i++) {
			if (card[i].GetKind() == 3) ns++;
			if (card[i].GetKind() == 4) np++;
		}
		tp = ns + np;

		switch (n) {
		case 1:
			if (np != 0) { 
				*p++ = RemoveCard(FindFirstCard("��"));
				return 1;
			}
			else { // �ǰ� �ϳ��� ���� ��� ���� �м�
				*p++ = RemoveCard(FindFirstCard("��"));
				return 1;
			}
			break;
		case 2: // 2�� �м��� 
			if (ns != 0) { // ���� 1��
				*p = RemoveCard(FindFirstCard("��"));
				return 1;
			}
			else { // �� 2��
				*p++ = RemoveCard(FindFirstCard("��"));
				peeNum = 2;
			}
			return peeNum;
		case 3: // 3�� �м��� 
			i = RemovePee(2, p);
			p += i;
			idx = RemovePee(1, p);
			return i + idx;
		default:
			return 0;
		}
	}

	/// <summary>
	/// ���� ���
	/// </summary>
	/// <returns></returns>
	int CalcScore() {
		int i, kind, n[4] = { 0, };
		int newScore;
		static int gScore[] = { 0,0,0,3,4,15 };

		for (i = 0; i < num; i++) {
			kind = card[i].GetKind();
			if (kind == 3) n[kind]++; // ������ ��� 1�� �߰� 
			if (kind >= 3) kind = 3;
			n[kind]++;
		}
		newScore = gScore[n[0]];
		if (n[0] == 3 && FindFirstCard("B��") != -1) newScore--;
		if (n[1] >= 5) newScore += (n[1] - 4);
		if (n[2] >= 5) newScore += (n[2] - 4);
		if (n[3] >= 10) newScore += (n[3] - 9);
		// ����
		if (FindFirstCard("8��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("2��") != -1)
			newScore += 5;
		// ȫ��
		if (FindFirstCard("1��") != -1 && FindFirstCard("2��") != -1 && FindFirstCard("3��") != -1)
			newScore += 3;
		// �ʴ�
		if (FindFirstCard("4��") != -1 && FindFirstCard("5��") != -1 && FindFirstCard("7��") != -1)
			newScore += 3;
		// û��
		if (FindFirstCard("6��") != -1 && FindFirstCard("9��") != -1 && FindFirstCard("J��") != -1)
			newScore += 3;
		return newScore;
	}   // ���� ���
};


/*====================================*/
// ȭ�� ǥ�� ��� ��ǥ ����
CDeck deck(18, 9);
CPlayer south(5, 20), north(5, 1);
CBlanket blanket(5, 12);
CPlayerHand southHand(40, 14), northHand(40, 4);
bool southTurn;

// ����� �Լ� 
void Initialize() {
	int i;
	for (;;) {
		deck.Reset();
		south.Reset();
		north.Reset();
		blanket.Reset();

		deck.Shuffle();
		for (int i = 0; i < 10; i++) {
			south.InsertCard(deck.Pop());
			north.InsertCard(deck.Pop());
			if (i < 8) blanket.InsertCard(deck.Pop());
		}
		
		// ����, �� �� �߿� ���� ���� 4���� ������ ���� 
		if (south.GetMaxSeries() != 4 && north.GetMaxSeries() != 4 && blanket.GetMaxSeries() != 4)
			break;
	}
	
}

// ȭ�鿡 ǥ�� 
void DrawScreen() {
	clrscr();
	south.Draw(southTurn);
	north.Draw(!southTurn);
	blanket.Draw();
	deck.Draw(false);
	southHand.Draw();
	northHand.Draw();
}

// �޽��� ��� 
void OutPrompt(const char* message, int wait = 0) {
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << message;
	delay(wait);
}

// �÷��̾� ���� �Է� (a : 10)
int InputInt(const char* message, int start, int end) {
	int ch;
	OutPrompt(message);
	for (;;) {
		ch = tolower(_getch());
		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) {
			return ch;
		}

		OutPrompt("��ȿ�� ��ȣ�Դϴ�. ������ ������ �°� �ٽ� �Է��ϼ���.");
	}
}

int main() {
	int i, ch;
	int arSame[4], sameNum;
	char mes[256];
	CPlayer* turn;

	CPlayerHand* turnHand,* otherHand;
	int userIdx, userSel, deckSel;
	SCard userCard, deckCard;
	bool userTriple, deckTriple;
	int nSnatch;
	int newScore;

	randomize();
	Initialize();
	DrawScreen();
	
	/// <summary>
	/// ���� ���� �˻�
	/// </summary>
	if (south.GetMaxSeries() == 3) {
		ch = InputInt("���� ī�尡 �� ���Դϴ�. (1:����, 2:�׳� �ϱ�) ", 1, 2);
		if (ch == 1) southHand.bShake = true;
	}
	if (north.GetMaxSeries() == 3) {
		ch = InputInt("���� ī�尡 �� ���Դϴ�. (1:����, 2:�׳� �ϱ�) ", 1, 2);
		if (ch == 1) northHand.bShake = true;
	}

	/// <summary>
	/// ���� ���� �ݺ�
	/// </summary>
	for (southTurn = true; !deck.isEmpty(); southTurn = !southTurn) {
		DrawScreen();
		if (southTurn) {
			turn = &south;
			turnHand = &southHand;
			otherHand = &northHand;
		}
		else {
			turn = &north;
			turnHand = &northHand;
			otherHand = &southHand;
		}

		sprintf_s(mes, "���� ���� �и� �����ϼ���(1~%d, 0:����) ", turn->GetNum());
		ch = InputInt(mes, 0, turn->GetNum());
		if (ch == 0) {
			if (InputInt("���� �����ðڽ��ϱ�? (0:��, 1:�ƴϿ�)", 0, 1) == 0)
				return 0;
			else continue;
		}
		

		/// <summary>
		/// �÷��̾ �� ī��� ���� ���� ī�尡 �ִ��� Ž��
		/// </summary>
		userTriple = deckTriple = false;
		userIdx = ch - 1;
		userCard = turn->GetCard(userIdx);
		sameNum = blanket.FindSameCard(userCard, arSame);
		switch (sameNum) {
		case 0:
			userSel = -1;
			blanket.InsertCard(turn->RemoveCard(userIdx));
			DrawScreen();
			break;
		case 1:
			userSel = arSame[0];
			break;
		case 2:
			if (blanket.GetCard(arSame[0]) == blanket.GetCard(arSame[1])) {
				userSel = arSame[0];
			}
			else { 
				blanket.DrawSelNum(arSame);
				sprintf_s(mes, "� ī�带 �����Ͻðڽ��ϱ�? (1~%d)", sameNum);
				userSel = arSame[InputInt(mes, 1, sameNum) - 1];
			}
			break;
		case 3:
			userSel = arSame[1];
			userTriple = true;
			break;
		}
		if (userSel != -1) {
			blanket.DrawTempCard(userSel, userCard);
		}
		delay(Speed);


		/// <summary>
		/// ������ ī�带 ���� ������ ���� ī�尡 �ִ��� Ž��
		/// </summary>
		deck.Draw(true);
		delay(Speed);
		deckCard = deck.Pop();
		sameNum = blanket.FindSameCard(deckCard, arSame);
		switch (sameNum) {
		case 0:
			deckSel = -1;
			break;
		case 1:
			deckSel = arSame[0];
			if (deckSel == userSel) {
				if (deck.isNotLast()) {
					blanket.InsertCard(deckCard);
					blanket.InsertCard(turn->RemoveCard(userIdx));
					OutPrompt("�ս��ϴ�.", PromptSpeed);
					continue;
				}
				else {
					deckSel = -1;
				}
			}
			break;

		case 2:
			if (userSel == arSame[0]) {
				deckSel = arSame[1];
			}
			else if (userSel == arSame[1]) {
				deckSel = arSame[0];
			}
			else {
				if (blanket.GetCard(arSame[0]) == blanket.GetCard(arSame[1])) {
					deckSel = arSame[0];
				}
				else {
					blanket.DrawSelNum(arSame);
					sprintf_s(mes, "� ī�带 �����Ͻðڽ��ϱ�?(1~%d)", sameNum);
					deckSel = arSame[InputInt(mes, 1, sameNum) - 1];
				}
			}
			break;
		case 3:
			deckSel = arSame[1];
			deckTriple = true;
			break;
		}

		if (deckSel != -1) {
			blanket.DrawTempCard(deckSel, deckCard);
		}
		deck.Draw(false);
		delay(Speed);

		/// <summary>
		/// ��ġ�ϴ� ī�� ��� ���������� ȸ��
		/// </summary>
		if (userSel != -1) {
			if (userTriple) {
				for (i = 0; i < 3; i++) {
					turnHand->InsertCard(blanket.RemoveCard(userSel - 1));
				}
			}
			else {
				turnHand->InsertCard(blanket.RemoveCard(userSel));
			}
			turnHand->InsertCard(turn->RemoveCard(userIdx));
			if (deckSel != -1 && deckSel > userSel) {
				deckSel -= (userTriple ? 3 : 1);
			}
		}
		if (deckSel != -1) {
			if (deckTriple) {
				for (i = 0; i < 3; i++) {
					turnHand->InsertCard(blanket.RemoveCard(deckSel - 1));
				}
			}
			else {
				turnHand->InsertCard(blanket.RemoveCard(deckSel));
			}
			turnHand->InsertCard(deckCard);
		}
		else {
			blanket.InsertCard(deckCard);
		}

		/// <summary>
		/// ��, ����, �Ͻ��� ���� �˻�
		/// </summary>
		nSnatch = 0;
		if (deck.isNotLast()) {
			if (userSel == -1 && sameNum == 1 && deckCard.GetNumber() == userCard.GetNumber()) {
				nSnatch++;
				OutPrompt("���Դϴ�.", PromptSpeed);
			}
			if (userSel == -1 && sameNum == 2 && deckCard.GetNumber() == userCard.GetNumber()) {
				nSnatch++;
				OutPrompt("�����Դϴ�.", PromptSpeed);
			}
			if (blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("�Ͻ����Դϴ�.", PromptSpeed);
			}
			if (userTriple || deckTriple) {
				OutPrompt("�Ѳ����� �� ���� �Ծ����ϴ�.", PromptSpeed);
				nSnatch += userTriple + deckTriple;
			}
		}

		// ���� ī�� �ű�� (���� �߰�) 
		SCard arPee[3];
		int nPee;
		nPee = otherHand->RemovePee(nSnatch, arPee);
		for (i = 0; i < nPee; i++) {
			turnHand->InsertCard(arPee[i]);
		}
		
		/*for (i = 0; i < nSnatch; i++) {
			turnHand->InsertCard(otherHand->RemovePee());
		}*/

		newScore = turnHand->CalcScore();
		if (deck.isNotLast() && newScore > turnHand->oldScore) {
			DrawScreen();
			if (InputInt("�߰� ������ ȹ���߽��ϴ�.(0:����, 1:��)", 0, 1) == 1) {
				turnHand->oldScore = newScore;
				turnHand->IncreaseGo();
			}
			else {
				break;
			}
		}
	}

	DrawScreen();
	OutPrompt("������ �������ϴ�");

	return 0;
}
