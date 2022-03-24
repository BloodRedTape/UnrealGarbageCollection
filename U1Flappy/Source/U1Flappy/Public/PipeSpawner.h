#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PipePair.h"
#include "PipeSpawner.generated.h"

UCLASS()
class U1FLAPPY_API APipeSpawner : public AActor{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category="Spawn")
	TSubclassOf<APipePair> PipePairClass;

	UPROPERTY(EditAnywhere, Category="Spawn")
	float SpawnRate = 2;

	FTimerHandle SpawnTimer;
public:
	virtual void BeginPlay() override;

	void SpawnPair();
};
