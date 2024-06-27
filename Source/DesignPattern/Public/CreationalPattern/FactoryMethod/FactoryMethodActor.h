// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProductionBase.h"
#include "GameFramework/Actor.h"
#include "FactoryMethodActor.generated.h"

UCLASS()
class UFactoryMethodBase : public UObject
{
	GENERATED_BODY()

public:
	virtual UProductionBase* CreateProduction(UObject* Outer)
	{
		return nullptr;
	}
};

UCLASS()
class UFactoryMethodA : public UFactoryMethodBase
{
	GENERATED_BODY()

public:

	virtual UProductionBase* CreateProduction(UObject* Outer) override
	{
		return NewObject<UProductionBase>(Outer, UProductionA::StaticClass());
	}

};


UCLASS()
class UFactoryMethodB : public UFactoryMethodBase
{
	GENERATED_BODY()

public:

	virtual UProductionBase* CreateProduction(UObject* Outer) override
	{
		return NewObject<UProductionBase>(Outer, UProductionB::StaticClass());
	}

};


UCLASS()
class DESIGNPATTERN_API AFactoryMethodActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFactoryMethodActor();
	UPROPERTY()
	UFactoryMethodA* FactoryMethodA;
	UPROPERTY()
	UFactoryMethodB* FactoryMethodB;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
