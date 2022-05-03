#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "UI/GameWidget.h"
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
private:
	UPROPERTY(Category="UI", EditAnywhere)
	TSubclassOf<UGameWidget> PreGameHUDClass;
	UPROPERTY(Category="UI", EditAnywhere)
	TSubclassOf<UGameWidget> InGameHUDClass;
	UPROPERTY(Category="UI", EditAnywhere)
	TSubclassOf<UGameWidget> PostGameHUDClass;
	
	UPROPERTY()
	UGameWidget *CurrentWidget;
public:
	TMulticastDelegate<void()> OnPreGameEnter;
	TMulticastDelegate<void()> OnInGameEnter;
	TMulticastDelegate<void()> OnPostGameEnter;
public:
	void BeginPlay()override;

	void GoInGame(){ NextState(EFlappyState::InGame); }

	void GoPostGame(){ NextState(EFlappyState::PostGame); }

	bool IsPreGame()const{ return GameState == EFlappyState::PreGame; }

	bool IsInGame()const{ return GameState == EFlappyState::InGame; }

	bool IsPostGame()const{ return GameState == EFlappyState::PostGame; }

	void IncrementScore(){ Score++; CurrentWidget->SetScore(Score); }
private:
	void NextState(EFlappyState State);
public:
	static APlayingGameState &Get();
};
