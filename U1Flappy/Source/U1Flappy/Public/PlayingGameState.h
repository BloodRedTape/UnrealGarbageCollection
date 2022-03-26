#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PlayingGameState.generated.h"


enum class EFlappyState{
	PreGame,
	InGame,
	PostGame
};

UCLASS()
class U1FLAPPY_API APlayingGameState : public AGameStateBase{
	GENERATED_BODY()
private:
	EFlappyState GameState;
	int Score;
public:
	void BeginPlay()override;

	void Start();

	void Reset();

	void NextState(EFlappyState State);
};
