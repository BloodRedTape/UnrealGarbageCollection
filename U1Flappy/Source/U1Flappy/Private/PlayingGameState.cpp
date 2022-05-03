#include "PlayingGameState.h"
#include "Kismet/GameplayStatics.h"


void APlayingGameState::BeginPlay(){
    Super::BeginPlay();
    NextState(EFlappyState::PreGame);
}

void APlayingGameState::NextState(EFlappyState State){
    GameState = State;

    APlayerController *ThisPlayerController = UGameplayStatics::GetPlayerController(this, 0);

    if (CurrentWidget) {
        CurrentWidget->RemoveFromParent();
        CurrentWidget = nullptr;
    }

    switch(GameState){
    case EFlappyState::PreGame:{
	    UE_LOG(LogTemp, Display, TEXT("PreGame"));

        CurrentWidget = CreateWidget<UGameWidget>(ThisPlayerController, PreGameHUDClass);
        OnPreGameEnter.Broadcast();
    }break;
    case EFlappyState::InGame:{
	    UE_LOG(LogTemp, Display, TEXT("InGame"));
        CurrentWidget = CreateWidget<UGameWidget>(ThisPlayerController, InGameHUDClass);
        OnInGameEnter.Broadcast();
    }break;
    case EFlappyState::PostGame:{
	    UE_LOG(LogTemp, Display, TEXT("PostGame"));
        CurrentWidget = CreateWidget<UGameWidget>(ThisPlayerController, PostGameHUDClass);
        OnPostGameEnter.Broadcast();
    }break;
    default:
        check(false);
    }

    CurrentWidget->AddToPlayerScreen();
}

APlayingGameState& APlayingGameState::Get(){
    check(GWorld);
    check(GWorld->GetGameState<APlayingGameState>());

    return *GWorld->GetGameState<APlayingGameState>();
}
