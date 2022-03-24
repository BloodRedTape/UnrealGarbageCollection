#include "Bird.h"

ABird::ABird(){
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = Root = CreateDefaultSubobject<USceneComponent>(TEXT("MeshComponent"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bird's Mesh"));
	Mesh->AttachTo(RootComponent);
}

void ABird::BeginPlay(){
	Super::BeginPlay();
	
}

void ABird::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	Velocity += Gravity * DeltaTime;

	FVector Location = GetActorLocation();
	Location.Z += Velocity;
	SetActorLocation(Location);
}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ABird::OnJump);
}

void ABird::AddForce(float Force){
	Velocity += Force / Mass;
}

void ABird::OnJump(){
	Velocity *= 0.5;
	AddForce(JumpForce);
}