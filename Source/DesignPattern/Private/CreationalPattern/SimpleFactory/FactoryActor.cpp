// Fill out your copyright notice in the Description page of Project Settings.


#include "CreationalPattern/SimpleFactory/FactoryActor.h"

// Sets default values
AFactoryActor::AFactoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFactoryActor::BeginPlay()
{
	Super::BeginPlay();
	UProjectBase* ProjectA = UFactoryObject::CreateProject(this, UProjectA::StaticClass());
	ProjectA->ProjectFunction();

	UProjectBase* ProjectB = UFactoryObject::CreateProject(this, UProjectB::StaticClass());
	ProjectB->ProjectFunction();
	
}

// Called every frame
void AFactoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

