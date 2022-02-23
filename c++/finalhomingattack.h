// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "finalhomingattack.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class COURSEWORK302_API Afinalhomingattack : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Afinalhomingattack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//VARIABLES
	UPROPERTY(EditAnywhere, BlueprintReadWrite)bool Cjumped = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)bool Cdashed = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)bool Chit = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)AActor* CTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)TArray<TEnumAsByte<EObjectTypeQuery>> CHomingTarget; 

	//FUNCTIONS
	UFUNCTION(BlueprintCallable)void Ccollisioncheck();
	UFUNCTION(BlueprintCallable)void Chomingattack();
	UFUNCTION(BlueprintCallable)void CDash();
	UFUNCTION(BlueprintCallable)void CDashcheck();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
