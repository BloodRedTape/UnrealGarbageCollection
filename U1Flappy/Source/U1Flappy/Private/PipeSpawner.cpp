#include "PipeSpawner.h"

void APipeSpawner::BeginPlay(){
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APipeSpawner::SpawnPair, SpawnRate, true, 0.f);
}

void APipeSpawner::SpawnPair(){
	FVector Location = GetActorLocation();

	GetWorld()->SpawnActor(PipePairClass, &Location);
}

