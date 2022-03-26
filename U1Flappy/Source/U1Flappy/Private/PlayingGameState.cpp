#include "PlayingGameState.h"
#include "Kismet/GameplayStatics.h"


void APlayingGameState::BeginPlay(){
    Super::BeginPlay();
    NextState(EFlappyState::PreGame);
}

void APlayingGameState::Start(){
    NextState(EFlappyState::InGame);
}

void APlayingGameState::Reset(){
    NextState(EFlappyState::PreGame);
}

void APlayingGameState::NextState(EFlappyState State){
    GameState = State;

    switch(GameState){
    case EFlappyState::PreGame:{
        APlayerController *ThisPlayerController = UGameplayStatics::GetPlayerController(this, 0);
    }break;
    case EFlappyState::InGame:{
        
    }break;
    case EFlappyState::PostGame:{

    }break;
    default:
        check(false);
    }
}