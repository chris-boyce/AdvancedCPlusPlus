// Chris Boyce 1908671 - Advanced C++ Module 


#include "Target.h"

#include "TargetRangePlayerState.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::ApplyDamage_Implementation(float DamageAmount)
{
	IIDamageable::ApplyDamage_Implementation(DamageAmount);
	UE_LOG(LogTemp, Warning, TEXT("%s took %f damage!"), *GetName(), DamageAmount);
	ATargetRangePlayerState* MyPlayerState = static_cast<ATargetRangePlayerState*>(GetWorld()->GetFirstPlayerController()->PlayerState);
	if(MyPlayerState)
	{
		MyPlayerState->RangeScore += 1000;
	}
	Destroy();
}

