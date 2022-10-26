// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultEnemyCharacter.h"
#include "DefaultAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

ADefaultEnemyCharacter::ADefaultEnemyCharacter()
	:
MaxWalkSpeed(250)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ADefaultAIController::StaticClass();
	TimeSystemCharacter = CreateDefaultSubobject<UTimeSystemCharacterComponent>(TEXT("TimeSystemCharacter"));

	DefaultSound = CreateDefaultSubobject<UAudioComponent>(TEXT("DefaultSound"));
	DefaultSound->SetupAttachment(GetRootComponent());

	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), TargetPoints);

}

// Called when the game starts or when spawned
void ADefaultEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
	
	DefaultSound->Stop();
	/*DefaultSound->Play();*/
}

// Called every frame
void ADefaultEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADefaultEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADefaultEnemyCharacter::LaunchAttack()
{
	FHitResult* Hit = new FHitResult();
	FVector Start = GetActorLocation() + UKismetMathLibrary::GetForwardVector(GetActorRotation()) * 40;
	FVector End = UKismetMathLibrary::GetForwardVector(GetRootComponent()->GetComponentRotation()) * AttackLength + Start;
	bool Success = GetWorld()->LineTraceSingleByChannel(*Hit, Start, End, ECC_Pawn);
	if (Success)
	{
		AActor* ActorHited = Cast<AActor>(Hit->Actor);
		UGameplayStatics::ApplyDamage(ActorHited, AttackDamage, GetController(), this, UDamageType::StaticClass());
	}
}

