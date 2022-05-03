#include "PipeSpawner.h"
#include "PlayingGameState.h"

void APipeSpawner::BeginPlay(){
	Super::BeginPlay();
	APlayingGameState::Get().OnInGameEnter.AddUObject(this, &APipeSpawner::OnInGameEnter);
	APlayingGameState::Get().OnPostGameEnter.AddUObject(this, &APipeSpawner::OnPostGameEnter);
}

void APipeSpawner::OnInGameEnter(){
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APipeSpawner::SpawnPair, SpawnRate, true, 0.f);
}

void APipeSpawner::OnPostGameEnter(){
	GetWorldTimerManager().ClearTimer(SpawnTimer);
}

void APipeSpawner::SpawnPair(){
	FVector Location = GetActorLocation();

	GetWorld()->SpawnActor(PipePairClass, &Location);
}

