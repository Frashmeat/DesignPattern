// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProductionBase.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API UProductionBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void ProductionFunc()
	{
		UE_LOG(LogTemp, Warning, TEXT("You should overwrite this"));
	};
};

UCLASS()
class UProductionA : public UProductionBase
{
	GENERATED_BODY()

public:
	virtual void ProductionFunc() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Production : A "));
	}
};


UCLASS()
class UProductionB : public UProductionBase
{
	GENERATED_BODY()

public:
	virtual void ProductionFunc() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Production : B"));
	}
};


