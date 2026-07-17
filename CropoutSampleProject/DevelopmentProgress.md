# Cropout Casino Development Progress

본 문서는 `GDDRequest.md` 기획서를 바탕으로 현재까지 개발이 완료된 사항들을 추적하고 기록하기 위한 문서입니다.

---

## ✅ Phase 1: Core System (완료)

기본적인 플레이어의 이동과 상호작용, 그리고 시스템 간의 데이터 유지 및 레벨 이동의 뼈대가 완성되었습니다.

### 1. 플레이어 시스템 (Player System)
- **TPS 캐릭터 이동 및 카메라**: 마우스 뷰 회전 및 WASD 방향 이동 구현 완료
- **애니메이션 블루프린트(ABP)**: Idle -> Walk 애니메이션 전환 구현 완료
- **상호작용(Interaction) 시스템**: 
  - `F` 키 입력 시 캐릭터 반경(150.0f) 내의 오브젝트를 구형(Sphere) 오버랩으로 감지하는 로직 구현 (`GamblerChracter.cpp`)
  - 확장성을 고려한 C++ 기반 블루프린트 인터페이스 적용 (`InteractableInterface.h / .cpp`)

### 2. 데이터 유지 시스템 (Persistence System)
- **커스텀 GameInstance 구축**: `CasinoGameInstance` (C++)
  - 레벨이 전환되어도 유지되는 변수 세팅 완료
  - `PlayerGold` (초기 자본 1000G)
  - `CurrentGambleType`
  - `CurrentMultiplier`
  - `bLastResultSuccess`
  - `GameState`
- **글로벌 Enum 관리**: `CasinoTypes.h` (C++)
  - 도박 종류(`EGambleType`) 및 게임 상태(`ECasinoGameState`) 정의 완료

### 3. 도박장 및 레벨 이동 시스템
- **테스트용 도박장 액터**: `TestGamblingSpot` (C++)
  - 플레이어가 다가가서 상호작용 시, GameInstance에 현재 액터에 설정된 `EGambleType`을 저장
  - 상호작용 완료 직후 `UGameplayStatics::OpenLevel`을 통해 지정된 도박장 레벨(예: `LV_Gamble_Tree`)로 즉시 이동하는 플로우 구현

---

## ⏳ Next Step: Phase 2 (Gambling System)
*추후 개발 예정인 항목입니다.*

1. **Gamble GameMode (C++)**: 도박장 레벨 진입 시 배율/확률 랜덤 생성 로직 및 승패 계산 시스템
2. **Gamble PlayerController (C++)**: 도박장 내 캐릭터 이동 잠금 및 UI 조작 전용 마우스 커서 활성화 시스템
3. **Gamble Widget (C++ / UI)**: 화면에 배율을 띄우고 도전을 시작하는 도박 UI 베이스 구현
