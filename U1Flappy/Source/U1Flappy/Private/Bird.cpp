#include "Bird.h"

ABird::ABird(){
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = Root = CreateDefaultSubobject<USceneComponent>(TEXT("MeshComponent"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bird's Mesh"));
	Mesh->AttachTo(RootComponent);
}

void ABird::BeginPlay(){
	Super::BeginPlay();
	Mesh->OnComponentBeginOverlap.AddDynamic( this, &ABird::OnOverlapBegin);
}

void ABird::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

	Velocity += Gravity * DeltaTime;

	Velocity = Velocity * bPhysicsEnabled;

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
	bPhysicsEnabled = true;
	
	Velocity *= 0.5;
	AddForce(JumpForce);
}

void ABird::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
                         int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult ){
	UE_LOG(LogTemp, Warning, TEXT("Overlapped"));
}