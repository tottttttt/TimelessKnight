#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Vector.h"
#include "Components/CapsuleComponent.h"
#include "TimeSystemCharacterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STIMELESSKNIGHT_API UTimeSystemCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTimeSystemCharacterComponent();

protected:
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere)
		int TimeRes;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void StartRevers();

	UFUNCTION(BlueprintCallable)
		void StopRevers();

	void Pop();

	void Push();

	bool Fully();

	bool Empty();

private:

	bool IsReverse;
	int CurrentPosition;
	int ActiveElem;

	TArray<FTransform>* TransformBuffer;
	TArray<FTransform>* PhysicsBuffer;
		
};