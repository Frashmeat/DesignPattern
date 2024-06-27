// Fill out your copyright notice in the Description page of Project Settings.


#include "CreationalPattern/FactoryMethod/FactoryMethodActor.h"

// Sets default values
AFactoryMethodActor::AFactoryMethodActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFactoryMethodActor::BeginPlay()
{
	Super::BeginPlay();
	FactoryMethodA = NewObject<UFactoryMethodA>();
	FactoryMethodA->CreateProduction(this)->ProductionFunc();
	FactoryMethodB = NewObject<UFactoryMethodB>();
	FactoryMethodB->CreateProduction(this)->ProductionFunc();
}

// Called every frame
void AFactoryMethodActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

