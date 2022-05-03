#include "Bird.h"
#include "Components/BoxComponent.h"
#include "PlayingGameState.h"

ABird::ABird(){
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = Root = CreateDefaultSubobject<USceneComponent>(TEXT("MeshComponent"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bird's Mesh"));
	Mesh->AttachTo(RootComponent);
}

void ABird::BeginPlay(){
	Super::BeginPlay();
	PrimaryActorTick.SetTickFunctionEnable(false);

	Mesh->OnComponentBeginOverlap.AddDynamic( this, &ABird::OnOverlapBegin);
	APlayingGameState::Get().OnInGameEnter.AddUObject(this, &ABird::OnInGameEnter);
	APlayingGameState::Get().OnPostGameEnter.AddUObject(this, &ABird::OnPostGameEnter);
}

void ABird::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	Velocity += Gravity * DeltaTime;

	SetActorLocation(GetActorLocation() + FVector(0.f, 0.f, Velocity));
}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ABird::OnJump);
}

void ABird::AddForce(float Force){
	Velocity += Force / Mass;
}

void ABird::OnJump(){
	APlayingGameState &GameState = APlayingGameState::Get();

	if(GameState.IsPreGame())
		GameState.GoInGame();
	Velocity *= 0.5;
	AddForce(JumpForce);
}

void ABird::OnInGameEnter() {
	PrimaryActorTick.SetTickFunctionEnable(true);
}

void ABird::OnPostGameEnter(){
	PrimaryActorTick.SetTickFunctionEnable(false);
}

void ABird::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
                         int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult ){
	UE_LOG(LogTemp, Warning, TEXT("Overlapped"));
	if (!OtherComp->IsA<UBoxComponent>())
		APlayingGameState::Get().GoPostGame();
}