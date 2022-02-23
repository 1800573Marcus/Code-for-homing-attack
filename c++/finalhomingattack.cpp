// Fill out your copyright notice in the Description page of Project Settings.


#include "finalhomingattack.h"

// Sets default values
Afinalhomingattack::Afinalhomingattack()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CHomingTarget.Add(ObjectTypeQuery7);//SET CHOMINGTARGET TO HOMING TARGET
}

// Called when the game starts or when spawned
void Afinalhomingattack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Afinalhomingattack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Afinalhomingattack::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void Afinalhomingattack::Ccollisioncheck(){
	CTarget->Destroy();//DESTROY COLLIDED OBJECT
	Cdashed = false;
	Chit = true;
	FVector LaunchVelocity = FVector(0.0f, 0.0f, 800.0f);//BOUNCE OFF ENEMY
	LaunchCharacter(LaunchVelocity,true,true);
}

void Afinalhomingattack::Chomingattack() {
	
	FVector LaunchVelocity = (CTarget->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	LaunchVelocity = LaunchVelocity*500;
	LaunchCharacter(LaunchVelocity, false, false);//LAUNCH PLAYER TOWARDS THE HOMING TARGET
}
void Afinalhomingattack::CDash() {

	FVector LaunchVelocity = GetActorForwardVector()*500;
	LaunchCharacter(LaunchVelocity, false, false);//LAUNCH CHARACTER IN DIRECTION THEY ARE ALREADY FACING
}
void Afinalhomingattack::CDashcheck() {
	if (Cjumped == true) {
		FVector start = GetActorLocation();//GET PLAYER POSITION
		start = start + FVector(0, 0, -400);//CHANGE TO JUST BELOW PLAYER
		 TArray<AActor*> none;
		 FHitResult OutHit(ForceInit);//GENERATE SPHERE JUST BELOW PLAY
		bool targethit = UKismetSystemLibrary::SphereTraceSingleForObjects(this, start, start, 500, CHomingTarget, false, none, EDrawDebugTrace::ForOneFrame, OutHit, true);//CHECK SPHERE FOR HOMING TARGETS 
		if (targethit == true) {
			CTarget = OutHit.Actor.Get();//IF HOMING TARGET FOUND SET CTARGET TO HOMING TARGET
		}
		else {
			CTarget = NULL;//IF NOTHING FOUND BY SPHERE RTACE SET TO NULL
		}

	};

}