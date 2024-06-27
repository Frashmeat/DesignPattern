// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectBase.h"
#include "FactoryActor.generated.h"

UCLASS()
class UFactoryObject : public UObject
{
	GENERATED_BODY()

public:
	static UProjectBase * CreateProject(UObject* Outer,TSubclassOf<UProjectBase> ProjectClass)
	{
		return NewObject<UProjectBase>(Outer, ProjectClass);
	}
};



UCLASS()
class DESIGNPATTERN_API AFactoryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFactoryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
