GAME DESIGN DOCUMENT
Project: Cropout Casino Prototype

Version: 0.1
Engine: Unreal Engine 5.8
Development Period: 2 Weeks
Genre: Risk Reward Gambling Game
Camera: Third Person Perspective


==================================================
1. GAME OVERVIEW
==================================================

Concept:

Cropout 스타일의 귀여운 마을에서 플레이어가 가진 모든 돈을 걸고
단 한 번의 도박에 도전하는 게임.

플레이어는 1,000G를 가지고 시작한다.

3개의 서로 다른 도박 중 하나를 선택한다.

성공:
- 10,000G 획득
- Victory Level 이동

실패:
- 모든 돈 손실
- Police Chase Level 이동


Core Experience:

"귀여운 외형 속 위험한 한 방 도박"


Player Emotion:

- 이번에는 성공할 것 같다.
- 위험하지만 도전하고 싶다.
- 결과가 나올 때까지 긴장된다.
- 성공하면 대박.
- 실패하면 파산.



==================================================
2. DEVELOPMENT SCOPE
==================================================

Goal:

2주 안에 하나의 완성된 도박 Scene 경험 제작.


Required:

- TPS Player Controller
- Main Village Level
- 3 Gambling Levels
- Random Gambling System
- Victory Result
- Police Chase Failure Event


Not Required:

- Inventory System
- Quest System
- Save System
- Growth System
- Multiple Stage
- Complex AI



==================================================
3. GAME FLOW
==================================================


Start Game

↓

Main Village Level

↓

Select Gambling Spot

↓

Open Gambling Level

↓

Generate Random Data

↓

Gambling Start

↓

Result


SUCCESS

↓

Victory Level


FAIL

↓

Police Chase Level

↓

Game Over



==================================================
4. PLAYER SYSTEM
==================================================

Controller:

Third Person Character


Camera:

TPS Camera

Reference:
PUBG Style Camera


Input:

WASD
- Character Movement


Mouse
- Camera Control


F Key
- Interaction



Gambling State:

When entering Gambling Level:

Disable:
- Movement
- Camera Control


Enable:
- UI Input



After Gambling:

Restore Player Control.



==================================================
5. CURRENCY SYSTEM
==================================================


Initial Gold:

1000G



Success:

Reward:

10000G



Failure:

Gold:

0G



==================================================
6. CORE GAMBLING SYSTEM
==================================================


Design:

All or Nothing Gambling


Player does not repeatedly increase money.


One gamble decides:

- Jackpot
- Bankruptcy



Flow:


Enter Gambling Area

↓

Generate Random Odds

↓

Show Gambling UI

↓

Player Confirm

↓

Calculate Result

↓

Play Result Animation

↓

Success / Fail



==================================================
7. RANDOM SYSTEM
==================================================


Every gambling attempt creates new values.


Random Variables:

- Multiplier
- Success Probability


Example:


Multiplier:

x4.5


Success Probability:

Hidden



Balance Rule:


High Multiplier

=

Low Success Probability



Low Multiplier

=

High Success Probability



Player does not know exact success probability.



==================================================
8. GAMBLING CONTENT
==================================================



--------------------------------------------------
A. GOLDEN TREE GAMBLING
--------------------------------------------------


Level:

LV_Gamble_Tree


Concept:

황금 나무에 도전하는 고위험 도박.



Flow:

Enter Tree Area

↓

Generate Odds

↓

Show UI

↓

Axe Action

↓

Tree Reaction

↓

Result



Required:

- Golden Tree
- Axe Animation
- Camera Shake
- Particle Effect
- Result Feedback



UI:

Golden Tree Gambling

Reward:
x4.2

Risk:
Unknown

Button:
Challenge



--------------------------------------------------
B. RESIDENT RACE GAMBLING
--------------------------------------------------


Level:

LV_Gamble_Race


Concept:

귀여운 주민들의 레이스 결과에 모든 돈을 건다.



Flow:

Enter Race Area

↓

Generate Odds

↓

Start Race

↓

Watch Result

↓

Success / Fail



Required:

- Race Track
- NPC Racers
- Random Winner
- Crowd Reaction



--------------------------------------------------
C. STOCK MARKET GAMBLING
--------------------------------------------------


Level:

LV_Gamble_Stock


Concept:

마을 자원의 가치를 예측하는 가짜 주식 시장.



Flow:

Open Stock UI

↓

Generate Chart

↓

Player Invest

↓

Chart Movement

↓

Result



Required:

- Chart UI
- Random Graph
- Price Animation
- Result Popup



==================================================
9. LEVEL STRUCTURE
==================================================


Levels:


LV_MainVillage


LV_Gamble_Tree


LV_Gamble_Race


LV_Gamble_Stock


LV_Victory


LV_PoliceChase



==================================================
10. MAIN VILLAGE
==================================================


Purpose:

도박 선택 공간.


Layout:


Race Area


Tree Area     Central Plaza     Stock NPC


Player Start



Design Rule:

- 모든 도박장이 보인다.
- 이동 시간을 최소화한다.
- 선택 고민에 집중한다.



==================================================
11. LEVEL TRANSITION
==================================================


Method:

Open Level


Data Persistence:

BP_CasinoGameInstance



Stored Data:


PlayerGold

CurrentGambleType

Multiplier

Result

GameState



==================================================
12. BLUEPRINT STRUCTURE
==================================================


Base:


BP_GambleBase



Variables:


Multiplier

SuccessProbability

Result



Functions:


GenerateRandomData()

StartGamble()

CalculateResult()

GiveReward()



Child:


BP_TreeGamble


BP_RaceGamble


BP_StockGamble



==================================================
13. UI STRUCTURE
==================================================


Base:


WBP_GambleBase



Child:


WBP_Tree


WBP_Race


WBP_Stock



==================================================
14. RESULT SYSTEM
==================================================


Success:


Random Success

↓

Gold = 10000

↓

Victory Level



Failure:


Random Fail

↓

Gold = 0

↓

Police Chase Level



==================================================
15. POLICE CHASE SYSTEM
==================================================


Purpose:

실패 연출.


Flow:


Player loses

↓

Police Spawn

↓

Player Runs

↓

Police Chase

↓

Capture

↓

Game Over



Implementation:


Simple Chase Movement


No complex AI required.


Example:


Player Speed:

600


Police Speed:

750



Player can escape temporarily.

Player cannot permanently escape.



==================================================
16. ART DIRECTION
==================================================


Style:

- Cropout Inspired
- Toon Shading
- Low Poly
- Cute Characters



Mood:


Normal:

- Bright
- Colorful
- Relaxed


Failure:

- Police Alarm
- Dark Lighting
- Panic Mood



==================================================
17. DEVELOPMENT PRIORITY
==================================================


Phase 1:

Core System

1. Player Movement
2. Main Village
3. Open Level
4. GameInstance Data
5. Gold System


Phase 2:

Gambling

1. Base Gambling Logic
2. Tree Gambling
3. Race Gambling
4. Stock Gambling


Phase 3:

Polish

1. UI
2. Sound
3. VFX
4. Camera Shake
5. Ending Presentation



==================================================
FINAL SUMMARY
==================================================


Cropout Casino는 귀여운 마을 속에서 벌어지는
단판 도박 게임이다.


플레이어는 1000G를 가지고 시작한다.


3개의 도박 중 하나를 선택한다.


성공:

10000G 획득

승리


실패:

0G

경찰 추격

게임 종료


핵심 재미:

"귀여운 세계에서 벌어지는 위험한 한 방 승부"