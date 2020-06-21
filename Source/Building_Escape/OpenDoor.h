// Copyright Matthew Barham 2020

#pragma once

#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);

private:
	AActor* ActorThatOpens;
	
	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened {0.f};

	UPROPERTY(EditAnywhere)
	float OpenAngle {90.f};

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay {0.5f};

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed {0.8f};

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed {2.f};

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate {nullptr};
};
