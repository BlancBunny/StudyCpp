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
/// 카드의 속성 구조체
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
		if (Name[0] == 'J') return 10; // 10월
		if (Name[0] == 'D') return 11; // 11월
		return 12;					   // 12월 
	}
	int GetKind() const {
		if (strcmp(Name + 1, "광") == 0) return 0;
		else if (strcmp(Name + 1, "십") == 0) return 1;
		else if (strcmp(Name + 1, "오") == 0) return 2;
		else if (strcmp(Name + 1, "쌍") == 0) return 3;
		else return 4; // 피
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
/// 전체 카드 목록 (48장)
/// </summary>
SCard flowerCard[MaxCard] = {
	"1광", "1오", "1피", "1피", "2십", "2오", "2피", "2피", "3광", "3오", "3피", "3피",
	"4십", "4오", "4피", "4피", "5십", "5오", "5피", "5피", "6십", "6오", "6피", "6피",
	"7십", "7오", "7피", "7피", "8광", "8십", "8피", "8피", "9십", "9오", "9피", "9피",
	"J십", "J오", "J피", "J피", "D광", "D쌍", "D피", "D피", "B광", "B십", "B오", "B쌍",
};

/// <summary>
/// 카드 동작 관리 클래스
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
	/// 카드 하나를 목록에 삽입 (삽입 정렬)
	/// </summary>
	/// <param name="c">카드 한장</param>
	void InsertCard(SCard c) {
		int i;
		if (c.Name[0] == 0) return;
		for (i = 0; i < num; i++) if (c < card[i]) break;
		memmove(&card[i + 1], &card[i], sizeof(SCard) * (num - i));
		card[i] = c;
		num++;
	}

	/// <summary>
	/// 카드 하나를 목록에서 제거
	/// </summary>
	/// <param name="idx">카드의 인덱스</param>
	/// <returns></returns>
	SCard RemoveCard(int idx) {
		assert(idx < num);
		SCard c = card[idx];
		memmove(&card[idx], &card[idx + 1], sizeof(SCard) * (num - idx - 1));
		num--;
		return c;
	}

	/// <summary>
	/// 카드와 같은 숫자 찾기
	/// </summary>
	/// <param name="c">찾으려는 카드</param>
	/// <param name="same">숫자가 같은 카드의 인덱스</param>
	/// <returns>같은 카드의 숫자 개수</returns>
	int FindSameCard(SCard c, int* same) {
		int i, n;
		int* p = same;

		for (i = 0, n = 0; i < num; i++) {
			if (card[i].GetNumber() == c.GetNumber()) {
				n++;
				*p++ = i;
			}
		}
		*p = -1; // 마지막 인덱스 표시 
		return n;
	}

	/// <summary>
	/// 해당 카드가 있는지 여부 조사
	/// </summary>
	/// <param name="name">조사할 카드</param>
	/// <returns>일치하는 카드의 인덱스</returns>
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
	/// 카드 목록에서 연속되는 숫자의 최대값 (4일 경우 게임 종료, 3일 경우 폭탄/흔들기) 
	/// </summary>
	/// <returns>연속되는 숫자의 최대값</returns>
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
/// 카드덱 클래스
/// </summary>
class CDeck : public CCardSet {
public:
	CDeck(int sx, int sy) : CCardSet(sx, sy) { ; }

	/// <summary>
	/// 덱 셔플 메소드 
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
	/// 덱으로부터 카드 한장을 뽑는 메소드
	/// </summary>
	/// <returns>뽑은 카드의 객체</returns>
	SCard Pop() { return RemoveCard(num - 1); }

	bool isEmpty() { return num == 0; }
	bool isNotLast() { return num > 1; }
	void Draw(bool bFlip) {
		gotoxy(sx, sy);
		cout << "??? " << (bFlip ? card[num - 1].Name : " ");
	}
};

/// <summary>
/// 게임 플레이어 클래스
/// </summary>
class CPlayer : public CCardSet {
public: 
	CPlayer(int sx, int sy) : CCardSet(sx, sy) { ; }

	/// <summary>
	/// 손패 숫자 표시
	/// </summary>
	/// <param name="myTurn">자기 턴 여부</param>
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
/// 게임판 클래스 
/// </summary>
class CBlanket : public CPlayer {
public:
	CBlanket(int sx, int sy) : CPlayer(sx, sy) { ; }
	void Draw() {
		CPlayer::Draw(false);
	}

	/// <summary>
	/// 숫자가 같은 카드가 2장 깔렸을때 한장 고르는 메소드
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
	/// 낸 카드/펼친 카드와 깔린 카드를 매치시키는 메소드
	/// </summary>
	/// <param name="idx">일치하는 깔린 카드의 인덱스</param>
	/// <param name="c">일치하는 낸 카드/펼친 카드</param>
	void DrawTempCard(int idx, SCard c) {
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << c;
	}
};

/// <summary>
/// 손패 클래스
/// </summary>
class CPlayerHand : public CCardSet {
private:
	int nGo;

public:
	int oldScore; 
	int bShake; // 흔들기

	CPlayerHand(int x, int y) : CCardSet(x, y) { oldScore = 6; nGo = 0; bShake = false; }
	void Reset() { CCardSet::Reset(); oldScore = 6; nGo = 0; bShake = false; }
	
	int GetGo() { return nGo; }  
	void IncreaseGo() { nGo++; } 

	/// <summary>
	/// 먹은 패 출력
	/// </summary>
	void Draw() {
		int i, kind;
		int x[4] = { sx, sx, sx, sx }, py = sy + 3;

		for (i = 0; i < num; i++) {
			kind = card[i].GetKind();;
			if (kind >= 3) kind = 3; // 피, 쌍피 
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
		cout << "점수:" << CalcScore() << "점, " << nGo << "고 " << (bShake ? "흔듬" : "");
	}    

	/// <summary>
	/// 피 n장 제거 (4장, 쪽, 따닥, 싹슬이)
	/// </summary>
	/// <returns> 제거된 피의 수 </returns>
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
				*p++ = RemoveCard(FindFirstCard("피"));
				return 1;
			}
			else { // 피가 하나도 없을 경우 쌍피 압수
				*p++ = RemoveCard(FindFirstCard("쌍"));
				return 1;
			}
			break;
		case 2: // 2장 압수시 
			if (ns != 0) { // 쌍피 1장
				*p = RemoveCard(FindFirstCard("쌍"));
				return 1;
			}
			else { // 피 2장
				*p++ = RemoveCard(FindFirstCard("피"));
				peeNum = 2;
			}
			return peeNum;
		case 3: // 3장 압수시 
			i = RemovePee(2, p);
			p += i;
			idx = RemovePee(1, p);
			return i + idx;
		default:
			return 0;
		}
	}

	/// <summary>
	/// 점수 계산
	/// </summary>
	/// <returns></returns>
	int CalcScore() {
		int i, kind, n[4] = { 0, };
		int newScore;
		static int gScore[] = { 0,0,0,3,4,15 };

		for (i = 0; i < num; i++) {
			kind = card[i].GetKind();
			if (kind == 3) n[kind]++; // 쌍피일 경우 1피 추가 
			if (kind >= 3) kind = 3;
			n[kind]++;
		}
		newScore = gScore[n[0]];
		if (n[0] == 3 && FindFirstCard("B광") != -1) newScore--;
		if (n[1] >= 5) newScore += (n[1] - 4);
		if (n[2] >= 5) newScore += (n[2] - 4);
		if (n[3] >= 10) newScore += (n[3] - 9);
		// 고도리
		if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1)
			newScore += 5;
		// 홍단
		if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1)
			newScore += 3;
		// 초단
		if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1)
			newScore += 3;
		// 청단
		if (FindFirstCard("6오") != -1 && FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1)
			newScore += 3;
		return newScore;
	}   // 점수 계산
};


