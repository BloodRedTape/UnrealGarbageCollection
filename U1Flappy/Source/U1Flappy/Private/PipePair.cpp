#include "PipePair.h"
#include "PlayingGameState.h"

APipePair::APipePair(){
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

void APipePair::BeginPlay(){
	Super::BeginPlay();

	APlayingGameState::Get().OnPostGameEnter.AddUObject(this, &APipePair::OnPostGameEnter);

	FBox PipeBaseBox = PipeBase->GetBoundingBox();
	FVector PipeBaseSize = PipeBaseBox.Max - PipeBaseBox.Min;

	FBox PipeTopBox = PipeTop->GetBoundingBox();
	FVector PipeTopSize = PipeTopBox.Max - PipeTopBox.Min;

	HoleOffset = FMath::RandRange(PipeTopSize.Z, PairHeight - PipeTopSize.Z - HoleSize);

	float BottomTopHeight = PipeTopSize.Z;
	float BottomBaseHeight = HoleOffset - BottomTopHeight;
	float BottomBaseScale = BottomBaseHeight/PipeBaseSize.Z;
	float TopTopHeight = PipeTopSize.Z;
	float TopBaseHeight = PairHeight - TopTopHeight - HoleSize - BottomTopHeight - BottomBaseHeight;
	float TopBaseScale = TopBaseHeight/PipeBaseSize.Z;

	BottomBase = AddSceneComponent<UStaticMeshComponent>(RootComponent);
	BottomBase->SetRelativeScale3D({1.f, 1.f, BottomBaseScale});
	BottomBase->SetRelativeLocation({0.f, 0.f, -PipeBaseBox.Min.Z * BottomBaseScale});
	BottomBase->SetStaticMesh(PipeBase);

	BottomBase->SetCollisionProfileName(TEXT("OverlapAll"));

	BottomTop = AddSceneComponent<UStaticMeshComponent>(RootComponent);
	BottomTop->SetRelativeLocation({0.f, 0.f, BottomBaseHeight - PipeTopBox.Min.Z});
	BottomTop->SetStaticMesh(PipeTop);

	BottomTop->SetCollisionProfileName(TEXT("OverlapAll"));

	TopTop = AddSceneComponent<UStaticMeshComponent>(RootComponent);
	TopTop->SetRelativeLocation({0.f, 0.f, HoleOffset + HoleSize - PipeTopBox.Min.Z});
	TopTop->SetStaticMesh(PipeTop);

	TopTop->SetCollisionProfileName(TEXT("OverlapAll"));

	TopBase = AddSceneComponent<UStaticMeshComponent>(RootComponent);
	TopBase->SetRelativeScale3D({1.f, 1.f, TopBaseScale});
	TopBase->SetRelativeLocation({0.f, 0.f, HoleOffset + HoleSize + TopTopHeight - PipeBaseBox.Min.Z*TopBaseScale});
	TopBase->SetStaticMesh(PipeBase);

	TopBase->SetCollisionProfileName(TEXT("OverlapAll"));

	Hole = AddSceneComponent<UBoxComponent>(RootComponent);
	Hole->SetRelativeLocation({0.f, 0.f, HoleOffset});
	Hole->SetBoxExtent({20.0f, 20.0f, HoleSize});

	Hole->SetCollisionProfileName(TEXT("OverlapAll"));

	Hole->OnComponentBeginOverlap.AddDynamic(this, &APipePair::OnPipeHoleEnter);
}

void APipePair::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	Location.Y -= Speed * DeltaTime;

	SetActorLocation(Location);
}

void APipePair::OnPostGameEnter() {
	PrimaryActorTick.SetTickFunctionEnable(false);
}

void APipePair::OnPipeHoleEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	APlayingGameState::Get().IncrementScore();
}
