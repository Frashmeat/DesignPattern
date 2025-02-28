// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestPlatform.generated.h"

class UMyFacadeBase;
class UProxy;

UCLASS()
class DESIGNPATTERN_API ATestPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UProxy* Proxy;

	UMyFacadeBase* MyFacade;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