/*====================================*/
// 화면 표시 요소 좌표 설정
CDeck deck(18, 9);
CPlayer south(5, 20), north(5, 1);
CBlanket blanket(5, 12);
CPlayerHand southHand(40, 14), northHand(40, 4);
bool southTurn;

// 도우미 함수 
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
		
		// 손패, 깔린 패 중에 같은 숫자 4장이 있으면 리셋 
		if (south.GetMaxSeries() != 4 && north.GetMaxSeries() != 4 && blanket.GetMaxSeries() != 4)
			break;
	}
	
}

// 화면에 표시 
void DrawScreen() {
	clrscr();
	south.Draw(southTurn);
	north.Draw(!southTurn);
	blanket.Draw();
	deck.Draw(false);
	southHand.Draw();
	northHand.Draw();
}

// 메시지 출력 
void OutPrompt(const char* message, int wait = 0) {
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << message;
	delay(wait);
}

// 플레이어 숫자 입력 (a : 10)
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

		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력하세요.");
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
	/// 흔들기 여부 검사
	/// </summary>
	if (south.GetMaxSeries() == 3) {
		ch = InputInt("같은 카드가 세 장입니다. (1:흔들기, 2:그냥 하기) ", 1, 2);
		if (ch == 1) southHand.bShake = true;
	}
	if (north.GetMaxSeries() == 3) {
		ch = InputInt("같은 카드가 세 장입니다. (1:흔들기, 2:그냥 하기) ", 1, 2);
		if (ch == 1) northHand.bShake = true;
	}

	/// <summary>
	/// 게임 진행 반복
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

		sprintf_s(mes, "내고 싶은 패를 선택하세요(1~%d, 0:종료) ", turn->GetNum());
		ch = InputInt(mes, 0, turn->GetNum());
		if (ch == 0) {
			if (InputInt("정말 끝내시겠습니까? (0:예, 1:아니오)", 0, 1) == 0)
				return 0;
			else continue;
		}
		

		/// <summary>
		/// 플레이어가 낸 카드와 같은 숫자 카드가 있는지 탐색
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
				sprintf_s(mes, "어떤 카드를 선택하시겠습니까? (1~%d)", sameNum);
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
		/// 덱에서 카드를 한장 뒤집어 같은 카드가 있는지 탐색
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
					OutPrompt("쌌습니다.", PromptSpeed);
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
					sprintf_s(mes, "어떤 카드를 선택하시겠습니까?(1~%d)", sameNum);
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
		/// 일치하는 카드 모두 점수판으로 회수
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
		/// 쪽, 따닥, 싹슬이 조건 검사
		/// </summary>
		nSnatch = 0;
		if (deck.isNotLast()) {
			if (userSel == -1 && sameNum == 1 && deckCard.GetNumber() == userCard.GetNumber()) {
				nSnatch++;
				OutPrompt("쪽입니다.", PromptSpeed);
			}
			if (userSel == -1 && sameNum == 2 && deckCard.GetNumber() == userCard.GetNumber()) {
				nSnatch++;
				OutPrompt("따닥입니다.", PromptSpeed);
			}
			if (blanket.GetNum() == 0) {
				nSnatch++;
				OutPrompt("싹슬이입니다.", PromptSpeed);
			}
			if (userTriple || deckTriple) {
				OutPrompt("한꺼번에 세 장을 먹었습니다.", PromptSpeed);
				nSnatch += userTriple + deckTriple;
			}
		}

		// 뺏은 카드 옮기기 (쌍피 추가) 
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
			if (InputInt("추가 점수를 획득했습니다.(0:스톱, 1:고)", 0, 1) == 1) {
				turnHand->oldScore = newScore;
				turnHand->IncreaseGo();
			}
			else {
				break;
			}
		}
	}

	DrawScreen();
	OutPrompt("게임이 끝났습니다");

	return 0;
}
